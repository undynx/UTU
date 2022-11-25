todo: main.o abb.o
	g++ -Wall -o main main.o abb.o
main.o: main.c
	g++ -Wall -c main.c
abb.o: abb.h abb.c
	g++ -Wall -c abb.c
limpiar:
	rm -f *.o
	rm -f main

