/*Implemente iterativamentelas siguientes operaciones accediendo directamente 
a la representación y sin usar procedimientos auxiliares y sin que las 
soluciones retornadas compartan memoria con los parámetros.*/

lista Take(int i, lista l){
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.

	lista nueva = NULL, fin = NULL;
	
	while((l != NULL) && (i>0)){
		
		if(nueva == NULL){ //si es el primer item
			nueva = new(nodo_lista); //crea el nodo
			nueva->dato = l->dato; //asigna el dato
			nueva->sig = NULL; //asigna NULL como siguiente 
			fin = nueva; //iguala fin a nueva
		}else{
			fin->sig = new(nodo_lista); //crea el nodo y lo asigna al siguiente de fin
			fin = fin->sig; //cambia la posicion de fin
			fin->dato = l->dato; //carga el dato;
			fin->sig = NULL; 
		}
		
		l = l->sig; //actualiza la posicion de l
		i--; //actualiza el contador
	}
	
	return nueva;
	 
}

lista Drop(int u, lista l){
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.
	
	lista nueva = NULL, fin = NULL;

	while(l != NULL){
		
		if(u<=0){ //si ya pasé los u numeros
		
			if(nueva == NULL){ //si es el primer elemento
				nueva = new(nodo_lista); //creo el nodo
				nueva->dato = l->dato; //actualizo el dato
				nueva->sig = NULL;
				fin = nueva;
			}else{ //si no es el primer elemento
				fin->sig = new(nodo_lista); 
				fin = fin->sig;
				fin->dato = l->dato;
				fin->sig = NULL;
			}
			
		}else{
			u--; //si no pase el u, disminuyo el contador
		}
		
		l = l->sig; //adelanto l hasta llegar a la posicion
	}
	
	return nueva;
}

lista Merge(lista l, lista p){
// Genera una lista fruto de intercalar ordenadamente las listas.
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.

	lista nueva = NULL, ult = NULL;
	
	while((l != NULL) || (p != NULL)){ //mientras alguna tenga datos:
		
		//CREACION DE LOS NODOS
		if (nueva = NULL){ //si es el primer elemento, creo el nodo
			nueva = new(nodo_lista);
			ult = nueva;
			ult->sig = NULL;
		}else{ //si no es el primer elemento
			ult->sig = new(nodo_lista); //creo el nodo
			ult = ult->sig;
			ult->sig = NULL;
		}
		
		//ASIGNACION DE VALORES
		if((l == NULL) && (p != NULL)){ //si l es nulo y p no, asigna el valor de p
			ult->dato = p->dato;
			p = p->sig; //se avanza en p
			
		}else if((p == NULL) && (l != NULL)){ //si p es nulo y l no, asigna el valor de l
			ult->dato = l->dato;
			l = l->sig; //avanza en l
			
		}else{ //ninguno de los dos es nulo
		
			if(l->dato <= p->dato){ //si p es mayor o igual que l
				ult->dato = l->dato;
				l = l->sig; //avanza en l
				
			}else{ //si l es mayor que p
				ult->dato = p->dato;
				p = p->sig; //avanza en p 
			}
		}
			
	}
	return nueva;
}

lista Append(lista l, lista p){
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

	lista nueva = NULL, ultimo = NULL;
	
	while((l != NULL) || (p != NULL){
		
		//Busco donde alocar el elemento
		if(nueva == NULL){ //si es el primer elemento
			nueva = new(nodo_lista);
			nueva->sig = NULL;
			ultimo = nueva; 
		}else{
			ultimo->sig = new (nodo_lista);
			ultimo = ultimo->sig;
			ultimo->sig = NULL;
		}
		
		if(l != NULL){ //si l aun tiene datos:
			ultimo->dato = l->dato; //copio de l
			l = l->sig; //itero sobre l
			
		} else{ //l no tiene datos
			ultimo->dato = s->dato;
			s = s->sig;
			
		}
	}
	return nueva;
}