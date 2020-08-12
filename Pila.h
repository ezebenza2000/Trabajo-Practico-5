#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Nodo.h"
template < typename Dato >
class Pila
{
	private:
		// Primer elemento de la pila
		Nodo<Dato>* primero;
	public:
		// Constructor
		// PRE: ninguna
		// POST: construye una pila vacía
		//- primero apunta a nulo
		Pila();

		// Destructor
		// PRE: pila creada
		// POST: Libera todos los recursos de la pila
		~Pila();

		// ¿La pila es vacía?
		// PRE: pila creada
		// POST: devuelve verdadero si la pila es vacía
		//falso de lo contrario
		bool pila_vacia();

		// Agregar un elemento a la pila
		// PRE: pila creada
		// POST: agrega un dato (dentro de un nodo) al principio
		void insert(Dato* d);

		// Obtener el dato que está en la cima
		// PRE: - pila creada y no vacía
		// POST: devuelve el dato que está en la cima
		Dato* get_dato();

		// Borrado del nodo que está en la cima
		// PRE: - pila creada y no vacía
		// POST: libera el nodo que está en la cima
		void del_dato();
};

template < typename Dato >
Pila<Dato>:: Pila(){
	primero = 0;
}

template < typename Dato >
Pila<Dato>:: ~Pila(){
	while (!(this->pila_vacia())){
		this->del_dato();
	}
}

template < typename Dato >
bool Pila<Dato>::pila_vacia(){
	return (primero == 0);
}

template < typename Dato >
void Pila<Dato>::insert(Dato* d)
{
	Nodo<Dato>* pnodo = new Nodo<Dato>(d);
	pnodo->set_siguiente(primero);
	primero = pnodo;
}

template < typename Dato >
Dato* Pila<Dato>::get_dato()
{
	return primero->get_dato();
}

template < typename Dato >
void Pila<Dato>::del_dato(){
	Nodo<Dato>* paux = primero;

	primero = paux->get_siguiente();
	delete paux->get_dato();
	delete paux;
}



#endif // PILA_H_INCLUDED


