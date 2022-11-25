// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Programa de Prueba Lista Doblemente Encadenada de Enteros

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "listade.h"

using namespace std;

void imprimir(listade l){
// Imprime l de principio a fin.
	if (!isEmpty(l)){
		while(!isEmpty(ant(l)))
			l = ant(l);
		while (!isEmpty(l)){
			cout << actual(l);
			if (!isEmpty(sig(l)))
				cout << " - ";
			l = sig(l);
		}
		cout << endl;
	}
}

void imprimir_inv(listade l){
// Imprime l del fin al principio.
	if (!isEmpty(l)){
		while(!isEmpty(sig(l)))
			l = sig(l);
		while (!isEmpty(l)){
			cout << actual(l);
			if (!isEmpty(ant(l)))
				cout << " - ";
			l = ant(l);
		}
		cout << endl;
	}
}

void imprimir_ant(listade l){
// Imprime los "anteriores" a l (actual).
	if (!isEmpty(l)){
		while (!isEmpty(l)){
			cout << actual(l);
			if (!isEmpty(ant(l)))
				cout << " - ";
			l = ant(l);
		}
		cout << endl;
	}
}

void imprimir_sig(listade l){
// Imprime los "siguientes" a l (actual).
	if (!isEmpty(l)){
		while (!isEmpty(l)){
			cout << actual(l);
			if (!isEmpty(sig(l)))
				cout << " - ";
			l = sig(l);
		}
		cout << endl;
	}
}

int main()
{
	bool salir = false;
	bool creado = false;
	listade l;
	int opcion;

	do{
		cout << "\n\n 1 - crear lista\n";
		cout << " 2 - cons\n";
		cout << " 3 - snoc\n";
		cout << " 4 - insOrd\n";
		cout << " 5 - first\n";
		cout << " 6 - last\n";
		cout << " 7 - actual\n";
		cout << " 8 - ant\n";
		cout << " 9 - sig\n";
		cout << "10 - vacia\n";
		cout << "11 - cant\n";
		cout << "12 - pertenece\n";
		cout << "13 - elim\n";
		cout << "14 - destruir\n";
		cout << "15 - imprimir\n";
		cout << "16 - imprimir invertido\n";
		cout << " 0 - salir\n\n";
		cout << "> ";

		cin >> opcion;

		if (opcion == 1){
			if (!creado){
				l = crear();
				creado = true;
				cout << " - lista creada.\n";
			}else
				cout << " - La lista ya está creada.\n";
		}
		else if (opcion == 2){
			if (creado){
				cout << " - Valor a ingresar: ";
				cin >> opcion;
				l = cons(l, opcion);
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 3){
			if (creado){
				cout << " - Valor a ingresar: ";
				cin >> opcion;
				l = snoc(l, opcion);
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 4){
			if (creado){
				cout << " (tenga en cuenta que l debe estar ordenada para que funcione correctamente)";
				cout << "\n - Valor a ingresar: ";
				cin >> opcion;
				l = insOrd(l, opcion);
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 5){
			if (creado)
				if (isEmpty(l))
						cout << " - La lista NO puede ser vacia.\n";
				else
					cout << " - " <<  first(l) << "\n";
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 6){
			if (creado)
				if (isEmpty(l))
						cout << " - La lista NO puede ser vacia.\n";
				else
					cout << " - " <<  last(l) << "\n";
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 7){
			if (creado)
				if (isEmpty(l))
						cout << " - La lista NO puede ser vacia.\n";
				else
					cout << " - " <<  actual(l) << "\n";
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 8){
			if (creado){
				if (isEmpty(l))
					cout << " - La lista NO puede ser vacia.\n";
				else{
					cout << "\t-> ";
					imprimir_ant(ant(l));
					cout << endl;
				}
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 9){
			if (creado){
				if (isEmpty(l))
					cout << " - La lista NO puede ser vacia.\n";
				else{
					cout << "\t-> ";
					imprimir_sig(sig(l));
					cout << endl;
				}
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 10){
			if (creado){
				if (isEmpty(l))
					cout << " - La lista es vacia.\n";
				else
					cout << " - La lista es NO vacia.\n";
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 11){
		   if (creado)
				cout << " - La lista tiene " << cant(l) << " elementos.\n";
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 12){
			if (creado){
				cout << " - Valor: ";
				cin >> opcion;
				if (pertenece(l, opcion))
					cout << " - " << opcion << " pertenece a la lista.\n";
				else
					cout << " - " << opcion << " NO pertenece a la lista.\n";
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 13){
			if (creado){
				cout << " - Valor a eliminar: ";
				cin >> opcion;
				l = elim(l, opcion);
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 14){
			if (creado){
				l = destruir(l);
				cout << " - lista destruida.\n";
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 15){
			if (creado){
				cout << "\t-> ";
				imprimir(l);
				cout << endl;
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 16){
			if (creado){
				cout << "\t-> ";
				imprimir_inv(l);
				cout << endl;
			}
			else
				cout << " - Debe crear la lista para usar el comando.\n";
		}
		else if (opcion == 0){
			salir = true;
		}
		else
			cout << " - comando incorrecto.\n";
	}while (!salir);

	cout << "\n\n\tCHAUUU!!!!\n";
	l = destruir(l);
}
