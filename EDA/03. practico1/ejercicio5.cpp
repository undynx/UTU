listagral NullLG(){
// Crea la lista general vacía
	return NULL;
}

listagral ConsLG(listagral lg, lista l){
// Inserta la lista elemento l al principio de la lista general lg.

	listagral nueva_lg = new(nodo_listagral);
	nueva_lg->dato = l;
	nueva_lg->sig = lg;
	return nueva_lg;

}

bool IsEmptyLG(listagral lg){
// Verifica si la lista general está vacía.
	if(lg == NULL)
		return true;
	else
		return false;
}

lista HeadLG(listagral lg){
// Retorna la primer lista elemento.
// Pre: lg no vacía.
	return lg->dato;
}

listagral TailLG(listagral lg){
// Retorna lg sin su primer elemento.
// Pre: lg no vacía.
	return lg->sig;
}

int LengthLG(listagral lg){
// Retorna la cantidad de naturales de la lista general lg. (recursiva)
	
	if(IsEmptyLG(lg))
		return 0;
	else 
		return Length(HeadLG(lg)) + LengthLG(TailLG(lg));

}

void ShowLG(listagral lg){
// Muestra la lista general separando los naturales y listas de naturales por comas y
// encerrando cada lista de naturales entre paréntesis.

	

}
