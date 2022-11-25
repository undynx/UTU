#include "arbolb.h"

#include <stdio.h>

#include <iostream>

using namespace std;

void imprimir(arbolb a){
// Imprime el arbol "en orden"
	if (!vacio(a)){
		imprimir(subiz(a));
		cout << raiz(a) << " - ";
		imprimir(subde(a));
	}
}


void imprimir_nivel(arbolb a, int nivel, int profundidad){
// Imprime un nivel del arbol.
// Pre: la profundidad de la primer llamada debe ser 0.
// Nota: la profundidad es la cantidad de llamasdas recursivas de la funcion
//       no tiene relacion con la profundidad del arbol.
	if (!vacio(a)){
		if(profundidad < nivel){
			imprimir_nivel(subiz(a), nivel, profundidad + 1);
			imprimir_nivel(subde(a), nivel, profundidad + 1);
		}else if(profundidad == nivel)
			cout << raiz(a) << " - ";
	}
}



int main(){
	arbolb a = crear();
	arbolb aux1 = crear();
	arbolb aux2 = crear();

	aux1 = insertar(4, crear(), crear());
	aux2 = insertar(5, crear(), crear());
	
	aux1 = 	insertar(2, aux1, aux2);

	aux2 = insertar(7, crear(), crear());

	aux2 = insertar(3, crear(), aux2);

	a = insertar(1, aux1, aux2);

	imprimir(a);

	cout << endl;

	cout << "imprimir por niveles:\n";

	for (int i = 0; i <= profundidad(a); i++){
		cout << " - Nivel " << i << ": ";
		imprimir_nivel(a, i, 0);
		cout << endl;
	}

	
	return 0;

}

