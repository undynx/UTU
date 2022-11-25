#ifndef LISTA_H
#define LISTA_H

// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// lista.h
// Lista Simple de Enteros

typedef struct nodolista * lista;


lista lista_crear();
// Crea la lista vacia.

int lista_head(lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacia.

lista lista_tail(lista l);
// Retorna el "resto" de la lista.
// Pre: l no vacia.

lista lista_ins(lista l, int n);
// Inserta n al inicio de l.

lista lista_elim(lista l, int x);
// Elimina x en l.

bool lista_vacia(lista l);
// Retorna true si l es vacia, false en caso contrario.

bool lista_pertenece(lista l, int n);
// Retorna true si n pertenece a l, false en caso contrario.

int lista_cantidad(lista l);
// Retorna la cantidad de elementos de l;

void lista_imprimir(lista l);
// Imprime l

void lista_destruir(lista & l);
// Destruye l y libera la memoria asociada.

#endif
