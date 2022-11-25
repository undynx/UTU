// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// hash.c
// Hash Abierto

#include "hash.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

struct nodo_bucket{
	lista l;
};

int hashf (int elem){
	return elem%HASH_SIZE;
}

hasht hasht_crear(){
	hasht aux = new(nodo_bucket[HASH_SIZE]);
	for(int i = 0; i < HASH_SIZE ; i++){
		aux[i].l = lista_crear();
	}
}

hasht hasht_insertar(hasht h, int x){
	int pos = hashf(x);
	h[pos].l = lisa_ins(h[pos].l, x);
	return h;
}

hasht hasht_eliminar(hasht h, int x){
	int pos = hashf(x);
	h[pos].l = lista_elim(h[pos].l, x);
	return h;
}

bool hasht_pertenece (hasht h, int x){
	int pos = hashf(x);
	h[pos].l = lista_pertenece(h[pos].l, x);
	return h;
}

hasht hasht_destruir(hasht h){
	for(int i = 0; i < HASH_SIZE; i++){
		lista_destruir(h[i].l);
	}
	delete h;
}

void hasht_print(hasht h){
	for (int i = 0; i < HASH_SIZE; i++){
		cout << "[" << i << "] ->";
		lista_imprimir(h[i].l);
		cout << endl;
	}
}

