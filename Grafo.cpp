#include "Grafo.h"

void Grafo::inicializa(){
    h = NULL;
}

bool Grafo::vacio(){
    if (h == NULL){
        return true;
    }
    return false;
}

int Grafo::tamanio(){
    int contador = 0;
    Vertice *aux;
    aux = h;
    while(aux != NULL){
        contador++;
        aux = aux->sig;
    }
    return contador;
}

Vertice *Grafo::getVertice(string nombre){
    Vertice *aux;
    aux = h;
    while ( aux != NULL ){
        if (aux->nombre == nombre){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

void Grafo::insertaVertice(string nombre){
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    nuevo->ady = NULL;

    if (vacio()){
        h = nuevo;
    }
    else{
        Vertice *aux;
        aux = h;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void Grafo::insertaArista(Vertice *origen, Vertice *destino, int valor){
    Arista *nueva = new Arista;
    nueva->valor = valor;
    nueva->sig = NULL;
    nueva->ady = NULL;

    Arista *aux;
    aux = origen->ady;
    if (aux == NULL){
        origen->ady = nueva;
        nueva->ady = destino;
    }
    else{
        while ( aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nueva;
        nueva->ady = destino;
    }
}

void Grafo::listaAdyacencia(){
    Vertice *vertAux;
    Arista *arisAux;
    vertAux = h;
    while(vertAux != NULL){
        cout<<vertAux->nombre<<"->";
        arisAux = vertAux->ady;
        while(arisAux != NULL){
            cout<<arisAux->ady->nombre<<"->";
            arisAux = arisAux->sig;
        }
        vertAux = vertAux->sig;
        cout<<endl;
    }
}

void Grafo::anular(){
    Vertice *aux;

    while(h != NULL){
        aux = h;
        h = h->sig;
        delete aux;
    }
}

void Grafo::eliminarArista(Vertice *origen, Vertice *destino){
    Arista *actual, *anterior;
    actual = origen->ady;


    if(actual == NULL){
        cout<<"El vertice origen no tiene aristas"<<endl;
    }
    else if (actual->ady == destino){
        origen->ady = actual->sig;
        delete actual;
    }
    else{
        int aux = 1;
        while(actual != NULL && aux == 1 ){
            if (actual->ady ==destino){
                anterior->sig = actual->sig;
                delete actual;
                aux = 0;
            }
            else {
                anterior = actual;
                actual = actual->sig;
            }
        }
        if (aux == 1){
            cout << "Esos dos vertices no estan conectados" << endl;
        }

    }
}

void Grafo::eliminarVertice(Vertice *vert){
    Vertice *actual, *anterior;
    Arista *aux;

    actual = h;

    while(actual != NULL ){

        aux = actual->ady;
        int i = 0;
        while(aux != NULL && i == 0){
            if(aux->ady == vert){
                eliminarArista(actual, aux->ady);
                i++;
            }
            aux = aux->sig;
        }
        actual = actual->sig;
    }
    actual = h;
    if (h == vert){
        h = h->sig;
        delete actual;
    }
    else{
        while(actual != vert){
            anterior = actual;
            actual = actual->sig;
        }
        anterior->sig = actual->sig;
        delete actual;
    }
}


