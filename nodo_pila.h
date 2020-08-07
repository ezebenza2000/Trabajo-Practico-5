#ifndef NODO_PILA_H
#define NODO_PILA_H

template <class T>
class nodo_pila
{
    public:
        nodo_pila();
        ~nodo_pila();
        void set_next(nodo_pila* next);
        T valor;
        nodo_pila *siguiente;
    private:

};

template <class T>
nodo_pila::nodo_pila()
{
    //ctor
}

template <class T>
nodo_pila::~nodo_pila()
{
    //dtor
}

template <class T>
void nodo_pila::set_next(nodo_pila* next){
    this->siguiente=next;
}
#endif // NODO_PILA_H
