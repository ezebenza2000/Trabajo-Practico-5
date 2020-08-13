#include "Grafo.h"


Grafo::Grafo(){
    h = NULL;
}

Grafo::~Grafo(){
    anular();
}


void Grafo::anular(){
    Vertice *vAux;
    Arista *aAux;
    while(h != NULL){
        vAux = h;
        while(h->get_adyacente() != NULL){
            aAux = h->get_adyacente();
            h->set_adyacente(aAux->get_arista());
            delete aAux->get_vuelo();
            delete aAux;
        }
        h = h->get_sig_vertice();
        delete vAux;
    }
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

void Grafo::insertaArista(Vertice *origen, Vertice *destino, int precio, float tiempo, string origenV){
    Arista *nueva ;
    Vuelo* nuevo = new Vuelo(precio,tiempo);
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


void Grafo::inserta_arista(string origen, string destino, int precio, float tiempo){
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

void Grafo::camino_minimo_p(Vertice *origen, Vertice *destino){
    Lista<Costo> listaCosto; // listaCosto tiene nodos con un puntero a vertice y una variable de tipo entero
    Lista<Costo> listaOrdenada;// listaOrdenada tiene nodos ordenados con un puntero a vertice y una variable de tipo entero
    Pila<VerticeVertice> pilaVertice; //La cola guarda 2 vertices

    VerticeVertice* aux2;
    Costo * costoAux = new Costo(origen, 0);
    listaCosto.insert(costoAux); //Inserto el primer vertice con costo cero
    costoAux = new Costo(origen, 0);
    listaOrdenada.insert(costoAux); //Inserto el primer vertice con costo cero

    int bandera, bandera2 = 0;
    int costoActual = 0;
    Vertice *verticeActual, *destinoActual;
    Arista *aux;

    while (!listaOrdenada.lista_vacia()){
        verticeActual = listaOrdenada.get_dato(1)->get_vertice();// Tiene que igualarse al primer vertice de la lista
        costoActual = listaOrdenada.get_dato(1)->get_costo(); //Tiene que igualarse al costo de la posicion 1

        listaOrdenada.del_dato(1);

        if (verticeActual == destino){
            cout<<"Costo: "<<costoActual<<endl;

            bandera2 = 1;
            destinoActual = destino;
            while(!pilaVertice.pila_vacia()){
                cout<<destinoActual->get_nombre()<<"<--";
                while(!(pilaVertice.pila_vacia()) && pilaVertice.get_dato()->get_segundo() != destinoActual){
                    pilaVertice.get_dato();
                    pilaVertice.del_dato();
                }
                if(!pilaVertice.pila_vacia()){
                    destinoActual = pilaVertice.get_dato()->get_primero();
                }
            }
            //
        }



        aux = verticeActual->get_adyacente();
        while ( aux != NULL ){ //RECORRO LAS ARISTAS DEL VERTICE
            bandera = 0;
            costoActual = costoActual + aux->get_precio();   //le sumo el precio para calcular el costo final

            for ( int i = 1; i <= listaCosto.get_tam(); i++){
                cout << "la cantidad de vueltas que da el for = " << i << endl;
                if(aux->get_adyacente() == listaCosto.get_dato(i)->get_vertice()){

                    bandera = 1;
                    if (costoActual < listaCosto.get_dato(i)->get_costo()){//Segundo es el del costo

                        listaCosto.get_dato(i)->set_costo(costoActual);
                        for ( int j = 1; j <= listaOrdenada.get_tam(); j++){

                            if (aux->get_adyacente() == listaOrdenada.get_dato(i)->get_vertice()){
                                listaOrdenada.get_dato(i)->set_costo(costoActual);
                            }

                        }

                        listaOrdenada.lista_sort();

                        aux2 =  new VerticeVertice(verticeActual, aux->get_adyacente());
                        pilaVertice.insert(aux2);

                        costoActual = costoActual - aux->get_precio();
                    }
                }
            }

            if (bandera == 0){
                costoAux = new Costo(aux->get_adyacente(),costoActual);
                listaCosto.insert(costoAux);
                costoAux = new Costo(aux->get_adyacente(),costoActual);
                listaOrdenada.insert(costoAux);

                listaOrdenada.lista_sort();
                aux2 =  new VerticeVertice(verticeActual, aux->get_adyacente());
                pilaVertice.insert(aux2);
                costoActual = costoActual - aux->get_precio();

            }

            aux = aux->get_arista();
        }


    }


    if (bandera2 == 0){
        cout << "No hay ruta entre esos dos vertices"<< endl;
    }

    costoAux = 0;
    aux = 0;
    aux2 = 0;

    verticeActual = 0;
    destinoActual = 0;
}


void Grafo::camino_minimo_t(Vertice *origen, Vertice *destino){
    Lista<Costo> listaCosto; // listaCosto tiene nodos con un puntero a vertice y una variable de tipo entero
    Lista<Costo> listaOrdenada;// listaOrdenada tiene nodos ordenados con un puntero a vertice y una variable de tipo entero
    Pila<VerticeVertice> pilaVertice; //La cola guarda 2 vertices

    VerticeVertice* aux2;
    Costo * costoAux = new Costo(origen, 0);
    listaCosto.insert(costoAux); //Inserto el primer vertice con costo cero
    costoAux = new Costo(origen, 0);
    listaOrdenada.insert(costoAux); //Inserto el primer vertice con costo cero

    int bandera, bandera2 = 0;
    int costoActual = 0;
    Vertice *verticeActual, *destinoActual;
    Arista *aux;

    while (!listaOrdenada.lista_vacia()){
        verticeActual = listaOrdenada.get_dato(1)->get_vertice();// Tiene que igualarse al primer vertice de la lista
        costoActual = listaOrdenada.get_dato(1)->get_costo(); //Tiene que igualarse al costo de la posicion 1

        listaOrdenada.del_dato(1);

        if (verticeActual == destino){
            cout<<"Costo: "<<costoActual<<endl;

            bandera2 = 1;
            destinoActual = destino;
            while(!pilaVertice.pila_vacia()){
                cout<<destinoActual->get_nombre()<<"<--";
                while(!(pilaVertice.pila_vacia()) && pilaVertice.get_dato()->get_segundo() != destinoActual){
                    pilaVertice.get_dato();
                    pilaVertice.del_dato();
                }
                if(!pilaVertice.pila_vacia()){
                    destinoActual = pilaVertice.get_dato()->get_primero();
                }
            }
            //
        }



        aux = verticeActual->get_adyacente();
        while ( aux != NULL ){ //RECORRO LAS ARISTAS DEL VERTICE
            bandera = 0;
            costoActual = costoActual + aux->get_tiempo();   //le sumo el precio para calcular el costo final

            for ( int i = 1; i <= listaCosto.get_tam(); i++){
                cout << "la cantidad de vueltas que da el for = " << i << endl;
                if(aux->get_adyacente() == listaCosto.get_dato(i)->get_vertice()){

                    bandera = 1;
                    if (costoActual < listaCosto.get_dato(i)->get_costo()){//Segundo es el del costo

                        listaCosto.get_dato(i)->set_costo(costoActual);
                        for ( int j = 1; j <= listaOrdenada.get_tam(); j++){

                            if (aux->get_adyacente() == listaOrdenada.get_dato(i)->get_vertice()){
                                listaOrdenada.get_dato(i)->set_costo(costoActual);
                            }

                        }

                        listaOrdenada.lista_sort();

                        aux2 =  new VerticeVertice(verticeActual, aux->get_adyacente());
                        pilaVertice.insert(aux2);

                        costoActual = costoActual - aux->get_tiempo();
                    }
                }
            }

            if (bandera == 0){
                costoAux = new Costo(aux->get_adyacente(),costoActual);
                listaCosto.insert(costoAux);
                costoAux = new Costo(aux->get_adyacente(),costoActual);
                listaOrdenada.insert(costoAux);

                listaOrdenada.lista_sort();
                aux2 =  new VerticeVertice(verticeActual, aux->get_adyacente());
                pilaVertice.insert(aux2);
                costoActual = costoActual - aux->get_tiempo();

            }

            aux = aux->get_arista();
        }


    }


    if (bandera2 == 0){
        cout << "No hay ruta entre esos dos vertices"<< endl;
    }

    costoAux = 0;
    aux = 0;
    aux2 = 0;

    verticeActual = 0;
    destinoActual = 0;
}


void Grafo::camino_minimo(string origen, string destino,int opcion){
    if (opcion == 1){
        camino_minimo_p(getVertice(origen),getVertice(destino));
    }
    else if (opcion == 2){
        camino_minimo_t(getVertice(origen),getVertice(destino));
    }
}


