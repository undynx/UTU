#include "abb.h"

#include <iostream>

using namespace std;


void imprimir_arbol (abb a){
// Imprime a "en orden".
	if (!vacio(a)){
		imprimir_arbol (subiz(a));
		cout << raiz(a) << " ";
		imprimir_arbol (subde(a));
	}
}

void imprimir_nivel (abb a, int nivel, int nivel_actual){
// Imprime un "nivel" de a.
// Pre: nivel_actual debe ser 0 en el primer llamado, representa la cantidad de 
// veces que la funcion fue llamada recursivamente.
	if(!vacio(a)){
		if (nivel_actual < nivel){
			imprimir_nivel (subiz(a), nivel, nivel_actual + 1);
			imprimir_nivel (subde(a), nivel, nivel_actual + 1);
		} else if (nivel_actual == nivel)
			cout << raiz(a) << " ";
	}
}

void imprimir_nivel_orden(abb a){
// Imprime primero en orden y despues por niveles el arbol binario de busqueda a.
	cout << "Imprimir \"en orden\":\n   -> ";
	imprimir_arbol (a);

	cout << "\n\nImprimir por niveles:";

	for (int i = 0; i < profundidad(a); i++){
		cout << "\n   -> nivel " << i + 1 << ": "; 
		imprimir_nivel (a, i, 0);
	}
	cout << "\n\n";
}

int main(){
	abb a = crear();

	a = insertar(23, a);
	a = insertar(4, a);
	a = insertar(30, a);
	a = insertar(3, a);
	a = insertar(8, a);
	a = insertar(24, a);
	a = insertar(32, a);
	a = insertar(33, a);
	a = insertar(6, a);
	a = insertar(5, a);
	a = insertar(7, a);

/*
	a = insertar(3, a);
	a = insertar(4, a);
	a = insertar(5, a);
	a = insertar(6, a);
	a = insertar(7, a);
	a = insertar(8, a);
	a = insertar(23, a);
	a = insertar(24, a);
	a = insertar(30, a);
	a = insertar(32, a);
	a = insertar(33, a);
*/

	imprimir_nivel_orden(a);

	cout << " -> ELIMINO 23\n";

	a = eliminar(23, a);

	imprimir_nivel_orden(a);

	return 0;
}
