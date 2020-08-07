#ifndef PILA_H
#define PILA_H
#include "nodo_pila.h"

template <class T>
class pila
{
    public:
        pila();
        ~pila();
        //Pre: el valor deve ser valido
        //Post:agrega un nevo elemento a la pila
        void apilar(T valor);
        unsigned elementos;
    private:
        T *ultimo;
};

template <class T>
pila::pila()
{
    this->elementos=0;
    this->ultimo=NULL;
    //ctor
}

template <class T>
pila::~pila()
{
    while(elementos!=0){
        desapilar();
    }
    //dtor
}

template <class T>
void pila::apilar(T valor){
    nodo_pila* aux=new nodo_pila;
    *aux.valor=valor;
    *aux.set_next(ultimo);
    this->ultimo=aux;
    elementos++;
}

template <class T>
T pila::desapilar(){
    nodo_pila* aux;
    T data;
    aux=this->ultimo;
    this->ultimo=*aux.siguiente;
    data=aux.valor;
    delete aux;
    elementos--;
}

#endif // PILA_H
