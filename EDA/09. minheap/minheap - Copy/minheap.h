#ifndef MINHEAP_H
#define MINHEAP_H

// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// minheap.h
// Monticulo Binario de Minimos

#define HEAP_SIZE 25

typedef struct nodo_minheap * minheap;

minheap minheap_crear();
// Crea el Min Heap Vacio.

minheap minheap_insertar(minheap h, int x);
// Inserta x en h.
// Pre: h no esta lleno.

int minheap_minimo(minheap h);
// Retorna el valor del minimo elemento.
// Pre: h tiene elementos.

minheap minheap_quitar_minimo(minheap h);
// Retorna h sin su minimo elemento.
// Pre: h tiene elementos.

int minheap_tope(minheap h);
// Retorna la cantidad de elementos de h.

minheap minheap_destruir(minheap h);
// Destruye h y libera la memoria asociada.

void minheap_print_arreglo(minheap h);
// Imprime el heap en forma de arreglo.

void minheap_print_monticulo(minheap h);
// Imprime el heap en forma de monticulo.

#endif
