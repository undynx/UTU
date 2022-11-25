todo: main.o lista.o
	g++ -Wall -o main main.o lista.o
main.o: main.c
	g++ -Wall -c main.c
lista.o: lista.c lista.h
	g++ -Wall -c lista.c
clean:
	rm -f *.o
	rm -f main
