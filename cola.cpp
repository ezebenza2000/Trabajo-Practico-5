#include "cola.h"

Cola :: Cola(){
    this->prim = NULL;
    this->ult = NULL;
}

bool Cola :: esta_vacia(){
    return this->prim == NULL;
}


void Cola :: cola_encolar(BSTNode<string>* elemento){
	elemento->prox = NULL;
    if(this->prim == NULL){
        this->prim = elemento;
        this->ult = elemento;
    }
    else{
	    this->ult->prox = elemento;
	    this->ult = elemento;
    }
}


BSTNode<string> *Cola :: cola_desencolar(){
    BSTNode<string>* aux = this->prim;
    this->prim = this->prim->prox;
    return aux;
}

void Cola :: mostrar(){
	BSTNode<string>* aux;
	while(!this->esta_vacia()){
		aux=this->cola_desencolar();
		cout>>*aux; //hay que reemplazar esto por un petodo especifico para mostrar la informacion por pantalla
	}
}
