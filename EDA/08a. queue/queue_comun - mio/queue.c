#include "queue.h"

#include <stdio.h>

struct nodo_queue{
	int dato;
	queue sig;
};

queue crear(){
// Crea un queue vacio.
	return NULL;
}

queue enqueue(queue q, int x){   // Version Iterativa
// Inserta x al final de q. O(n).
	queue aux = new(nodo_queue);
	aux->dato = x;
	aux->sig = NULL;
	queue iter = q;
	
	while(iter->sig != NULL){
		iter = iter->sig;
	}
	
	iter->sig = aux;
	
	return q;
}


queue enqueue(queue q, int x){   // Version Recursiva
// Inserta x al final de q. O(n)
	if(q == NULL){
		q = new(nodo_queue);
		q->dato = x;
		q->sig = NULL;
		return q;
	}else{
		q->sig = enqueue(q->sig, x);
		return q;
	}
}


int primero(queue q){
// Retorna el primer elemento de q. O(1).
// Pre: q no vacia.
	return q->dato;
}

int ultimo(queue q){   // Version Iterativa
// Retorna el ultimo elemento de q. O(n).
// Pre: q no vacia.
	while(q->sig != NULL)
		q = q->sig;
	return q->dato;
}


int ultimo(queue q){   // Version Recursiva
// Retorna el ultimo elemento de q. O(n)
// Pre: q no vacia.
	if(q->sig == NULL)
		return q->dato;
	else
		return ultimo(q->sig);
}
	



queue dequeue(queue q){
// Elimina el primer elemento de q. O(1).
// Si no hay elementos no hace nada.
	if(q != NULL){
		queue aux = q;
		q = q->sig;
		delete aux;
	}
	return q;
}

bool vacio(queue q){
// Retorna true si q es vacio, false en caso contrario.
	return(q == NULL);
}

queue destruir(queue q){
// Destruye q y libera la memoria asociada. O(n).
	if(q != NULL){
		if(q->sig == NULL)
			delete q;
		else{
			q->sig == destruir(q->sig);
			delete q;
		}
	}
	return q;
}

