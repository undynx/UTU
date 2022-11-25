#include "abb.h"

#include <stdio.h>

#include <iostream>

using namespace std;

struct nodo_abb{
	int dato;
	abb iz;
	abb de;
};

abb crear(){
// Crea un arbol binario de busqueda vacio.
	return NULL;
}

abb insertar(int x, abb ab){
// Inserta a x en el arbol binario de busqueda.
	if (ab == NULL){
		ab = new(nodo_abb);
		ab->dato =x;
		ab->iz = NULL;
		ab->de = NULL;
	}else if (x < ab->dato)
		ab->iz = insertar(x, ab->iz);
	else
		ab->de = insertar(x, ab->de);
	return ab;
}

abb max_iz(abb & ab){
	if (ab->de == NULL){
		abb aux = ab;
		ab = ab->iz;
		return aux;
	}else
		return max_iz(ab->de);
}

abb min_de(abb & ab){
	if (ab->iz == NULL){
		abb aux = ab;
		ab = ab->de;
		return aux;
		
	}else
		return min_de(ab->iz);
}



abb eliminar(int x, abb ab){
// Elimina x en el arbol binario de busqueda.
	if (ab == NULL)
		return ab;
	else if (ab->dato > x){
		ab->iz = eliminar(x, ab->iz);
		return ab;
	}else if (ab->dato < x){
		ab->de = eliminar(x, ab->de);
		return ab;
	}
	else{		// x == ab->dato
		abb aux;
		if ((ab->iz == NULL) && (ab->de == NULL)){  // es hoja
			delete ab;
			return NULL;
		}else if (ab->iz == NULL){
			aux = ab->de;
			delete ab;
			return aux;
		}else if (ab->de == NULL){
			aux = ab->iz;
			delete ab;
			return aux;
		}else{
			if (profundidad(ab->iz) > profundidad(ab->de))
				aux = max_iz(ab->iz);
			else
				aux = min_de(ab->de);
			aux->iz = ab->iz;
			aux->de = ab->de;
			delete ab;
			return aux;
		}
	}
}


int raiz(abb ab){
// Retorna la raiz del arbol binario de busqueda.
// Pre: ab no vacio.
	return ab->dato;
}

abb subiz(abb ab){
// Retorna el sub arbol izquierdo.
// Pre: ab no vacio.
	return ab->iz;
}

abb subde(abb ab){
// Retorna el sub arbol derecho.
// Pre: ab no vacio.
	return ab->de;
}

bool vacio(abb ab){
// Retorna true si ab es vacio, false en caso contrario.
	return (ab == NULL);
}

bool pertenece(int x, abb ab){
// Retorna true si ab pertenece a ab, false en caso contrario.
	if (ab == NULL)
		return false;
	else if (ab->dato == x)
		return true;
	else if (x < ab->dato)
		return pertenece(x, ab->iz);
	else
		return pertenece(x, ab->de);
}

int max(int a, int b){
// Retorna el maximo de a y b.
	if(a > b)
		return a;
	else
		return b;
}

int profundidad(abb ab){
// Retorna la profundidad del arbol.
	if (ab == NULL)
		return 0;
	else
		return 1 + max(profundidad(ab->iz), profundidad(ab->de));

}

int cantidad(abb ab){
// Retorna la cantidad de elementos del arbol.
	if (ab == NULL)
		return 0;
	else
		return cantidad(ab->iz) + 1 + cantidad(ab->de);
}

abb destruir (abb ab){
// Destruye el arbol y libera la memoria asociada.
	if (ab != NULL){
		ab->iz = destruir(ab->iz);
		ab->de = destruir(ab->de);
		delete ab;
	}
	return ab;
}
