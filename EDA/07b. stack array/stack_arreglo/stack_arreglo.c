#include "stack.h"

struct nodo_stack{
	int tope;
	int * arr;
};

stack crear(){
// Crea el stack vacio.
	stack s = new(nodo_stack);
	s->tope = 0;
	s->arr = new(int[MAX_STACK]);
	return s;
}

stack push(stack s, int x){
// Inserta x en el tope de s.
// En caso de desborde no hace nada
	if (s->tope < MAX_STACK){
		s->arr[s->tope] = x;
		s->tope++;
	}
	return s;
}

int top(stack s){
// Retorna el tope de s.
// Pre: s no vacio.
	return s->arr[s->tope -1];
}

stack pop(stack s){
// Elimina el tope de s.
// Si no hay elementos no hace nada.
	s->tope--;
	return s;
}

bool vacio(stack s){
// Retorna true si s es vacio, false en caso contrario.
	return (s->tope == 0);
}

stack destruir(stack s){
// Destruye s y libera la memoria asociada.
	delete [] s->arr;
	delete s;
	return s;
}
