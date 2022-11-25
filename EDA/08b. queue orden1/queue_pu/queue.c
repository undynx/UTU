#include "queue.h"

#include <stdio.h>


typedef struct nodo_cola * cola;

struct nodo_cola{
	int dato;
	cola sig;	
};

struct nodo_queue{
	cola primero;
	cola ultimo;
};

queue crear(){
// Crea un queue vacio.
	queue q = new(nodo_queue);
	q->primero = NULL;
	q->ultimo = NULL;
	return q;
}

queue enqueue(queue q, int x){
// Inserta x al final de q.  O(1).
	cola c = new(nodo_cola);
	c->dato = x;
	c->sig = NULL;
	if ((q->primero == NULL) && (q->ultimo == NULL)){
		q->primero = c;
		q->ultimo = c;
	}else{
		q->ultimo->sig = c;
		q->ultimo = c;
	}
	return q;
}

int primero(queue q){
// Retorna el primer elemento de q.  O(1).
// Pre: q no vacia.
	return q->primero->dato;
}

int ultimo(queue q){
// Retorna el ultimo elemento de q.  O(1).
// Pre: q no vacia.
	return q->ultimo->dato;
}

queue dequeue(queue q){
// Elimina el primer elemento de q.  O(1).
// Si no hay elementos no hace nada.
	if ((q->primero != NULL) && (q->ultimo != NULL)){
		if (q->primero == q->ultimo){
			delete q->primero;
			q->primero = NULL;
			q->ultimo = NULL;
		}else{
			cola aux = q->primero;
			q->primero = q->primero->sig;
			delete aux;	
		}
	}
	return q;
}

bool vacio(queue q){
// Retorna true si q es vacio, false en caso contrario.
	return ((q->primero == NULL) && (q->ultimo == NULL));
}

cola destruir_cola(cola c){
// Destruye q y libera la memoria asociada.  O(n).
	if (c != NULL){
		if (c->sig == NULL){
			delete c;
			return c;
		}else{
			c->sig = destruir_cola(c->sig);
			delete c;
		}
	}
	return c;

}

queue destruir (queue q){
// Destruye q y libera la memoria asociada.
	q->primero = destruir_cola(q->primero);
	delete q;
	return q;
}
