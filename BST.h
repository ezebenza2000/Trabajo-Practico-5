//
// Created by carolina on 3/6/20.
//

#include "BSTNode.h"
#include "cola.h"
#include<iostream>

#ifndef ABB_BST_H
#define ABB_BST_H

template <class T>
class BST
{
private:
    // attributes
    BSTNode<T>* root;

    // methods

    // Pre: Objeto creado y recibe los datos;
    // Post: Compara en el arbol para ubicar por data
    BSTNode<T>* insert(BSTNode<T>* node, T data,Aeropuertos* aeropuerto);

    //Pre: Objeto creado
    //Post: Imprime de manera recursiva buscando del que esta mas a la izquierda
    //hasta el que esta mas a la derecha
    void print_in_order(BSTNode<T> * node);

    //Pre: Objeto creado
    //Post: Imprime el recorrido por niveles del arbol
    void print_por_niveles(BSTNode<T> *node);

    //Busca en el arbol el valor mas chico
    T find_min(BSTNode<T>* node);

    //Busca en el arbol el valor mas grande
    T find_max(BSTNode<T>* node);

    T successor(BSTNode<T>* node);

    T predecessor(BSTNode<T>* node);



    BSTNode<T>* remove(BSTNode<T>* node, T data);

    void delete_all(BSTNode<T>* node);

public:
    //methods


    //Constructor
    // Creates an empty tree
    BST();

    //Destructor
    ~BST<T>();


     // Pre : Objeto creado. Recibe un dato de tipo T y un string;
     // Post: Adds a new node to the actual BST. If its the tree is empty
     // the node inserted will be the root
    void insert(T data,Aeropuertos* aeropuerto);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void print_in_order();

    //Pre: Objeto creado
    //Post: Imprime el recorrido por niveles del arbol
    void print_por_niveles();

    // Finds a given value in the BST. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool search(T data);

    //Compara dependiendo el valor, si esta o no
    BSTNode<T>* search(BSTNode<T>* node, T data);

    // Finds the minimum value that exist in the BST.
    T find_min();

    // Finds the maximum value that exist in the BST.
    T find_max();

    // Finds the successor of a given data value.
    T successor(T data);

    // Finds the predecessor of a given data value.
    T predecessor(T data);

    // Removes a given data from the BST
    void remove(T data);

    BSTNode<T>* get_root();
    bool empty();

    // Deletes all the nodes in the BST
    void delete_all();

};

template <class T>
BST<T>::BST() {
    this->root = NULL;
}


template <class T>
BSTNode<T>* BST<T>::insert(BSTNode<T>* node, T data, Aeropuertos* valor) {

    if (node == NULL) {
        node = new BSTNode<T>(data,valor);
    }

    else if (data > node->get_data()) {
        node->set_right(insert(node->get_right(), data, valor), node);
    }

    else {
        node->set_left(insert(node->get_left(), data, valor), node);
    }
    return node;
}

template <class T>
void BST<T>::insert(T data, Aeropuertos* valor)
{
    this->root = insert(this->root, data, valor);
}

template <class T>
void BST<T>::print_in_order(BSTNode<T>* node)
{
    if (node != NULL)
    {
            print_in_order(node->get_left());
            if (node->get_data() != "NO"){
                std::cout<< "\n\nClave = " << node->get_data()<<endl;
                std::cout << "la clave es :_"<<node->get_data()<<"_"<<endl;
                node->get_valor()->mostrar_aeropuerto();
                //std::cout<< node->get_valor()->mostrar_aeropuerto()<<endl;
            }

            print_in_order(node->get_right());
    }
}

template <class T>
void BST<T>::print_in_order()
{
    this->print_in_order(this->root);
}

template <class T>
void BST<T>::print_por_niveles(BSTNode<T> *node){
    Cola* nuevaCola = new Cola();
    if(node != NULL) nuevaCola->cola_encolar(node);
    while(!nuevaCola->esta_vacia()){
        BSTNode<T>* aux = nuevaCola->cola_desencolar();
        std::cout << "\n\nClave = " << aux->get_data() << endl;
        if(!(aux->isLeaf())){
            if(aux->leftChildOnly()){
                nuevaCola->cola_encolar(aux->get_left());
                std :: cout << "Tengo hijo izq" << endl;
            }
            if(aux->rightChildOnly()){
                nuevaCola->cola_encolar(aux->get_right());
                std :: cout << "Tengo hijo der" << endl;
            }
            if (!aux->rightChildOnly() && !aux->leftChildOnly()){
                nuevaCola->cola_encolar(aux->get_left());
                nuevaCola->cola_encolar(aux->get_right());
                std :: cout << "Tengo ambos hijos" << endl;
            }

        }
        else if(aux->isLeaf()){
            std :: cout << "Soy hoja" << endl;
		}
        else break;
    }
    delete nuevaCola;
}

