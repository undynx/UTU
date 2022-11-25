todo: main.o
	g++ -Wall -o heap minheap.o main.o	
main.o: main.c minheap.o
	g++ -Wall -c main.c
minheap.o: minheap.h minheap.c
	g++ -c minheap.c
clean:
	rm -f *.o
	rm -f heap
