// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// hash.c
// Hash Cerrado

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

struct nodo_bucket{
	int dato;
	bool vacio;
	bool usado;
};

int hashf (int elem){
	return elem%HASH_SIZE;
}

hasht hasht_crear(){
	hasht aux = new(nodo_bucket[HASH_SIZE]);
	for (int i = 0; i < HASH_SIZE; i++){
		aux[i].vacio = true;
		aux[i].usado = false;
	}
	return aux;
}

hasht hasht_insertar(hasht h, int x){
	int pos = hashf (x);
	int pos_inicial = pos;
	bool salir = false;

	while (!salir && !h[pos].vacio){
		pos++;
		if (pos == HASH_SIZE)
			pos = 0;
		if (pos_inicial == pos)
			salir = true;
	}
	if (!salir){
		h[pos].vacio = false;
		h[pos].usado = true;
		h[pos].dato = x;
	}
	return h;
}

hasht hasht_eliminar(hasht h, int x){
	int pos = hashf (x);
	int pos_inicial = pos;
	bool salir = false;

	while (!salir && h[pos].usado){
		if (!h[pos].vacio && (h[pos].dato == x)){
			h[pos].vacio = true;
			salir = true;
		}else{
			pos++;
			if (pos == HASH_SIZE)
				pos = 0;
			if (pos_inicial == pos)
				salir = true;
		}
	}
	return h;
}

bool hasht_pertenece (hasht h, int x){
	int pos = hashf (x);
	int pos_inicial = pos;
	bool salir = false;
	bool retorno = false;

	while (!salir && h[pos].usado){
		//cout << "pos " << pos << endl; 
		if (!h[pos].vacio && (h[pos].dato == x)){
			retorno = true;
			salir = true;
		}else{
			pos++;
			if (pos == HASH_SIZE)
				pos = 0;
			if (pos_inicial == pos)
				salir = true;
		}
	}
	return retorno;
}

hasht hasht_destruir(hasht h){
	delete [] h;
	return h;
}

void hasht_print(hasht h){
	for (int i = 0; i < HASH_SIZE; i++){
		cout << "[" << i << "] ->";
		if (!h[i].vacio)
			cout << h[i].dato << "\t";
		else
			cout << " vacio \t";
		if (h[i].usado)
			cout << "usado\n";
		else
			cout << "nuevo\n";
	}
	cout << endl;
}