template <class T>
void BST<T>::print_por_niveles()
{
    this->print_por_niveles(this->root);
}

template <class T>
BSTNode<T>* BST<T>::search(BSTNode<T>* node, T data)
{
    if (node == NULL || node->get_data() == data)
        return node;

    if (data > node->get_data())
        return search(node->get_right(), data);

    return search(node->get_left(), data);
}

template <class T>
bool BST<T>::search(T data)
{
    BSTNode<T>* result = search(this->root, data);

    return result != NULL;
}


template <class T>
T BST<T>::find_min(BSTNode<T>* node)
{
    //if(node == NULL)
        //return -1;
    if(node->get_left() == NULL)
        return node->get_data();
    else
        return find_min(node->get_left());
}

template <class T>
T BST<T>::find_min()
{
    return find_min(this->root);
}

template <class T>
T BST<T>::find_max(BSTNode<T>* node)
{
    if(node == NULL)
        return -1;
    else if(node->get_right() == NULL)
        return node->get_data();
    else
        return find_max(node->get_right());
}

template <class T>
T BST<T>::find_max()
{
    return find_max(this->root);
}

template <class T>
T BST<T>::successor(BSTNode<T>* node)
{
    if (node->get_right() != NULL)
    {
        return find_min(node->get_right());
    }
    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_data() < ancestor->get_data()) {
            successor = ancestor;
            ancestor = ancestor->get_left();
        }
        else
            ancestor = ancestor->get_right();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::successor(T data)
{
    BSTNode<T>* data_node = this->search(this->root, data);
    // Return the key. If the key is not found or successor is not found, return -1
    //if(data_node == NULL)
    //    return '-1';
    //else
    return successor(data_node);
}

template <class T>
T BST<T>::predecessor(BSTNode<T> * node)
{
    if (node->get_left() != NULL)
    {
        return find_max(node->get_left());
    }

    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_data() > ancestor->get_data()) {
            successor = ancestor; // so far this is the deepest node for which current node is in left
            ancestor = ancestor->get_right();
        }
        else
            ancestor = ancestor->get_left();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::predecessor(T data)
{
    BSTNode<T> * data_node = this->search(this->root, data);

    if(data_node == NULL)
        return -1;
    else return predecessor(data_node);
}

template <class T>
BSTNode<T> * BST<T>::remove(BSTNode<T>* node, T data)
{
    // The given node is not found in BST
    if (node == NULL)
        return NULL;

    if (node->get_data() == data)
    {

        if (node->isLeaf()){
        /*
            if(node->get_parent()->get_right() == node){
                node->get_parent()->set_right(NULL);
            }
            else if(node->get_parent()->get_left() == node){
                node->get_parent()->set_left(NULL);
            }*/
            node->set_tdata("NO");

        }
        else if (node->rightChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_right()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_right();
            delete aux->get_valor();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_left();
            delete aux->get_valor();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->successor(data);
            Aeropuertos* valor = search(this->root,successor_data)->get_valor();

            // Replace node's key with successor's key
            node->set_data(successor_data,valor);

            // Delete the old successor's key
            node->set_right(remove(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(remove(node->get_right(), data));

    else
        node->set_left(remove(node->get_left(), data));

    return node;
}

template <class T>
void BST<T>::remove(T data)
{
    this->root = remove(this->root, data);
}

template <class T>
BSTNode<T>* BST<T>::get_root(){
    return this->root;
}

template <class T>
bool BST<T>::empty()
{
    return this->root == NULL;
}


template <class T>
void BST<T>::delete_all(BSTNode<T>* node)
{
    if(node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node->get_valor();
    delete node;
}

template <class T>
void BST<T>::delete_all()
{
    this->delete_all(this->root);
}

template <class T>
BST<T>::~BST<T>()
{
    this->delete_all();
}


#endif //ABB_BST_H
