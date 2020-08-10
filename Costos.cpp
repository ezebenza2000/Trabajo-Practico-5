#include "Costos.h"


Costo::Costo(Vertice *vertice, int costo){
    this->vertice = vertice;
    this->costo = costo;
}

Costo :: Costo(){
	
}

Costo::~Costo(){
    delete vertice;
}

Vertice * Costo::get_vertice(){
    return this->vertice;
}

void Costo::set_vertice(Vertice* vertice){
    this->vertice = vertice;
}

int Costo::get_costo(){
    return this->costo;
}

void Costo::set_costo(int costo){
    this->costo = costo;
}
