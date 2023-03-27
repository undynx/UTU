#include segmento.h

Segmento::Segmento(){
	a = new Punto();
	b = new Punto();
}

Segumento::Segmento(Punto *p1, Punto *p2){
	a = new Punto(p1->getX(), p1->getY());
	b = new Punto(p2->getX(), p2->getY());
}

float Segmento::getLargo(){
	return sqrt(pow(a->getX() - b->getX(), 2.0) + pow(a->getY() - b->getY(), 2.0));
	
}

Segmento::~Segmento(){
	delete a;
	delete b;
}