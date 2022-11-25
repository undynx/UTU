// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Modulo Implementacion
// Lista Doblemente Encadenada de Enteros


#include "listade.h"
#include <stdio.h>

struct nodo_listade{
	int dato;
	listade sig;
	listade ant;
};

listade crear(){
// Crea la lista doblemente encadenada vacia.
	return NULL;
}

listade cons(listade l, int n){
// Inserta n al inicio de l.
	listade aux = new(nodo_listade);
	aux->dato = n;
	aux->ant = NULL;
	if (l == NULL){
		aux->sig = NULL;
		return aux;
	}else{
		listade iter = l;
		while (iter->ant != NULL)
			iter = iter->ant;
		iter->ant = aux;
		aux->sig = iter;
		return l;
	}
}

listade snoc(listade l, int n){
// Inserta n al final de l.
	listade aux = new(nodo_listade);
	aux->dato = n;
	aux->sig = NULL;
	if (l == NULL){
		aux->ant = NULL;
		return aux;
	}else{
		listade iter = l;
		while (iter->sig != NULL)
			iter = iter->sig;
		iter->sig = aux;
		aux->ant = iter;
		return l;
	}
}

listade insOrd(listade l, int n){
// Inserta ordenadamente en l.
// Pre: l ordenada.
	listade aux = new(nodo_listade);
	aux->dato = n;
	if (l == NULL){
		aux->ant = NULL;
		aux->sig = NULL;
		return aux;
	}else{
		listade iter = l;
		while (iter->ant != NULL)
			iter = iter->ant;
		while ((iter->sig != NULL) && (n > iter->dato))
			iter = iter->sig;
		if (n < iter->dato){
			aux->sig = iter;
			aux->ant = iter->ant;
			iter->ant = aux;
			if (aux->ant != NULL)
				aux->ant->sig = aux;
			
		}else{
			aux->sig = NULL;
			aux->ant = iter;
			iter->sig = aux;
		}
		return l;
	}
}

int first(listade l){
// Retorna el primer elemento de la lista.
// Pre: l no vacia.
	while (l->ant != NULL)
		l = l->ant;
	return l->dato;
}

int last(listade l){
// Retorna el ultimo elemento de la lista.
// Pre: l no vacia.
	if (l->sig == NULL)
		return l->dato;
	else
		return last(l->sig);
}

int actual(listade l){
// Retorna el elemento "actual" de la lista.
// Pre: l no vacia.
	return l->dato;
}

listade ant(listade l){
// Retorna los "anteriores" al nodo actual de la lista.
// Pre: l no vacia.
	return l->ant;
}

listade sig(listade l){
// Retorna los "siguientes" al nodo actual de la lista.
// Pre: l no vacia.
	return l->sig;
}

bool isEmpty(listade l){
// Retorna true si l es vacia, false en caso contrario.
	return (l == NULL);
}

int cant_ant(listade l){
// Retorna la cantidad de elementos de l.
	if (l == NULL)
		return 0;
	else
		return 1 + cant_ant(l->ant);
}

int cant_sig(listade l){
// Retorna la cantidad de elementos de l.
	if (l == NULL)
		return 0;
	else
		return 1 + cant_sig(l->sig);
}

int cant(listade l){
// Retorna la cantidad de elementos de l.
	if (l == NULL)
		return 0;
	else
		return 1 + cant_ant(l->ant) + cant_sig(l->sig);
}

bool pertenece(listade l, int n){
// Retorna true si n pertenece a l, false en caso contrario.
	if (l == NULL)
		return false;
	else{
		while (l->ant != NULL)
			l = l->ant;
		while ((l != NULL) && (l->dato != n))
			l = l->sig;
		if (l == NULL)
			return false;
		else
			return true;
	}
}

listade elim(listade l, int elem){
// En caso de que elem pertenezca a l, retorna l sin ese elemento.
	if (l == NULL){
		return l;
	}else{
		listade iter = l;
		while (iter->ant != NULL)
			iter = iter->ant;
		while (iter != NULL){
			if (iter->dato == elem){
				listade ant = iter->ant;
				listade sig = iter->sig;
				if (l == iter){
					if (ant != NULL)
						l = ant;
					else
						l = sig;
				}
				delete iter;
				iter = sig;
				if (ant != NULL)
					ant->sig = sig;
				if (sig != NULL)
					sig->ant = ant;
				
			}else{
				iter = iter->sig;
			}
		}
		return l;
	}
}

listade destruir(listade l){
// Destruye l y libera la memoria asociada.
	if (l != NULL){
		while (l->ant != NULL)
			l = l->ant;
		while (l != NULL){
			listade aux = l;
			l = l->sig;
			delete aux;
		}
	}
	return l;
}

