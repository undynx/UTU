//Lista circular

listacirc crear(){
// Crea la lista circular vacia.
	return NULL;
}

listacirc cons(listacirc l, int n){
// Inserta n al inicio de l.
	listacirc aux = new(nodo_listacirc);
	aux->dato = n;

	if(l == NULL){
		aux->sig = aux;
		return aux;
	}else{
		aux->sig = l;
		listacirc ini = l;
		while(l->sig != ini)
			l = l->sig
		l->sig = aux;
		return aux;
	}
}

listacirc snoc(listacirc l, int n){
// Inserta n al final de l.
	listacirc aux = new(nodo_listacirc);
	aux->dato = n;

	if(l == NULL){
		aux->sig = aux;
		return aux;
	}else{
		aux->sig = l;
		listacirc ini = l;
		while(l->sig != ini)
			l = l->sig
		l->sig = aux;
		return aux;
	}
}

int head(listacirc l){
//Retorna el primer elemento de la lista
//Pre: l no es vacia
	return l->dato;
}

listacirc tail(listacirc l){
//Retorna el "resto" de la lista
//Pre: l no es vacia
	return l->sig;
}

bool isEmpty(listacirc l){
// Retorna true si l es vacia, false en caso contrario.
	if (l==NULL)
		return true;
	else 
		return false;
}

int cant(listacirc l){
// Retorna la cantidad de elementos de l.
	int contador = 0;
	listacirc ini = l;
	
	if(l == NULL)
		return contador;
	else{
		while(l->sig != ini){
			contador ++;
			l = l->sig;
		}
	}
	
	if(l != NULL)
		contador ++;
	
	return contador;
}

bool pertenece(listacirc l, int n){
// Retorna true si n pertenece a l, false en caso contrario.
	listacirc ini = l;
	
	if(l == NULL)
		return false;
	else{
		while((l->sig != ini) && (l->dato != n))
			l = l->sig;
		
		if(l->dato == n)
			return true;
		else
			return false;
	}

}

listacirc elim(listacirc l, int elem);
// En caso de que elem pertenezca a l, retorna l sin ese elemento.

listacirc destruir(listacirc l);
// Destruye l y libera la memoria asociada.