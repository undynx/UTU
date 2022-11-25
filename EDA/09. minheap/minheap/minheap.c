#include "minheap.h"
#include <math.h>

#include <iostream>

using namespace std;

// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// minheap.c
// Monticulo Binario de Minimos

/*
posicion padre		hijos
n					2*n+1, 2*n+2

posicion hijo		padre
n					(n-1)/2
*/

struct nodo_minheap{
	int tope;
	int * arr;
};

minheap minheap_crear(){
// Crea el Min Heap Vacio.
	minheap h = new(nodo_minheap);
	h->tope = 0;
	h->arr = new(int[HEAP_SIZE]);
	return h;
}

minheap minheap_insertar(minheap h, int x){
// Inserta x en h.
// Pre: h no esta lleno.
	h->arr[h->tope] = x;
	int pos = h->tope;
	int swap;
	h->tope++;
	while ((pos > 0) && (h->arr[pos] < h->arr[(pos-1)/2])){
		swap = h->arr[pos];
		h->arr[pos] = h->arr[(pos-1)/2];
		h->arr[(pos-1)/2] = swap;
		pos = (pos-1)/2;
	}
	return h;
}

int minheap_minimo(minheap h){
// Retorna el valor del minimo elemento.
// Pre: h tiene elementos.
	return h->arr[0];
}

minheap minheap_quitar_minimo(minheap h){
// Retorna h sin su minimo elemento.
// Pre: h tiene elementos.
	h->tope--;
	int pos = 0;
	int swap;
	int pos_swap;
	h->arr[0] = h->arr[h->tope];
	bool intercambiar = true;
	while (intercambiar && (2*pos+1 < h->tope)){  // Mientras tenga hijos
		if (2*pos+2 < h->tope){						// Si tengo dos hijos
			if (h->arr[2*pos+1] > h->arr[2*pos+2])		// Me fijo cual es hijo de menor valor y guardo su posicion.
				pos_swap = 2*pos+2;
			else
				pos_swap = 2*pos+1;
		}else										// Si tengo un hijo
			pos_swap = 2*pos+1;
		if (h->arr[pos_swap] < h->arr[pos]){		// Si es menor que mi hijo mas chico, intercambio
			swap = h->arr[pos];
			h->arr[pos] = h->arr[pos_swap];
			h->arr[pos_swap] = swap;
			pos = pos_swap;							// Me posiciono donde estaba mi hijo
		}else
			intercambiar = false;
	}
	return h;
}

int minheap_tope(minheap h){
// Retorna la cantidad de elementos de h.
	return h->tope;
}

minheap minheap_destruir(minheap h){
// Destruye h y libera la memoria asociada.
	delete [] h->arr;
	delete h;
	return h;
}

void minheap_print_arreglo(minheap h){
// Imprime el heap en forma de arreglo.
	int i = 0;
	while (i < h->tope){
		cout << h->arr[i];
		i++;
		if (i < h->tope)
			cout << " - ";
	}
	cout << endl;
}

void minheap_print_monticulo(minheap h){
// Imprime el heap en forma de monticulo.
	bool primero;
	for (int i = 0;  (int)pow(2, i) <= h->tope; i++){
		primero = true;
		for (int j = (int)pow(2, i)-1; j < 2*(int)pow(2, i) - 1; j++){
			if (j < h->tope){
					if (primero){
						cout << h->arr[j];
						primero = false;
					}else
						cout << " - " << h->arr[j];
			}
		}
		cout << endl;
	}
}
