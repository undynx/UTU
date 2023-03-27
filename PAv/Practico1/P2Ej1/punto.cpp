#inclue "punto.h"

Punto::Punto(){
	x = 0;
	y = 0;
}

Punto::Punto(float x, float){
	this->x = x;
	this->y = y;
}
	
float Punto::getX(){
	//Post: devuelve X
	return x;
}
	
float getY(){
	//Post: devuleve Y
	return y;
}
	
void Punto::setX(float x){
	//Post: setea x
	this->x = x;
}
	
void Punto::setY(float y){
	//Post: setea y
	this->y = y;
}

Punto::~Punto(){}

