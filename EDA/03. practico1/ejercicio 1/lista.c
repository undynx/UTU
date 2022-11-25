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
};

lista crear(){
// Crea la lista vacia.
	return NULL;
}

lista cons(lista l, int n){
// Inserta n al inicio de l.
	lista nodo_nuevo = new(nodo_lista);
	nodo_nuevo->dato = n;
	nodo_nuevo->sig = l;
	l = nodo_nuevo;
	return l;
}

lista snoc(lista l, int n){
// Inserta n al final de l.

	if(l == NULL){ //si la lista es vacia
		lista nuevo_nodo = new(nodo_lista);
		nuevo_nodo->dato = n;
		nuevo_nodo->sig = NULL;
		l = nuevo_nodo;
	}else{
		l->sig = snoc(l->sig, n);
	}
	return l;
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
	if (l == NULL)
		return true;
	else
		return false;
}

bool pertenece_r(lista l, int n){
// Retorna true si n pertenece a l, false en caso contrario.
	bool presente;
	if(isEmpty(l)){
		presente = false;
	}else{
		if(head(l) == n){
			presente = true;
		}else{
			presente = pertenece(l->sig, n);
		}
	}
	
	return presente;
}

bool pertenece(lista l, int n){
// Retorna true si n pertenece a l, false en caso contrario. (iter)
	bool presente = false;
	
	while((presente == false) && (l != NULL)){
		if(l->dato == n)
			presente = true;
		else
			l = l->sig;
	}

	return presente;
}

lista elim(lista l, int elem){
// En caso de que elem pertenezca a l, retorna l sin ese elemento.

	lista ant = NULL;
	lista iter = l;
	
	if(isEmpty(l)){
		return l;
	} else {
		while(iter != NULL){
			if(iter->dato == elem){
				if(ant == NULL){
					l = l->sig;
					delete iter;
					iter = l;
				}else{
					ant->sig = iter->sig;
					delete iter;
					iter = ant->sig;
				}
			}else{
				ant = iter;
				iter = iter->sig;
			}
		}
	}
	
	return l;
}

lista destruir(lista l){
// Destruye l y libera la memoria asociada.
	if(l==NULL){
		return l;
	} else {
		l->sig = destruir(l->sig);
		delete l;
	}
	
	return l;
}


int cant(lista l){
//Retorna la cantidad de elementos que tiene l
	if(l == NULL){
		return 0;
	}else{
		return 1 + cant(l->sig);
	}

}

// PRACTICO //

int Last_rec(lista l){
// Retorna el último elemento de l.
// Pre: l no es vacía.
	
	if(l->sig == NULL){
		return l->dato;
	}else{
		l = l->sig;
	}

}

int Last(lista l){
// Retorna el último elemento de l.
// Pre: l no es vacía.

	while(l->sig != NULL){
		l = l->sig
	}
	return l->dato;
}

int Max(lista l){
// Retorna el máximo elemento de l.
// Pre: l no es vacía.
	
	max = l->dato;
	
	while(l != NULL){
		if(l->dato > max)
			max = l->dato
		l = l->sig
	}

	return max;
}

float Average(lista l){
// Retorna si la lista no es vacía el promedio de sus elementos.
// Pre: l no es vacía
	
	suma = 0;
	cant = 0;
	
	while(l != NULL){
		suma = suma + l->dato
		cant ++;
		l = l->sig;
	}
	
	return (float)suma / cant;
}

lista Insert(int x, lista l){
// Inserta ordenadamente el elemento x en la lista ordenada l
	
	lista ant = NULL;
	lista iter = l;
	
	while((iter != NULL) && (iter-> dato > x){
		ant = iter;
		iter = iter->sig;
	}
	
	lista nodo_nuevo = new(nodo_lista);
	nodo_nuevo->dato = x;
	nodo_nuevo->sig = iter;
	
	if(ant != NULL){
		ant->sig = nodo_nuevo;
	} else {
		l = nodo_nuevo;
	}
	return l;
	
}

bool Equals(lista l, lista p){
// Verifica si las listas l y p son iguales (mismos elementos en el mismo orden).
	bool iguales = true;
	
	while((iguales == true) && (l != NULL)){
	
		if(l->dato != p->dato)
			iguales = false;
		l = l->sig;
		p = p->sig;
	
	}
	
	return iguales;

}


