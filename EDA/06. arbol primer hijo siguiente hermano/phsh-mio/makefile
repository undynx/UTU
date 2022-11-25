todo: main
main: main.o arbol.o
	g++ -Wall -o prog main.o arbol.o
main.o: main.c
	g++ -Wall -c main.c
arbol.o: arbol.h arbol.c
	g++ -Wall -c arbol.c
clean:
	rm -f *.o
	rm -f prog

