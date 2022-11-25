#ifndef ARBOLB_H
#define ARBOLB_H

typedef struct nodo_arbolb * arbolb;

arbolb crear();
// Crea un arbol vacio.

arbolb insertar(int x, arbolb subiz, arbolb subde);
// Inserta x como raiz, deja a subiz como sub arbol izquierdo y
// a subde como subarbol derecho.

int raiz(arbolb ab);
// Retorna la raiz del arbol.
// Pre: ab no vacio.

arbolb subiz(arbolb ab);
// Retorna el subarbol izquierdo del arbol.
// Pre: ab no vacio.

arbolb subde(arbolb ab);
// Retorna el subarbol izquierdo del arbol.
// Pre: ab no vacio.

bool vacio(arbolb ab);
// Retorna true si ab es vacio, false en caso contrario.

bool pertenece(arbolb ab, int x);
// Retorna true si x pertenece ab, false en caso contrario.

int profundidad(arbolb ab);
// Retorna la profundidad del arbol.

int cantidad(arbolb ab);
// Retorna la cantidad de elementos del arbol.

arbolb destruir (arbolb ab);
// Destruye el arbol y libera la memoria asociada.

#endif
