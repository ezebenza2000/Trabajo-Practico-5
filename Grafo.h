#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"
#include "Costos.h"
#include "VerticeVertice.h"
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
    private:
      Vertice *h;
      void anular();

      //Recibe la ruta de origen y destino para saber que "VIAJE" borrar
      void eliminarArista(Vertice *origen, Vertice *destino);

      //Recibe la direccion del vertice que quiere borrar
      void eliminarVertice(Vertice *vert);

      //Con la direccion de memoria y los valores recibido crea una nueva arista
      void insertaArista(Vertice *origen, Vertice *destino, int precio, float tiempo, string origenV);

      void camino_minimo_p(Vertice *origen, Vertice *destino);

      void camino_minimo_t(Vertice *origen, Vertice *destino);

    public:
        //Constructor
        Grafo();

        //Destructor
        ~Grafo();

        //pregunta si esta vacio
        bool vacio();

        //PRE:objeto creado;
        //POST: Devuelve la cantidad de vertices;
        int tam();

        //Realiza un print grafico que muestra el grafo
        void listaAdyacencia();

        //PRE: Recibe un string
        //POST: Devuelve el vertice con el nombre de ese string
        Vertice *getVertice(string nombre);

        //PRE: Grafo ya inicializado
        //POST: Agrega un vertice al final de la lista de vertices
        void inserta_vertice(string nombre);

        //PRE:Recibe el nombre del vertice origen, el del destino, el precio y el tiempo
        //POST: Crea una arista adyacente al vertice origen con los datos;
        void inserta_arista(string origen, string destino, int precio, float tiempo);

        //PRE: Recibe el nombre del vertice origen y del destino
        //para saber que arista es
        //POST: De existir una arista con cierto camino se borra.
        void eliminar_arista(string origen, string destino);


        //PRE: Recibe un string
        //POST: Elimina el vertice con dicho nombre
        void eliminar_vertice(string vertice);

        void camino_minimo(string origen, string destino, int opcion);


};


#endif //GRAFO_H
