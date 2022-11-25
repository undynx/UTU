#ifndef QUEUE_H
#define QUEUE_H

typedef struct nodo_queue * queue;

queue crear();
// Crea un queue vacio.

queue enqueue(queue q, int x);
// Inserta x al final de q.

int primero(queue q);
// Retorna el primer elemento de q.
// Pre: q no vacia.

int ultimo(queue q);
// Retorna el ultimo elemento de q.
// Pre: q no vacia.

queue dequeue(queue q);
// Elimina el primer elemento de q.
// Si no hay elementos no hace nada.

bool vacio(queue q);
// Retorna true si q es vacio, false en caso contrario.

queue destruir(queue q);
// Destruye q y libera la memoria asociada.

#endif


