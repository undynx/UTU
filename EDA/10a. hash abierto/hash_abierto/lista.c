// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// lista.c
// Lista Simple de Enteros


#include "lista.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


struct nodolista{
    int dato;
    lista sig;
};

lista lista_crear(){
// Crea la lista vacia.
    return NULL;
}

int lista_head(lista l){
// Retorna el primer elemento de la lista.
// Pre: l no vacia.
    return l->dato;
}

lista lista_tail(lista l){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
    return l->sig;
}

lista lista_ins(lista l, int n){
// Inserta n al inicio de l.
    if (l == NULL){
        l = new(nodolista);
        l->dato = n;
        l->sig = NULL;
    }
    else{
        lista aux = new(nodolista);
        aux->dato = n;
        aux->sig = l;
        l = aux;        
    }
	return l;
}

lista lista_elim(lista l, int x){
// Elimina x en l.
	if (l != NULL)
		if (l->dato == x){
			lista aux = l;
			l = l->sig;
			delete aux;
			return l;
		}
		else
			l->sig = lista_elim(l->sig, x);
			return l;
}

bool lista_vacia(lista l){
// Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

int lista_cantidad_iterativa(lista l){
// Retorna la cantidad de elementos de l;
// Iterativa
    int cont = 0;
    while (l != NULL){
        cont++;
        l = l->sig;
    }
    return cont;
}

int lista_cantidad(lista l){
// Retorna la cantidad de elementos de l;
// Recursiva
    if (l == NULL)
        return 0;
    else
        return 1 + lista_cantidad(l->sig);    
}

bool lista_pertenece_iterativa(lista l, int n){
// Retorna true si n pertenece a l, false en caso contrario.
// Iterativa
    bool encontre = false;
    while ((l != NULL) && !encontre){
        if (l->dato == n)
            encontre = true;
        l = l->sig;
    }
    return encontre;
}

bool lista_pertenece(lista l, int n){
// Retorna true si n pertenece a l, false en caso contrario.
// Recursiva
    if (l==NULL)
        return false;
    else{
        if (l->dato == n)
            return true;
        else
            return lista_pertenece(l->sig, n);
    }
}


void lista_destruir_iterativa(lista & l){
// Destruye l y libera la memoria asociada.
// Iterativa
    lista aux;
    while (l != NULL){
        aux = l;
        l = l->sig;
        delete aux;
    }
}

void lista_imprimir(lista l){
// Imprime l
	if (l == NULL)
		cout << "|||";
	else{
		cout << l->dato << "->";
		lista_imprimir(l->sig);
	}
}


void lista_destruir(lista & l){
// Destruye l y libera la memoria asociada.
// Recursiva
    if (l != NULL){
        lista_destruir(l->sig);
        delete l;
    }
}
