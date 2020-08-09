#ifndef LISTA_H
#define LISTA_H

# include <iostream>
# include "Nodo.h"

template < typename Dato >
class Lista
{
    private:
        // Primer elemento de la lista
        Nodo<Dato>* primero;
        // Tamaño de la lista
        unsigned tam;
    public:
        // Constructor
        // PRE: Ninguna
        // POST: construye una lista vacía
        // - primero apunta a nulo
        // - tam = 0
        Lista();
        // Destructor
        // PRE: Lista creada
        // POST: Libera todos los recursos de la lista
        ~Lista();
        // Agregar un elemento a la lista
        // PRE: lista creada y d válido
        // POST: agrega un dato dentro de un nodo al principio
        // - modifica el primero
        // - tam se incrementa en 1
        void insert(Dato* d);
        // Obtener el tamaño de la lista
        // PRE: Lista creada
        // POST: devuelve el tamaño de la lista (cantidad de nodos)
        int get_tam();
        // Obtener el dato que está en la posición pos
        // PRE: - lista creada y no vacía
        // - 0 < pos <= tam
        // POST: devuelve el dato que está en la posición pos
        // se toma 1 como el primero
        Dato* get_dato(unsigned pos);
        // ¿Lista vacia?
        // PRE: Lista creada
        // POST: T si es vacia, F sino
        bool lista_vacia();
        //Borro un nodo
        //PPRE: Lista creada y recibe una posicion
        //POST: decrementa el tamaño y borra el nodo de la posicion
        void del_dato(int pos);
        //Devuelve el nodo de la posicion
        //PRE: Lista creada y recibe la posicion
        //POST: Devuelve el puntero al nodo en dicha posicion
        Nodo<Dato> * get_nodo(int pos);
        //Esta funcion usa get_costo() entonces solo sirve con ese objeto;
        void lista_sort();
};

template < typename Dato >
Lista<Dato>::Lista()
{
    primero = 0;
    tam = 0;
}

template < typename Dato >
Lista<Dato>::~Lista()
{
    while (!this->lista_vacia())
    {
        this->del_dato(1);
    }
}

template < typename Dato >
bool Lista<Dato>::lista_vacia()
{
    return (tam == 0);
}

/*
template < typename Dato >
void Lista<Dato>::insert(Dato d)
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (!(this->lista_vacia()))
    {
        nuevo->set_siguiente(primero);
    }
    primero = nuevo;
    tam++;
}
*/

template < typename Dato >
void Lista<Dato>::insert(Dato* d)
{
    Nodo<Dato>* pnodo = new Nodo<Dato>(d);
    Nodo<Dato>* paux = primero;
    if (this->lista_vacia()){
        primero = pnodo;
    }
    else
    {
        while (paux->get_siguiente()){

            paux = paux->get_siguiente();
        }
        paux->set_siguiente(pnodo);

    }
    tam++;
}

template < typename Dato >
Dato* Lista<Dato>::get_dato(unsigned pos)
{

    Nodo<Dato> *paux = primero;
    unsigned i = 1;
    while (i < pos && paux->get_siguiente())
    {
        paux = paux->get_siguiente();
        i++;
    }
    return paux->get_dato();
}

template < typename Dato >
void Lista<Dato>::del_dato(int pos)
{
    Nodo<Dato> * borrar = primero;
    if (pos == 1){
        primero = borrar->get_siguiente();
    }
    else{
        Nodo<Dato> * anterior = get_nodo(pos-1);
        borrar = anterior->get_siguiente();
        anterior->set_siguiente(borrar->get_siguiente());
    }

    delete borrar;
    tam--;
}

template < typename Dato >
Nodo<Dato> * Lista<Dato>::get_nodo(int pos){
    Nodo<Dato> * aux = primero;
    int i = 1;
    while (i < pos){
        aux = aux->get_siguiente();
        i++;
    }
    return aux;
}

template < typename Dato >
int Lista<Dato>::get_tam()
{
    return tam;
}


template < typename Dato >
void Lista<Dato>::lista_sort(){

    Nodo<Dato> * pAct = primero;

    while(pAct != NULL){
        Nodo<Dato> * pSig = pAct->get_siguiente();
        while(pSig != NULL){
            Dato * datoAct = pAct->get_dato();
            Dato * datoSig = pSig->get_dato();
            if (datoAct->get_costo() > datoSig->get_costo()){
                pSig->set_dato(datoAct);
                pAct->set_dato(datoSig);
            }
            pSig = pSig->get_siguiente();
        }
        pAct = pAct->get_siguiente();
    }

}


#endif
