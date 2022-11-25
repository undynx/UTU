todo: main.o stack_arreglo.o
	g++ -Wall -o prog main.o stack_arreglo.o
main.o: main.c
	g++ -Wall -c main.c
stack_arreglo.o: stack.h stack_arreglo.c
	g++ -Wall -c stack_arreglo.c
clean:
	rm -f *.o
	rm -f prog

