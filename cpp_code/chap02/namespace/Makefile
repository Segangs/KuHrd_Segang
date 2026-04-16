app.out : main.o kitae.o mike.o
	g++ main.o kitae.o mike.o -o app.out

main.o : main.cpp
	g++ -c main.cpp -o main.o

kitae.o : kitae.cpp
	g++ -c kitae.cpp -o kitae.o

mike.o : mike.cpp
	g++ -c mike.cpp -o mike.o

clean:
	rm -rf *.o app.out