// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "queue.h"

#define MAX_STR 64

using namespace std;


int main()
{
	cout << "\tPrueba Queue\n";
	cout << "\t------------\n\n";
	cout << "Comandos:\n";
	cout << "   - crear\n";
	cout << "   - enqueue\n";
	cout << "   - primero\n";
	cout << "   - ultimo\n";
	cout << "   - dequeue\n";
	cout << "   - salir\n\n\n";
	char comando[MAX_STR];

	bool salir = false;
	bool creado = false;

	queue q;
	int elem;

	while (!salir)
	{
		cout << "> ";
		cin >> comando;
		if (strcmp (comando, "salir") == 0)
		{
			cout << " - CHAUUU!!!!\n\n";
			salir = true;
		}
		else if (strcmp (comando, "crear") == 0)
		{
			q = crear ();
			creado = true;
			cout << " - Queue creada con exito.\n\n";
		}
		else if (strcmp (comando, "enqueue") == 0)
		{
			if (creado){
				cin >> elem;
				q = enqueue(q, elem);
				cout << " - " << elem << " insertado con exito.\n\n";
			}else
				cout << " - ERROR: La Queue debe estar creada al utilizar esta funcion.\n\n";
		}
		else if (strcmp (comando, "primero") == 0)
		{
			if (creado)
				if (vacio (q))
					cout << " - La Queue esta vacia.\n\n";
				else
					cout << " - Primero = " << primero (q) << endl;
			else
				cout << " - ERROR: La Queue debe estar creada al utilizar esta funcion.\n\n";
		}
		else if (strcmp (comando, "ultimo") == 0)
		{
			if (creado)
				if (vacio (q))
					cout << " - La Queue esta vacia.\n\n";
				else
					cout << " - Ultimo = " << ultimo (q) << endl;
			else
				cout << " - ERROR: La Queue debe estar creada al utilizar esta funcion.\n\n";
		}

		else if (strcmp (comando, "dequeue") == 0)
		{
			if (creado){
				if (!vacio (q)){
					q = dequeue (q);
					cout << " - Primero desencolado con exito.\n\n";
				}else
					cout << " - No se puede desencolar el primero porque la Queue esta vacia.\n\n";
			}
			else
				cout << " - ERROR: La Queue debe estar creada al utilizar esta funcion.\n\n";
		}
		else if (strcmp (comando, "vacio") == 0)
		{
			if (creado){
				if (vacio (q))
					cout << " - Vacio.\n\n";
				else
					cout << " - No Vacio.\n\n";
			}else
				cout << " - ERROR: La Queue debe estar creada al utilizar esta funcion.\n\n";
		}
		else
			cout << " - Comando Incorrecto.\n\n";
	}
}

