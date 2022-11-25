#ifndef LISTA_H
#define LISTA_H

// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// lista.h
// Lista Simple de Enteros

typedef struct nodo_lista * lista;

lista crear();
// Crea la lista vacia.

lista cons(lista l, int n);
// Inserta n al inicio de l.

lista snoc(lista l, int n);
// Inserta n al final de l.

int head(lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacia.

lista tail(lista l);
// Retorna el "resto" de la lista.
// Pre: l no vacia.

bool isEmpty(lista l);
// Retorna true si l es vacia, false en caso contrario.

int cant(lista l);
// Retorna la cantidad de elementos de l.

bool pertenece(lista l, int n);
// Retorna true si n pertenece a l, false en caso contrario.

lista elim(lista l, int elem);
// En caso de que elem pertenezca a l, retorna l sin ese elemento.

lista destruir(lista l);
// Destruye l y libera la memoria asociada.

#endif

