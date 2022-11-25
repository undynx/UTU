#include "stack.h"

#include <stdio.h>


struct nodo_stack{
	int dato;
	stack sig;
};

stack crear(){
// Crea el stack vacio.
	return NULL;
}

stack push(stack s, int x){
// Inserta x en el tope de s.
	stack aux = new(nodo_stack);
	aux->dato = x;
	aux->sig = s;
	return aux;
}

int top(stack s){
// Retorna el tope de s.
// Pre: s no vacio.
	return s->dato;
}

stack pop(stack s){
// Elimina el tope de s.
// Si no hay elementos no hace nada.
	if(s != NULL){
		stack aux = s;
		s = s->sig;
		delete aux;
	}
	return s;
}

bool vacio(stack s){
// Retorna true si s es vacio, false en caso contrario.
	return (s == NULL);
}

stack destruir(stack s){
// Destruye s y libera la memoria asociada.
	if(s != NULL){
		if(s->sig == NULL)
			delete s;
		else{
			s->sig = destruir(s->sig);
			delete s;
		}
	}
	return s;
}
