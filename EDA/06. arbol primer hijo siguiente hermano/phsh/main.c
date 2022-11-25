// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Modulo de Prueba Arbol Primer Hijo, Siguiente Hermano

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "arbol.h"

#define MAX_STR 64

using namespace std;

int main()
{
	cout << "\tPrueba Árbol Primer Hijo - Siguiente Hermano\n";
	cout << "\t--------------------------------------------\n\n";
	
	cout << "Comandos:\n";
	cout << "   - crear\n";
	cout << "   - insertar version   (ej: insertar 1.2.3)\n";
	cout << "   - imprimir\n";
	cout << "   - imprimirniveles\n";
	cout << "   - imprimirnivel nivel\n";
	cout << "   - profundidad\n";
	cout << "   - pertenece elem\n";
	cout << "   - vacio\n";
	cout << "   - destruir\n";
	cout << "   - salir\n\n\n";
	char comando[MAX_STR];
	int elem;
	char path[MAX_STR];
	bool salir = false;
	bool creado = false;
	arbol a;
	
	while (!salir){
		cout << "> ";
		cin >> comando;
		if (strcmp(comando, "crear") == 0){
			a = arbol_crear();
			cout << " - Arbol creado.\n";
			creado = true;
		}
		if (strcmp(comando, "insertar") == 0){
			if (creado){
				cin >> path;
				cout << "Insertando \"" << path << "\"....\n";
				if (arbol_ins (a, path))
					cout << " - OK: Version insertada.\n";
				else
					cout << " - ERROR: Imposible insertar version \n";
			}
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "imprimir") == 0){
			if (creado)
				arbol_imprimir_tree (a);
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "imprimirniveles") == 0){
			if (creado)
				arbol_imprimir_niveles (a);
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "imprimirnivel") == 0){
			cin >> elem;
			if (creado){
				cout << " - Nivel " << elem << ": ";
				arbol_imprimir_nivel (a, elem);
				cout << endl;
			}else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}		
		if (strcmp(comando, "profundidad") == 0){
			if (creado)
				cout << " - Profundidad = " << arbol_profundidad (a) << endl;
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "pertenece") == 0){
			cin >> elem;
			if (creado){
				if (arbol_pertenece (a, elem))
					cout << " - \"" << elem << "\" pertenece al arbol\n";
				else
					cout << " - \"" << elem << "\" NO pertenece al arbol\n";
			}
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "vacio") == 0){
			if (creado){
				if (arbol_vacio (a))
					cout << " - El arbol es vacio.\n";
				else
					cout << " - El arbol NO es vacio.\n";
			}
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "destruir") == 0){
			if (creado){
				arbol_destruir (a);
				cout << " - Arbol destruido.\n";
				creado = false;
			}
			else
				cout << " - ERROR: El árbol debe estar creado al utilizar esta función.\n";
		}
		if (strcmp(comando, "salir") == 0){
			arbol_destruir (a);
			salir = true;
			cout << " - Chau!!!\n";
		}
	}
}
