#ifndef punto_h
#define punto_h

class Punto{
	private:
		float x;
		float y;
	
	public:
		Punto(); //constructor por defecto
		Punto(float x, float y); //constructor comun
		
		float getX();
		//Post: devuelve X
		
		float getY();
		//Post: devuleve Y
		
		void setX(float x);
		//Post: setea x
		
		void setY(float y);
		//Post: setea y
		
		~Punto();

} 

#endif