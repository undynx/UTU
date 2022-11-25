// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - CETP
//
// main.c

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "stack.h"

#define MAX_STR 64

using namespace std;


int main()
{
	cout << "\tPrueba Stack (Implementado con Arreglos)\n";
	cout << "\t--------------------------------------\n\n";
	cout << "Comandos:\n";
	cout << "   - crear\n";
	cout << "   - push\n";
	cout << "   - top\n";
	cout << "   - pop\n";
	cout << "   - salir\n\n\n";
	char comando[MAX_STR];

	bool salir = false;
	bool creado = false;

	stack s;
	int elem;

	while (!salir)
	{
		cout << "> ";
		cin >> comando;
		if (strcmp (comando, "salir") == 0)
		{
			cout << " - CHAUUU!!!!\n\n";
			salir = true;
			s = destruir(s);
		}
		else if (strcmp (comando, "crear") == 0)
		{
			s = crear ();
			creado = true;
			cout << " - Stack creado con exito.\n\n";
		}
		else if (strcmp (comando, "push") == 0)
		{
			if (creado){
				cin >> elem;
				if (push (s, elem))
					cout << " - " << elem << " insertado con exito.\n\n";
				else
					cout << " - ERROR: Imposible insertar, el Stack esta lleno.\n\n";
			}else
				cout << " - ERROR: El Stack debe estar creado al utilizar esta funcion.\n\n";
		}
		else if (strcmp (comando, "top") == 0)
		{
			if (creado)
				if (vacio (s))
					cout << " - El Stack esta vacio.\n\n";
				else
					cout << " - Tope = " << top (s) << endl;
			else
				cout << " - ERROR: El Stack debe estar creado al utilizar esta funcion.\n\n";
		}
		else if (strcmp (comando, "pop") == 0)
		{
			if (creado){
				if (!vacio (s)){
					pop (s);
					cout << " - Tope eliminado con exito.\n\n";
				}else
					cout << " - No se puede eliminar tope pues el Stack esta vacio.\n\n";
			}
			else
				cout << " - ERROR: El Stack debe estar creado al utilizar esta funcion.\n\n";
		}
		else if (strcmp (comando, "vacio") == 0)
		{
			if (creado){
				if (vacio (s))
					cout << " - Vacio.\n\n";
				else
					cout << " - No Vacio.\n\n";
			}else
				cout << " - ERROR: El Stack debe estar creado al utilizar esta funcion.\n\n";
		}
		else
			cout << " - Comando Incorrecto.\n\n";
	}
}
