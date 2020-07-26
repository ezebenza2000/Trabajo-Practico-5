#include "cola.h"

Cola :: Cola(){
    this->prim = NULL;
    this->ult = NULL;
}

bool Cola :: esta_vacia(){
    return this->prim == NULL;
}


void Cola :: cola_encolar(BSTNode<string>* elemento){
    if(this->prim == NULL){
        this->prim = elemento;
        this->ult = this->prim;
    }
    BSTNode<string>* aux = this->ult;
    aux->prox = elemento;
    this->ult = elemento;
}


BSTNode<string> *Cola :: cola_desencolar(){
    BSTNode<string>* aux = this->prim;
    this->prim = this->prim->prox;
    return aux;
}