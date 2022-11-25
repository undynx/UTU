todo: main.o
	g++ -Wall -o hash hash.o main.o
main.o: main.c hash.o
	g++ -Wall -c main.c
hash.o: hash.h hash.c
	g++ -c hash.c
clean:
	rm -f *.o
	rm -f hash
