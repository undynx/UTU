todo: main.o
	g++ -Wall -o hash hash.o main.o lista.o
main.o: main.c hash.o
	g++ -Wall -c main.c
hash.o: hash.h hash.c lista.o
	g++ -c hash.c
lista.o: lista.h lista.c
	g++ -c lista.c
clean:
	rm -f *.o
	rm -f hash
