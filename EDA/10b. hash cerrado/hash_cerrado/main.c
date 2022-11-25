// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Modulo de prueba Hash Cerrado

#include "hash.h"
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
	hasht h;
	do{
		cout << "\t- crear\n";
		cout << "\t- insertar\n";
		cout << "\t- eliminar\n";
		cout << "\t- pertenece\n";
		cout << "\t- destruir\n";
		cout << "\t- imprimir\n";
		cout << "\t- salir\n\n";
		cout << ">";
		cin >> comando;

		if (strcmp(comando, "crear") == 0){
			h = hasht_crear();
			cout << " - Hash Creado.\n\n";
		}
		if (strcmp(comando, "insertar") == 0){
			cin >> valor;
			h = hasht_insertar(h, valor);
			cout << " - Valor Insertado.\n\n";
		}
		if (strcmp(comando, "eliminar") == 0){
			cin >> valor;
			h = hasht_eliminar(h, valor);
			cout << " - Valor Eliminado.\n\n";
		}
		if (strcmp(comando, "pertenece") == 0){
			cin >> valor;
			if (hasht_pertenece (h, valor))
				cout << " - Pertenece\n";
			else
				cout << " - NO Pertenece\n";
		}
		if (strcmp(comando, "destruir") == 0){
			h = hasht_destruir(h);			
			cout << " - Hash Destruido.\n\n";
		}
		if (strcmp(comando, "imprimir") == 0){
			hasht_print(h);			
		}
		if (strcmp(comando, "salir") == 0){
			salir = true;
		}
	}while (!salir);
	cout << "\nCHAUUUUU!!!!!!!!!!!!!\n";

}


