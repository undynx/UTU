/* Dada la siguiente definición del TAD Lista, implementar las siguientes 
operaciones recursivamente (sin acceder a la representacion interna)

lista Null();
// Crea la lista vacía.

lista Cons(int x, lista l);
// Inserta el elemento x al principio de la lista l.

bool IsEmpty(lista l);
// Retorna true si l es vacía, false en caso contrario.

int Head(lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacía.

lista Tail(lista l);
// Retorna la lista sin su primer elemento.
// Pre: l no vacía. */

bool IsElement(int x, lista l){
// Retorna true si x pertenece a l, false en caso contrario.

	if(IsEmpty(l)){
		return false;
	}else if(Head(l) == x){
		return true;
	}else{
		return IsElement(x, Tail(l));
	}
}

int Length(lista l){
// Retorna la cantidad de elementos de la lista.
	if(isEmpty(l))
		return 0
	else
		return 1 + Length(Tail(l));
}

int Max(lista l){
// Retorna el máximo elemento de l.
// Pre: l no vacía.
	if(isEmpty(l))
		return Head(l);
	else{
		int max_tail = Max(Tail(l));
		if (Head(l) > max_tail)
			max_tail = Head(l);
	}
	return max_tail;
}

bool Equals(lista l, lista p){
// Retorna true si las listas l y p son iguales (mismos elementos en el mismo orden)
// false en caso contrario.
	
	if((isEmpty(l)) && (isEmpty(p)){
		return true;
	}else{
		bool iguales = Equals(Tail(l), Tail(p));
		if(Head(l) == Head(p))
			iguales = true;
		else
			iguales = false;
	}
	
	return iguales;
}

void Show(lista l){
// Muestra los elementos de la lista l separados por comas.
	if(!isEmpty(l)){
		cout << Head(l);
		if(!isEmpty(Tail(l))){
			cout << ", "
			Show(Tail(l));
		}
	}
}

lista Remove(int x, lista l);
// Retorna la lista fruto de eliminarx en l.
// l no comparte memoria con la lista resultado.

lista Snoc(int x, lista l){
// Retorna la lista fruto de insertar el elemento x al final de la lista l.
// l no comparte memoria con la lista resultado.
	
}

lista Append(lista l, lista p);
// Retorna la lista fruto de agregar la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

int Last(lista l){
// Retorna el último elemento.
// Pre: l no vacía.
	if(isEmpty(Tail(l)))
		return Head(l);
	else
		Last(Tail(l));
}

int HowMany(int x, lista l);
// Cuenta las ocurrencias del natural x en la lista l

bool IsSorted(lista l){
// Retorna true si l está ordenada, false en caso contrario.

  	
	
}

lista Change(int x, int y, lista l);
// Retorna una nueva lista fruto de cambiar x por y en l.
// l no comparte memoria con la lista resultado.

lista InsBefore(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes de y en l.
// l no comparte memoria con la lista resultado.

lista InsAround(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes y después de y en l.
// l no comparte memoria con la lista resultado.

