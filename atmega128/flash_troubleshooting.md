# ATmega128 업로드 오류 정리

## 증상

빌드는 성공했지만 `make upload` 단계에서 `avrdude`가 USB 프로그래머에 접근하지 못하고 실패했다.

```text
[ 66%] Built target Atmega128_Project.elf
[100%] Flashing Atmega128_Project.hex to hardware...
avrdude: usb_open(): cannot read serial number "error sending control message: Operation not permitted"
avrdude: usb_open(): cannot read product name "error sending control message: Operation not permitted"
avrdude: usbdev_open(): WARNING: failed to set configuration 1: could not set config 1: Operation not permitted
avrdude: usbdev_open(): error claiming interface 0: could not claim interface 0: Operation not permitted
avrdude: usbdev_open(): no usable interface found

avrdude done.  Thank you.

make[3]: *** [CMakeFiles/upload.dir/build.make:71: CMakeFiles/upload] Error 1
make[2]: *** [CMakeFiles/Makefile2:110: CMakeFiles/upload.dir/all] Error 2
make[1]: *** [CMakeFiles/Makefile2:117: CMakeFiles/upload.dir/rule] Error 2
make: *** [Makefile:137: upload] Error 2
```

## 원인

이 문제는 빌드 실패가 아니라 USB 프로그래머 접근 권한 문제다.

- `avrdude`는 `AVRISPmkII` 장치를 찾으려 시도했지만
- `libusb`가 장치 인터페이스를 `claim`하는 단계에서 `Operation not permitted`로 실패했다
- 즉, HEX 파일이나 C 코드 문제가 아니라 OS/WSL/USB 권한 문제가 핵심이다

추가로 현재 환경에서는 아래 정황도 확인됐다.

- `lsusb` 실행 시 `unable to initialize libusb: -99`
- `/dev/bus/usb` 경로가 없음

이 상태는 Linux 쪽에 USB 장치가 정상적으로 노출되지 않았거나, 권한 설정이 빠져 있음을 시사한다.

## CMake 변경 내용

`atmega128/CMakeLists.txt`에서 업로드 관련 값을 캐시 변수로 바꿔서, 파일을 직접 수정하지 않고 설정을 바꿀 수 있게 조정했다.

기존에는 아래처럼 고정값이었다.

```cmake
set(PROG_TYPE AVRISPmkII)
set(PROG_PORT usb)
```

변경 후에는 아래처럼 `avrdude` 관련 값을 외부에서 넘길 수 있다.

```cmake
set(AVRDUDE_MCU m128 CACHE STRING "avrdude MCU id")
set(AVRDUDE_PROGRAMMER AVRISPmkII CACHE STRING "avrdude programmer id")
set(AVRDUDE_PORT usb CACHE STRING "avrdude port")
set(AVRDUDE_EXTRA_ARGS "" CACHE STRING "additional avrdude arguments")
```

업로드 타겟도 다음처럼 변경했다.

```cmake
find_program(AVRDUDE_EXECUTABLE avrdude REQUIRED)

add_custom_target(upload
    COMMAND ${AVRDUDE_EXECUTABLE}
        -p ${AVRDUDE_MCU}
        -c ${AVRDUDE_PROGRAMMER}
        -P ${AVRDUDE_PORT}
        ${AVRDUDE_EXTRA_ARGS}
        -U flash:w:${PROJECT_NAME}.hex:i
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Flashing ${PROJECT_NAME}.hex to hardware..."
    VERBATIM
)
```

## 사용 예시

이제 다음처럼 configure 할 때 옵션을 바꿔서 사용할 수 있다.

```bash
cmake -S atmega128 -B build/atmega128 \
  -DCMAKE_TOOLCHAIN_FILE=atmega128/avr-toolchain.cmake \
  -DAVRDUDE_PROGRAMMER=AVRISPmkII \
  -DAVRDUDE_PORT=usb \
  -DAVRDUDE_EXTRA_ARGS="-v"
```

## 해결 절차

### 1. WSL을 쓰는 경우 USB 장치 연결

Windows PowerShell 관리자 권한에서:

```powershell
usbipd list
usbipd bind --busid <BUSID>
usbipd attach --wsl --busid <BUSID>
```

### 2. Linux/WSL 안에서 장치 확인

```bash
lsusb
ls -l /dev/bus/usb/*/*
```

### 3. 빠른 확인용으로 sudo로 업로드 테스트

```bash
sudo avrdude -p m128 -c AVRISPmkII -P usb -U flash:w:Atmega128_Project.hex:i
```

이 명령은 임시 확인용이다. 이 상태에서 동작하면 원인은 거의 확실하게 권한 문제다.

### 4. 영구 해결: udev 규칙 추가

장치의 VID/PID를 `lsusb`로 확인한 뒤 `/etc/udev/rules.d/99-avr.rules`에 규칙을 추가한다.

예시:

```text
SUBSYSTEM=="usb", ATTR{idVendor}=="03eb", ATTR{idProduct}=="2104", MODE="0666"
```

그 다음 규칙을 다시 로드한다.

```bash
sudo udevadm control --reload-rules
sudo udevadm trigger
```

## 결론

- 현재 실패 원인은 소스 코드가 아니라 USB 권한/노출 문제다
- WSL이라면 `usbipd attach` 상태를 먼저 확인해야 한다
- 일반 Linux라면 `udev` 규칙이 빠졌을 가능성이 높다
- `sudo avrdude ...`가 동작하면 권한 이슈로 판단하면 된다

