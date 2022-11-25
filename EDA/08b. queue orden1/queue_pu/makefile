todo: main.o queue.o
	g++ -Wall -o prog main.o queue.o
main.o: main.c
	g++ -Wall -c main.c
queue.o: queue.h queue.c
	g++ -Wall -c queue.c
clean:
	rm -f *.o
	rm -f prog

