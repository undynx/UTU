#ifndef ABB_H
#define ABB_H

typedef struct nodo_abb * abb;

abb crear();
// Crea un arbol binario de busqueda vacio.

abb insertar(int x, abb ab);
// Inserta a x en el arbol binario de busqueda.

abb eliminar(int x, abb ab);
// Elimina x en el arbol binario de busqueda.

int raiz(abb ab);
// Retorna la raiz del arbol binario de busqueda.
// Pre: ab no vacio.

abb subiz(abb ab);
// Retorna el sub arbol izquierdo.
// Pre: ab no vacio.

abb subde(abb ab);
// Retorna el sub arbol derecho.
// Pre: ab no vacio.

bool vacio(abb ab);
// Retorna true si ab es vacio, false en caso contrario.

bool pertenece(int x, abb ab);
// Retorna true si ab pertenece a ab, false en caso contrario.

int cantidad(abb ab);
// Retorna la cantidad de elementos de ab.

int profundidad(abb ab);
// Retorna la profundidad de ab.

abb destruir(abb ab);
// Destruye ab y libera la memoria asociada.


#endif
