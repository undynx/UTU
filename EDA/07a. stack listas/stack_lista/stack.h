#ifndef STACK_H
#define STACK_H


typedef struct nodo_stack * stack;

stack crear();
// Crea el stack vacio.

stack push(stack s, int x);
// Inserta x en el tope de s.

int top(stack s);
// Retorna el tope de s.
// Pre: s no vacio.

stack pop(stack s);
// Elimina el tope de s.
// Si no hay elementos no hace nada.

bool vacio(stack s);
// Retorna true si s es vacio, false en caso contrario.

stack destruir(stack s);
// Destruye s y libera la memoria asociada.

#endif


