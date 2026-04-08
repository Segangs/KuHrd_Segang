app.out : main.o a.o b.o
	gcc main.o a.o b.o -o app.out

main.o : main.c
	gcc -c main.c -o main.o

a.o : a.c
	gcc -c a.c -o a.o

b.o : b.c
	gcc -c b.c -o b.o

clean:
	rm -rf *.o app.outmake 