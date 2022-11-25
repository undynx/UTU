todo: main.o listade.o
	g++ -Wall -o main main.o listade.o
main.o: main.c
	g++ -Wall -c main.c
listade.o: listade.c listade.h
	g++ -Wall -c listade.c
clean:
	rm -f *.o
	rm -f main
