todo: main.o stack_lista.o
	g++ -Wall -o prog main.o stack_lista.o
main.o: main.c
	g++ -Wall -c main.c
stack_lista.o: stack.h stack_lista.c
	g++ -Wall -c stack_lista.c
clean:
	rm -f *.o
	rm -f prog

