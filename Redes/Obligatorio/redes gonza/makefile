todo: mensajeria
mensajeria: mensajeria.o md5.o
	g++ -Wall -o mensajeria mensajeria.o md5.o
mensajeria.o: mensajeria.c
	g++ -Wall -c mensajeria.c
md5.o: md5.h md5.cpp
	g++ -Wall -c md5.cpp
limpiar: clean
clean:
	rm -f *.o
	rm -f mensajeria
