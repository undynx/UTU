#ifndef LISTADE_H
#define LISTADE_H

// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// listade.h
// Modulo Definicion/Especificacion
// Lista Doblemente Encadenada de Enteros

typedef struct nodo_listade * listade;


listade crear();
// Crea la lista doblemente encadenada vacia.

listade cons(listade l, int n);
// Inserta n al inicio de l.

listade snoc(listade l, int n);
// Inserta n al final de l.

listade insOrd(listade l, int n);
// Inserta ordenadamente en l.
// Pre: l ordenada.

int first(listade l);
// Retorna el primer elemento de la lista.
// Pre: l no vacia.

int last(listade l);
// Retorna el ultimo elemento de la lista.
// Pre: l no vacia.

int actual(listade l);
// Retorna el elemento "actual" de la lista.
// Pre: l no vacia.

listade ant(listade l);
// Retorna los "anteriores" al nodo actual de la lista.
// Pre: l no vacia.

listade sig(listade l);
// Retorna los "siguientes" al nodo actual de la lista.
// Pre: l no vacia.

bool isEmpty(listade l);
// Retorna true si l es vacia, false en caso contrario.

int cant(listade l);
// Retorna la cantidad de elementos de l.

bool pertenece(listade l, int n);
// Retorna true si n pertenece a l, false en caso contrario.

listade elim(listade l, int elem);
// En caso de que elem pertenezca a l, retorna l sin ese elemento.

listade destruir(listade l);
// Destruye l y libera la memoria asociada.


#endif

