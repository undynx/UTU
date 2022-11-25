#include "arbolb.h"

#include <stdio.h>


struct nodo_arbolb{
	int dato;
	arbolb iz;
	arbolb de;
};

arbolb crear(){
// Crea un arbol vacio.
	return NULL;
}

arbolb insertar(int x, arbolb subiz, arbolb subde){
// Inserta x como raiz, deja a subiz como sub arbol izquierdo y
// a subde como subarbol derecho.
	arbolb aux = new(nodo_arbolb);
	aux->dato = x;
	aux->iz = subiz;
	aux->de = subde;
	return aux;
}

int raiz(arbolb ab){
// Retorna la raiz del arbol.
// Pre: ab no vacio.
	return ab->dato;
}

arbolb subiz(arbolb ab){
// Retorna el subarbol izquierdo del arbol.
// Pre: ab no vacio.
	return ab->iz;
}

arbolb subde(arbolb ab){
// Retorna el subarbol derecho del arbol.
// Pre: ab no vacio.
	return ab->de;
}

bool vacio(arbolb ab){
// Retorna true si ab es vacio, false en caso contrario.
	return (ab == NULL);
}

bool pertenece(arbolb ab, int x){
// Retorna true si x pertenece ab, false en caso contrario.
	if (ab == NULL)
		return false;
	else if (ab->dato == x)
		return true;
	else
		return pertenece (ab->iz, x) || pertenece(ab->de, x);
}


int max(int a, int b){
// Retorna el maximo de a y b.
	if(a > b)
		return a;
	else
		return b;
}

int profundidad(arbolb ab){
// Retorna la profundidad del arbol.
	if (ab == NULL)
		return 0;
	else
		return 1 + max(profundidad(ab->iz), profundidad(ab->de));
}

int cantidad(arbolb ab){
// Retorna la cantidad de elementos del arbol.
	if (ab == NULL)
		return 0;
	else
		return cantidad(ab->iz) + 1 + cantidad(ab->de);

}


arbolb destruir (arbolb ab){
// Destruye el arbol y libera la memoria asociada.
	if (ab != NULL){
		ab->iz = destruir(ab->iz);
		ab->de = destruir(ab->de);
		delete ab;
	}
	return ab;
}


