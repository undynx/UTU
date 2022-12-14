// Estructuras de Datos y Algoritmos
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// arbol.c
// Arbol Primer Hijo, Siguiente Hermano

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include <iostream>

struct  nodo_arbol{
	int dato;
	arbol ph;
	arbol sh;
};

arbol arbol_crear (){
// Crea el arboln vacio.
	return NULL;
}

int arbol_raiz (arbol a){
// Retorna la raiz de a.
// Pre: a es no vacio.
	return a->dato;
}

arbol arbol_ph (arbol a){
// Retorna el primer hijo a.
// Pre: a es no vacio.
	return a->ph;
}

arbol arbol_sh (arbol a){
// Retorna el siguiente hermano de a.
// Pre: a es no vacio.
	return a->sh;
}

bool arbol_ins (arbol & a, char * path){
// Inserta el path en el arbol, por ejemplo si recibe "1.2.3" inserta "3" como hijo de "2" y nieto de "1"
// la rama "1.2" debe existir para insertar "3" correctamente.
// Pre: "a" creado anteriormente.
// Retorna true si inserta correctamente, false en caso contrario
	arbol aux;
	arbol iter = a;
	arbol iter_padre = NULL;
	char * pch = strtok(path, ".");
	int act;
	bool exit =false;
	bool retorno = false;
	while ((pch != NULL) && (!exit)){
		act = atoi(pch);
		pch = strtok(NULL, "."); 
		if (pch == NULL){
			aux = new(nodo_arbol);
			aux->dato = act;
			aux->ph = NULL;
			if (iter_padre == NULL){
				aux->sh = a;
				a = aux;
			}else{
				aux->sh = iter_padre->ph;
				iter_padre->ph = aux;
			}
			exit = true;
			retorno = true;
		}else{
			while ((iter != NULL) && (act != iter->dato))
				iter = iter->sh;
			if (iter == NULL)
				exit = true;
			else{
				iter_padre = iter;
				iter = iter->ph;
			}
		}
	}
	return retorno;
}

bool arbol_vacio (arbol a){
// Retorna true si a es vacio, false caso contrario.
	return (a == NULL);
}

int arbol_cantidad (arbol a){
// Retorna la cardinalidad de a.
	if (a == NULL)
		return 0;
	else
		return 1 + arbol_cantidad (a->ph) + arbol_cantidad (a->sh);
}

int maximo (int x, int y){
// Retorna el maximo de "x" e "y".
	if (x > y)
		return x;
	else
		return y;
}

int arbol_profundidad (arbol a){
// Retorna la profundidad de "a".
	if (a == NULL)
		return 0;
	else
		return maximo(1 + arbol_profundidad(a->ph), arbol_profundidad(a->sh));
}

bool arbol_pertenece (arbol a, int e){
// Retorna true si e pertenece a a.
	if (a == NULL)
		return false;
	else
		return (arbol_pertenece(a->ph, e) || arbol_pertenece(a->sh, e));
}

void arbol_imprimir_tree_aux  (arbol a, int guiones){
// Imprime el arbol tabulado
	if (a != NULL){
		for (int i=0; i< guiones; i++)
			cout << "-";
		cout << a->dato << endl;
		arbol_imprimir_tree_aux(a->ph, guiones + 1);
		arbol_imprimir_tree_aux(a->sh, guiones);
	}
}

void arbol_imprimir_tree (arbol a){
// Imprime el arbol tabulado
	arbol_imprimir_tree_aux(a, 0);
}

void arbol_imprimir_nivel (arbol a, int nivel){
// Imprime un nivel del arbol.
	if (a != NULL){
		if (nivel == 0){
			cout << a->dato << " ";
			arbol_imprimir_nivel(a->sh, nivel);
		}else{
			arbol_imprimir_nivel(a->ph, nivel -1);
			arbol_imprimir_nivel(a->sh, nivel);
		}
	}
}

void arbol_imprimir_niveles (arbol a){
// Imprime todos los niveles del arbol.
	for (int i=0; i< arbol_profundidad(a); i++){
		cout << "Nivel " << i << ": ";
		arbol_imprimir_nivel(a, i);
		cout << endl;
	}
}

void arbol_destruir (arbol & a){
// Destruye a y lo deja apuntando a NULL.
	if (a != NULL){
		arbol_destruir(a->ph);
		arbol_destruir(a->sh);
		delete a;
	}
	a = NULL;
}


