# TARGET = hello limit literal charNumber

# ${TARGET} : ${TARGET}.c
#	cc -o ${TARGET} ${TARGET}.c

# clean : 
#	rm ${TARGET}


TARGET = hello charNumber oddEven

all : ${TARGET}

hello : $@
charNumber : $@ # cc명령은 사실 make에서 생략가능하다.
oddEven : $@

clean : 
	rm ${TARGET}