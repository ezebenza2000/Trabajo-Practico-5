#ifndef COLA_H
#define COLA_H

#include "BSTNode.h"
#include "string"
#include "aeropuertos.h"

class Cola{

private:
    BSTNode<string>* prim;
    BSTNode<string>* ult;

public:
    Cola();

    // Devuelve verdadero si la cola no tiene elementos encolados, false en caso contrario.
    // Pre: la cola fue creada.
    bool esta_vacia();

    // Agrega un nuevo elemento a la cola.
    // Pre: la cola fue creada.
    // Post: se agregó un nuevo elemento a la cola, valor se encuentra al final
    // de la cola.
    void cola_encolar(BSTNode<string>* elemento);

    // Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
    // primero de la cola, y se devuelve su valor, si está vacía, devuelve NULL.
    // Pre: la cola fue creada.
    // Post: se devolvió el valor del primer elemento anterior, la cola
    // contiene un elemento menos, si la cola no estaba vacía.
    BSTNode<string>* cola_desencolar();


    // Pre: la cola fue creada.
    // Post: Desencola todos los elementos y los muestra por pantalla
    void mostrar();
};

#endif //COLA_H
