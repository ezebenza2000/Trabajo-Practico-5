#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vuelos.h" //ad oc
#include "BST.h"
#include "Etiqueta.h"
#include "Vertice.h"
#include "Costos.h"
#include "Lista.h"
#include "Pila.h"


using namespace std;

/*
Este tipo de grafo va a tener una lista de vertices
que cada uno tiene una lista de aristas, por lo tanto
grafo va a tener un puntero de tipo vertice y otro
de tipo arista. Ademas cada arista tiene un puntero a la siguiente arista
y otro al vertice destino que apunta.
 */

class Grafo
{
    private:        /*ad oc*/
      Lista<Vertices<Vuelos>> adyasencia;
      
      //PRE:Recibe una arista cargada
      //POST: Añade la arista al final de la lista de aristas del vertice
      void insertaArista(Arista* arista);
      

    public:
        //Constructor
        Grafo();

        //Destructor
        ~Grafo();

        //pregunta si esta vacio
        bool vacio();

        //Realiza un print grafico que muestra el grafo
        void listaAdyacencia();

        //PRE: Recibe un string
        //POST: Devuelve el vertice con el nombre de ese string
        Vertice *getVertice(string nombre);

        //PRE: Grafo ya inicializado
        //POST: Agrega un vertice al final de la lista de vertices
        void inserta_vertice(string nombre);
        
        //PRE: Grafo ya inicializado
        //POST: Agrega un vertice al final de la lista de vertices
        void inserta_vertice(string nombre);

        //PRE: Recibe un string
        //POST: Elimina el vertice con dicho nombre
        void eliminar_vertice(string vertice);
        
        
        Lista<Etiqueta<Vuelos>> Grafo::camino_minimo(string origen, string destino, char t)(string origen, string destino);


};


#endif //GRAFO_H
