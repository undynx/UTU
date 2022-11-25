// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// hash.h
// Hash Cerrado

#ifndef HASH_H
#define HASH_H

#define HASH_SIZE 10

typedef struct nodo_bucket * hasht;

hasht hasht_crear();
// Crea el hash Vacio.

hasht hasht_insertar(hasht h, int x);
// Inserta x en h.

hasht hasht_eliminar(hasht h, int x);
// Elimina x en h.

bool hasht_pertenece (hasht h, int x);
// Retorna true si x pertenece a h.

hasht hasht_destruir(hasht h);
// Destruye h y libera la memoria asociada.

void hasht_print(hasht h);
// Imprime el hash.

#endif
