#include "Grafo.h"


Grafo::Grafo(){
    h = NULL;
}

Grafo::~Grafo(){

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
    return contador;
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

void Grafo::inserta_vertice(string nombre){
    Vertice *nuevo = new Vertice(nombre);
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


void Grafo::inserta_arista(string origen, string destino, int precio, int tiempo){
    insertaArista(getVertice(origen), getVertice(destino), precio, tiempo, origen);
}

void Grafo::listaAdyacencia(){
    Vertice *vertAux;
    Arista *arisAux;
    vertAux = h;
    while(vertAux != NULL){
        cout<<vertAux->get_nombre()<<"->";
        arisAux = vertAux->get_adyacente();
        while(arisAux != NULL){
            cout<<arisAux->get_adyacente()->get_nombre()<<"->";
            arisAux = arisAux->get_arista();
        }
        vertAux = vertAux->get_sig_vertice();
        cout<<endl;
    }
}

void Grafo::anular(){
    Vertice *aux;

    while(h != NULL){
        aux = h;
        h = h->get_sig_vertice();
        delete aux;
    }
}

void Grafo::eliminarArista(Vertice *origen, Vertice *destino){
    Arista *actual, *anterior;
    actual = origen->get_adyacente();


    if(actual == NULL){
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
                actual->set_sig_arista(NULL);
                delete actual;
                aux = 0;
            }
        }
        if (aux == 1){
            cout << "Esos dos vertices no estan conectados" << endl;
        }
    }
}

void Grafo::eliminar_arista(string origen, string destino){
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

void Grafo::eliminar_vertice(string vertice){
    eliminarVertice(getVertice(vertice));
}

void Grafo::camino_minimo(Vertice *origen, Vertice *destino){
    Lista<Costo> listaCosto; // listaCosto tiene nodos con un puntero a vertice y una variable de tipo entero
    Lista<Costo> listaOrdenada;// listaOrdenada tiene nodos con un puntero a vertice y una variable de tipo entero
    Pila<VerticeVertice> pilaVertice; //La cola guarda 2 vertices

    Costo * costoAux1 = new Costo(origen, 0);
    listaCosto.insert(costoAux1); //Inserto el primer vertice con costo cero
    Costo * costoAux2 = new Costo(origen, 0);
    listaOrdenada.insert(costoAux2); //Inserto el primer vertice con costo cero

    int bandera, bandera2;
    int costoActual;
    Vertice *verticeActual, *destinoActual;
    while (!listaOrdenada.lista_vacia()){
        Costo * costoAux = listaOrdenada.get_dato(1);
        verticeActual = costoAux->get_vertice(); // Tiene que igualarse al primer vertice de la lista
        costoActual = costoAux->get_costo(); //Tiene que igualarse al costo de la posicion 1
        listaOrdenada.del_dato(1);

        if (verticeActual == destino){
            cout<<"Costo: "<<costoActual<<endl;

            bandera2 = 1;
            destinoActual = destino;
            while(!pilaVertice.pila_vacia()){
                cout<<destinoActual->get_nombre()<<"<--";
                while(!(pilaVertice.pila_vacia()) && ((pilaVertice.get_dato())->get_segundo() != destinoActual)){
                    cout << pilaVertice.get_dato() << "<--";
                    pilaVertice.del_dato();
                }
                if(!pilaVertice.pila_vacia()){
                    destinoActual = pilaVertice.get_dato()->get_primero();
                }

            }
        }
    }

    Arista *aux;

    aux = verticeActual->get_adyacente();
    while ( aux != NULL ){ //RECORRO LAS ARISTAS DEL VERTICE
        bandera = 0;
        costoActual = costoActual + aux->get_precio();   //le sumo el precio para calcular el costo final

        for ( int i = 1; i < listaCosto.get_tam(); i++){
            Costo * costoAux3 = listaCosto.get_dato(i);
            if(aux->get_adyacente() == costoAux3->get_vertice()){

                bandera = 1;
                if (costoActual < costoAux3->get_costo()){//Segundo es el del costo

                    costoAux3->set_costo(costoActual);
                    for ( int j = 1; j < listaOrdenada.get_tam(); j++){
                        Costo* costoAux6 = new Costo();//get_dato(j);
                        if (aux->get_adyacente() == costoAux6->get_vertice()){
                            costoAux6->set_costo(costoActual);
                        }
                        costoAux6 = 0;
                    }

                    listaOrdenada.lista_sort();

                    VerticeVertice* auxiliar =  new VerticeVertice(verticeActual, aux->get_adyacente());
                    pilaVertice.insert(auxiliar);
                    auxiliar = 0;

                    costoActual = costoActual - aux->get_precio();
                }
            }
            costoAux3 = 0;
        }

        if (bandera == 0){
            Costo * costoAux4 = new Costo(aux->get_adyacente(),costoActual);
            listaCosto.insert(costoAux4);
            Costo * costoAux5 = new Costo(aux->get_adyacente(),costoActual);
            listaOrdenada.insert(costoAux5);

            listaOrdenada.lista_sort();
            VerticeVertice* auxiliar =  new VerticeVertice(verticeActual, aux->get_adyacente());
            pilaVertice.insert(auxiliar);
            auxiliar = 0;
            costoActual = costoActual - aux->get_precio();
            costoAux4 = 0;
            costoAux5 = 0;
        }

        aux = aux->get_arista();
    }

    if (bandera2 == 0){
        cout << "No hay ruta entre esos dos vertices"<< endl;
    }
}

void Grafo::camino_minimo(string origen, string destino){
    camino_minimo(getVertice(origen),getVertice(destino));
}


