#include "Vuelo.h"

Vuelo :: Vuelo(int precio, float tiempo){
    this->precio = precio;
    this->tiempo = tiempo;
}

Vuelo :: Vuelo(){
	this->precio = 32767;
	this->tiempo = 10080;
}

Vuelo Vuoelo::operator+(Vuelo a){
	Vuelo b;
	b.set_precio(a.get_precio() + this->get_precio());
	b.set_tiempo(a.get_tiempo() + this->get_tiempo());
}

Vuelo Vuoelo::operator=(Vuelo a){
	this->precio=a.get_precio();
	this->tiempo=a.get_tiempo();
}


void Vuelo :: set_precio(int precio){
    this->precio = precio;
}

int Vuelo :: get_precio(){
    return this->precio;
}

void Vuelo :: set_tiempo(float tiempo){
    this->tiempo = tiempo;
}

float Vuelo :: get_tiempo(){
    return this->tiempo;
}
