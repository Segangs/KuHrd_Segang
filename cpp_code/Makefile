app.out : main.o a.o b.o
	gcc main.o a.o b.o -o app.out

main.o : main.c
	gcc -c main.c -o main.o

kitae.o : kitae.c
	gcc -c kitae.c -o kitae.o

mike.o : mike.c
	gcc -c mike.c -o mike.o

clean:
	rm -rf *.o app.outmake 