// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// lista.c
// Lista Simple de Enteros

#include "lista.h"
#include <stdio.h>

struct nodo_lista{
	int dato;
	lista sig;
	int cantidad;
};


lista crear(){
// Crea la lista vacia.
	return NULL;
}

lista cons(lista l, int n){
// Inserta n al inicio de l.
	lista aux = new(nodo_lista);
	aux->dato = n;
	aux->sig = l;
	l = aux;
	return l;
}

lista snoc(lista l, int n){
// Inserta n al final de l.


}

int head(lista l){
// Retorna el primer elemento de la lista.
// Pre: l no vacia.
	return l->dato;
}

lista tail(lista l){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return l->sig;
}

bool isEmpty(lista l){
// Retorna true si l es vacia, false en caso contrario.
	return (l == NULL);
}

int cant(lista l){
// Retorna la cantidad de elementos de l (recursiva).
	if (l == NULL)
		return 0;
	else
		return 1 + cant(l->sig);
}

int cant_iterativa(lista l){
// Retorna la cantidad de elementos de l (iterativa).
	int cant = 0;
	while(l != NULL){
		cant++;
		l = l->sig;
	}
	return cant;
}

bool pertenece(lista l, int n){
// Retorna true si n pertenece a l, false en caso contrario.

}




lista elim(lista l, int elem){
// En caso de que elem pertenezca a l, retorna l sin ese elemento.
}

lista destruir(lista l){
// Destruye l y libera la memoria asociada.
}
