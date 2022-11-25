#include "abb.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_abb{
	int dato;
	abb iz;
	abb de;
}

abb crear(){
// Crea un arbol binario de busqueda vacio
	return NULL;
}

abb insertar(int x, abb ab){
//Inserta x en el arbol binario de busqueda
	if(ab == NULL){
		ab = new(nodo_abb);
		ab->dato = x;
		ab->iz = NULL;
		ab->de = NULL;
	}else if(x > ab->dato){
		ab->de = insertar(x, ab->de);
	}else{
		ab->iz = insertar(x, ab->iz);
	}
	return ab;
}

abb eliminar(int x, abb ab){
// Elimina x en el arbol binario de busqueda
	if(ab == NULL)
		return ab;
	else if(ab->dato != x){ //Si no es el dato, itero
		
		if(x > ab->dato){
			//Si x es mayor que el dato, busca a la derecha
			ab->iz = eliminar(x, ab->der);
			return ab;
		}else
			//Si x es menor que el dato, busca a la izquierda
			ab->de = eliminar(x, ab->iz);
			return ab;
		}
		
	}else{ //Estoy en el dato
		abb aux;
		if((ab->iz == NULL) && (ab->de == NULL)){
			//El nodo en el que está el dato es hoja, no tiene hijos
			delete ab;
			return ab;
		}else if(ab->iz == NULL){
			aux = ab->de;
			delete ab;
			return aux;
		}else if(ab->de == NULL){
			aux = ab->iz;
			delete ab;
			return aux;
		}
	}

}

int raiz(abb ab){
//Retorna la raiz del arbol binario de busqueda
//Pre: ab no vacio
	return ab->dato;
}

abb subiz(abb ab){
//Retorna el subarbol izquierdo
//Pre: ab no vacio
	return ab->iz;
}

abb subde(abb ab){
//Retorna el subarbol derecho
//Pre: ab no vacio
	return ab->de; 
}

bool vacio(abb ab){
//Retorna true si ab es vacio, false en caso contrario
	return (ab == NULL);
}

int max(int a, int b){
//Retorna el maximo entre a y b
	if(a > b)
		return a;
	else 
		return b;
}

bool pertenece(int x, abb ab){
//Retorna true si x pertenece a ab, false en caso contrario
	if(ab == NULL)
		return false;
	else if(ab->dato == x)
		return true;
	else if(x > ab->dato)
		return pertenece(x, ab->der);
	else
		return pertenece(x, ab->iz);   
}

int cantidad(abb ab){
//Retorna la cantidad de elementos de ab
	if(ab == NULL)
		return 0;
	else
		return cantidad(ab->iz) + 1 + cantidad (ab->de);
}

int profundidad(abb ab){
//Retorna la profundidad de ab
	if(ab == NULL)
		return 0;
	else 
		return 1 + max(profundidad ab->iz), profundidad(ab->de));
}

abb destruir(abb ab){
//Destruye el arbol y libera la memoria asociada
	if(ab != NULL){
		destruir(ab->iz);
		destruir(ab->de);
		delete ab;
	}
	return ab;
}