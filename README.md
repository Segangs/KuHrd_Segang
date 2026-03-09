<img src="https://capsule-render.vercel.app/api?type=waving&height=200&text=Segang&fontAlign=80&fontAlignY=40&color=gradient" />

고려대 개발자 양성과정에서 쓰이는 저장소이다.

## 2026.03.09.
- 포트폴리오, Github(특히 개인포트폴리오) 준비
- https://docs.google.com/presentation/d/1igQGshYUiAKx2f91brdvskaBBEhlvog_YM9Dt9nse1I/edit?slide=id.g3ce03867d15_12_0#slide=id.g3ce03867d15_12_0
- 깃허브 : https://github.com/Segangs/KuHrd_Segang
- 강사님 : https://github.com/freshmea

- Git 설치
- vs code Ctrl+` ->  git clone https://github.com/Segangs/KuHrd_Segang.git

wsl
cd ~: user 홈
ls : list
mkdir
nano test.c 에디터
cat test.c 파일내용확인

cc -o test test.c
./test

cc 설치되어있지 않을시 : sudo apt install gcc

VS CODE >  GitHub 연결
WSL 연결
WSL에 Github  연결 
segang@DESKTOP-35648T9:~$ git clone https://github.com/Segangs/KuHrd_Segang.git .

VS CODE 툴 공부
GitHub 공부 : https://sseozytank.tistory.com/41
우분투 : 

 예습과 복습

260309 make, 연산자 위주로 예습

상수constant : 리터럴 문자열 상수, 일반상수 
변수 variable : 메모리 공간 이용


cmake project <<  cc명령어가 나중에 길어짐 +라이브러리 +분할 컴파일 (유지보수 쉬움) +링킹 
cc대신 cmake유틸리티 사용 : make파일로 관리
cmakelists.txt 파일 관리용 파일, 잘 작성해야 함. make파일로 할지 ninja로 할지.
ninja 유틸리티도 있음 실전에서 ninja를 더 많이 사용 (속도 빠름, 가독성 떨어짐, 사용 불편. 하지만 cmake에서 ninja로 만들면 됨)

---