#ifndef ARBOL_H
#define ARBOL_H

// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// anario.h
// Arbol Primer Hijo, Siguiente Hermano

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct  nodo_arbol * arbol;

arbol arbol_crear ();
// Crea el arboln vacio.

int arbol_raiz (arbol a);
// Retorna la raiz de a.
// Pre: a es no vacio.

arbol arbol_ph (arbol a);
// Retorna el primer hijo a.
// Pre: a es no vacio.

arbol arbol_sh (arbol a);
// Retorna el siguiente hermano de a.
// Pre: a es no vacio.

bool arbol_ins (arbol & a, char * path);
// Inserta el path en el arbol, por ejemplo si recibe "1.2.3" inserta "3" como hijo de "2" y nieto de "1"
// la rama "1.2" debe existir para insertar "3" correctamente.
// Pre: "a" creado anteriormente.
// Retorna true si inserta correctamente, false en caso contrario

bool arbol_vacio (arbol a);
// Retorna true si a es vacio, false caso contrario.

int arbol_cantidad (arbol a);
//Retorna la cantidad de a 

int maximo(int x, int y);
//Retorna el maximo de x e y

int arbol_profundidad (arbol a);
// Retorna la profundidad de a.

bool arbol_pertenece (arbol a, int e);
// Retorna true si e pertenece a a.

void arbol_imprimir_tree (arbol a);
// Imprime el arbol tabulado.

void arbol_imprimir_tree_aux (arbol a, int guiones);
// Imprime el arbol tabulado.

void arbol_imprimir_nivel (arbol a, int nivel);
// Imprime un nivel del arbol.

void arbol_imprimir_niveles (arbol a);
// Imprime todos los niveles del arbol.

void arbol_destruir (arbol & a);
// Destruye a y lo deja apuntando a NULL.

#endif
