//segmento.h

class Segmento{
	private:
		Punto* a;
		Punto* b;
	public:
		Segmento();
		Segmento(Punto* a, Punto* b);
		float getLargo();
		~Segmento();
		
}