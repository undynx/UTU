// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Modulo de Prueba  Min Heap (Monticulo Binario de Minimos)

#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#define MAX_COMANDO 25

using namespace std;

int main (){
	bool salir = false;
	int valor;
	char comando[MAX_COMANDO];
	minheap h;
	do{
		cout << "\t- crear\n";
		cout << "\t- insertar\n";
		cout << "\t- minimo\n";
		cout << "\t- quitar_minimo\n";
		cout << "\t- tope\n";
		cout << "\t- destruir\n";
		cout << "\t- imprimir1\t(imprime en forma de arreglo)\n";
		cout << "\t- imprimir2\t(imprime en forma de monticulo)\n";
		cout << "\t- salir\n\n";
		cout << ">";
		cin >> comando;

		if (strcmp(comando, "crear") == 0){
			h = minheap_crear();
			cout << " - Min Heap Creado.\n\n";
		}
		if (strcmp(comando, "insertar") == 0){
			cin >> valor;
			h = minheap_insertar(h, valor);
			cout << " - Valor Insertado.\n\n";
		}
		if (strcmp(comando, "minimo") == 0){
			cout << "El minimo es " << minheap_minimo(h) << endl << endl;
		}
		if (strcmp(comando, "quitar_minimo") == 0){
			h = minheap_quitar_minimo(h);
			cout << " - Minimo Eliminado.\n\n";
		}
		if (strcmp(comando, "tope") == 0){
	cout << " - El heap tiene " << minheap_tope(h) << " elementos\n\n";
		}
		if (strcmp(comando, "destruir") == 0){
			h = minheap_destruir(h);			
			cout << " - Min Heap Destruido.\n\n";
		}
		if (strcmp(comando, "imprimir1") == 0){
			minheap_print_arreglo(h);			
		}
		if (strcmp(comando, "imprimir2") == 0){
			minheap_print_monticulo(h);			
		}
		if (strcmp(comando, "salir") == 0){
			salir = true;
		}
	}while (!salir);
	cout << "\nCHAUUUUU!!!!!!!!!!!!!\n";


}


