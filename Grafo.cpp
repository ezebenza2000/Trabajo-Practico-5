#include "Grafo.h"

Grafo::Grafo(){
    h = NULL;
}

bool Grafo::vacio(){
    if (h == NULL){
        return true;
    }
    return false;
}

int Grafo::tam(){
    int contador = 0;
    Vertice *aux;
    aux = h;
    while(aux != NULL){
        contador++;
        aux = aux->get_sig_vertice();
    }
    return cont;
}

Vertice *Grafo::getVertice(string nombre){
    Vertice *aux;
    aux = h;
    while ( aux != NULL ){
        if (aux->get_nombre() == nombre){
            return aux;
        }
        aux = aux->get_sig_vertice();
    }
    return NULL;
}

void Grafo::insertaVertice(string nombre){
    Vertice *nuevo = new Vertice;
    nuevo->set_nombre(nombre);
    nuevo->set_sig_vertice(NULL);
    nuevo->set_adyacente(NULL);

    if (vacio()){
        h = nuevo;
    }
    else{
        Vertice *aux;
        aux = h;
        while(aux->get_sig_vertice() != NULL){
            aux = aux->get_sig_vertice();
        }
        aux->set_sig_vertice(nuevo);
    }
}

void Grafo::insertaArista(Vertice *origen, Vertice *destino, int precio, int tiempo, string origenV){
    Arista *nueva ;
    Vuelo *nuevo;
    nuevo->set_precio(precio);
    nuevo->set_tiempo(tiempo);
    nueva = new Arista(nuevo);
    nueva->set_origen(origenV);
    nueva->set_sig_adyacente(NULL);
    nueva->set_sig_arista(NULL);

    Arista *aux;
    aux = origen->get_adyacente();
    if (aux == NULL){
        origen->set_adyacente(nueva);
        nueva->set_sig_adyacente(destino);
    }
    else{
        while ( aux->get_arista() != NULL){
            aux = aux->get_arista();
        }
        aux->set_sig_arista(nueva);
        nueva->set_sig_adyacente(destino);
    }
}


void Grafo::insertaArista(string origen, string destino, int precio, int tiempo){
    insertaArista(getVertice(origen), getVertice(destino), precio, tiempo, origen)
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
        vertAux = vertAux-sig;
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

void Grafo::eliminarArista(Vertice *origen; Vertice *destino){
    Arista *actual, *anterior;
    actual = origen->get_adyacente();


    if(actual == NULL;){
        cout<<"El vertice origen no tiene aristas"<<endl;
    }
    else if (actual->get_adyacente() == destino){
        origen->set_adyacente(actual->get_arista());
        actual->set_sig_adyacente(NULL);
        delete actual;
    }
    else{
        int aux = 1;
        while(actual != NULL && aux == 1 ){
            anterior = actual;
            actual = actual->get_arista();
            if (actual->get_adyacente() == destino){
                anterior->set_sig_arista(actual->get_arista());
                actual->set_sig_adyacente(NULL);
                actual->set_sig_arista(NULL)
                delete actual;
                aux = 0;
            }
        }
        if (aux == 1){
            cout << "Esos dos vertices no estan conectados" << endl;
        }
    }
}

void Grafo::eliminarArista(string origen, string destino){
    eliminarArista(getVertice(origen),getVertice(destino));
}

void Grafo::eliminarVertice(Vertice *vert){
    Vertice *actual, *anterior;
    Arista *aux;

    actual = h;

    while(actual != NULL ){

        aux = actual->get_adyacente();
        int i = 0;
        while(aux != NULL && i == 0){
            if(aux->get_adyacente() == vert){
                eliminarArista(actual, aux->get_adyacente());
                i++;
            }
            aux = aux->get_arista();
        }
        actual = actual->get_sig_vertice();
    }
    actual = h;
    if (h == vert){
        h = h->get_sig_vertice();
        actual->set_adyacente(NULL);
        actual->set_sig_vertice(NULL);
        delete actual;
    }
    else{
        while(actual != vert){
            anterior = actual;
            actual = actual->get_sig_vertice();
        }
        anterior->set_sig_vertice(actual->get_sig_vertice());
        delete actual;
    }
}

void Grafo::eliminarVertice(string vertice){
    eliminarVertice(getVertice(vertice));
}


