#include "abb.h"

#include <stdio.h>

#include <iostream>

using namespace std;

struct nodo_abb{
	int dato;
	abb iz;
	abb de;
};

abb crear(){
// Crea un arbol binario de busqueda vacio.
	return NULL;
}

abb insertar(int x, abb ab){
// Inserta a x en el arbol binario de busqueda.
	if(abb == NULL){
		abb aux = new(nodo_abb);
		aux->dato = x;
		aux->iz = NULL;
		aux->de = NULL;
	}else if(x > ab->dato)
		ab->de = insertar(x, ab->de);
	else
		ab->iz = insertar(x, ab->iz);
	
	return ab;
		
}

abb max_iz(abb & ab){
	
}

abb min_de(abb & ab){
	
}



abb eliminar(int x, abb ab){
// Elimina x en el arbol binario de busqueda.
	
}


int raiz(abb ab){
// Retorna la raiz del arbol binario de busqueda.
// Pre: ab no vacio.
	return ab->dato;
}

abb subiz(abb ab){
// Retorna el sub arbol izquierdo.
// Pre: ab no vacio.
	return ab->iz;
}

abb subde(abb ab){
// Retorna el sub arbol derecho.
// Pre: ab no vacio.
	return ab->de;
}

bool vacio(abb ab){
// Retorna true si ab es vacio, false en caso contrario.
	return (ab == NULL);
}

bool pertenece(int x, abb ab){
// Retorna true si ab pertenece a ab, false en caso contrario.
	if(ab == NULL)
		return false;
	else{
		if(ab->dato == x)
			return true;
		else if(x < ab->dato)
			return pertenece(x, ab->iz);
		else
			return pertenece(x, ab->de);
	}
}

int max(int a, int b){
// Retorna el maximo de a y b.
	if(a > b)
		return a;
	else
		return b;
}

int profundidad(abb ab){
// Retorna la profundidad del arbol.
	if (ab == NULL)
		return 0;
	else
		return 1 + max(profundidad(ab->iz), profundidad(ab->de));

}

int cantidad(abb ab){
// Retorna la cantidad de elementos del arbol.
	if(ab == NULL)
		return 0;
	else
		return 1 + cantidad(ab->iz) + cantidad(ab->de);
}

abb destruir (abb ab){
// Destruye el arbol y libera la memoria asociada.
	if(ab != NULL){
		ab->iz = destruir(ab->iz);
		ab->de = destruir(ab->de);
		delete ab;
	}
	return ab;
}
