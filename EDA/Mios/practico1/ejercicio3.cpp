/*Implemente recursivamentelas siguientes operaciones sin que las soluciones 
retornadascompartan memoria con los parámetros.*/


lista Take(int i, lista l){
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.
	
	if(l == NULL){
		return l;
	}else if(i == 0){
		return NULL;
	}else{
		lista nueva = new(nodo_lista);
		nueva->dato = l->dato;
		nueva->sig = Take(i-1, l->sig);
		return nueva;
	}

}

lista Drop(int u, lista l){
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.
	
	if(l == NULL){
		return l;
	}else if(u > 0){
		return Drop(u-1, l->sig);
	} else{
		lista aux = new(nodo_lista);
		aux->dato = l->dato;
		aux->sig = Drop(u, l->sig);
		return aux;
	}

}

lista Merge(lista l, lista p){
// Genera una lista fruto de intercalar ordenadamente las listas.
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.
	
	if((l == NULL) && (p == NULL)){
		return NULL;
	} else if(l == NULL){
		lista nueva = new(nodo_lista);
		nueva->dato = p->dato;
		nueva->sig = Merge(l, p->sig);
		return nueva;
	} else if(p == NULL){
		lista nueva = new(nodo_lista);
		nueva->dato = l->dato;
		nueva->sig = Merge(l->sig, p);
		return nueva;
	} else{
		lista nueva = new(nodo_lista);
		if(l->dato > p->dato){
			nueva->dato = p->dato;
			return Merge(l, p->sig);
		} else{
			nueva->dato = l->dato;
			return Merge(l->sig, p);
		}
		return nueva;
	}

}

lista Append(lista l, lista p){
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

	if((l == NULL) && p == NULL){
		return l;
	}else {
		lista aux = new(nodo_lista);
		if(l != NULL){
			aux->dato = l->dato;
			aux->sig = Append(l->sig, p);
			return aux;
		}else{
			aux->dato = p->dato;
			aux->sig = Append(l, p->sig);
			return aux;
		}
	}
}