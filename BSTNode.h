//
// Created by carolina on 3/6/20.
//

#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H
#include <string.h>
#include "aeropuertos.h"
using namespace std;

template <class T>
class BSTNode
{
private:

    T data; //data seria la clave del diccionario
    Aeropuertos* valor; //valor seria lo que almacena esa clave
    BSTNode<T>* left; //Left children
    BSTNode<T>* right; //Right children
    BSTNode<T>* parent; //Nodo Padre

public:
    BSTNode<T> *prox = NULL;

    //construye el nodo con data y valor, de principio apuntando todos los punteros a NULL
    BSTNode(T data,Aeropuertos* valor);

    //Devuelve data (la clave)
    T get_data();

    //Devuelve valor (El contenido de la clave)
    Aeropuertos* get_valor();

    //le cambia el valor a la clave y al valor(ver)
    void set_data(T data,Aeropuertos* valor);


    //PRE: Recibe 2 direcciones de memoria de otros nodos
    //POST: Establece un padre, y un hijo derecho
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);

    //PRE: Recibe 2 direcciones de memoria de otros nodos
    //POST: Establece un padre, y un hijo izquierdo
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);

    //PRE: Recibe una direccion de memoria
    //POST: La establece como hijo izquierdo
    void set_left(BSTNode<T>* left);

    //PRE: Recibe una direccion de memoria
    //POST: La establece como hijo derecho
    void set_right(BSTNode<T>* right);

    //PRE: Recibe una direccion de memoria
    //POST: La establece como padre
    void set_parent(BSTNode<T>* parent);

    //PRE:ninguna
    //POST:Devuelve la direccion de memoria de su hijo derecho
    BSTNode<T>* get_right();

    //PRE:ninguna
    //POST:Devuelve la direccion de memoria de su hijo izquierdo
    BSTNode<T>* get_left();

    //PRE:ninguna
    //POST:Devuelve la direccion de memoria de su padre
    BSTNode<T>* get_parent();

    //Pre: Objeto creado
    //POST: Devuelve si es un nodo hoja o no
    bool isLeaf();

    //Pre: Objeto creado
    //Post: Devuelve si solo tiene hijo derecho o no
    bool rightChildOnly();

    //Pre: Objeto creado
    //Post: Devuelve si solo tiene hijo izquierdo o no
    bool leftChildOnly();
};

template <class T>
BSTNode<T>::BSTNode(T data, Aeropuertos* valor)
{
    this->data = data;
    this->valor = valor;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

template <class T>
T BSTNode<T>::get_data()
{
    return this->data;
}


template <class T>
Aeropuertos* BSTNode<T>::get_valor()
{
    return this->valor;
}


template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right, BSTNode<T>* parent){
    this->right = right;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right){
    this->right = right;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left, BSTNode<T>* parent){
    this->left = left;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_parent(BSTNode<T> *parent) {
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_data(T data, Aeropuertos* valor)
{
    this->data = data;
    this->valor = valor;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left){
    this->left = left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_right()
{
    return this->right;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_left()
{
    return this->left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_parent()
{
    return this->parent;
}

template <class T>
bool BSTNode<T>::isLeaf() {
    return (this->get_left() == NULL && this->get_right() == NULL);
}

template <class T>
bool BSTNode<T>::rightChildOnly() {
    return (this->get_left() == NULL && this->get_right() != NULL);
}

template <class T>
bool BSTNode<T>::leftChildOnly() {
    return (this->get_left() != NULL && this->get_right() == NULL);
}

#endif //ABB_BSTNODE_H
