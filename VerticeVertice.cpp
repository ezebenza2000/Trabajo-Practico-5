#include "VerticeVertice.h"

VerticeVertice::VerticeVertice(Vertice * primero, Vertice * segundo){
    this->primero = primero;
    this->segundo = segundo;
}

VerticeVertice::~VerticeVertice(){
    primero = 0;
    segundo = 0;
}


void VerticeVertice::set_primero(Vertice * primero){
    this->primero = primero;
}


void VerticeVertice::set_segundo(Vertice * segundo){
    this->segundo = segundo;
}


Vertice* VerticeVertice::get_primero(){
    return this->primero;
}


Vertice* VerticeVertice::get_segundo(){
    return this->segundo;
}
