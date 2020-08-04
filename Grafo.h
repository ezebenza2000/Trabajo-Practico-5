#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>

using namespace std;

/*
Este tipo de grafo va a tener una lista de vertices
que cada uno tiene una lista de aristas, por lo tanto
grafo va a tener un puntero de tipo vertice y otro
de tipo arista
 */

class Vertice;

class Arista
{
    Arista *sig;
    Vertice *ady;
    int valor;
    friend class Grafo;
};


class Vertice
{
    Vertice *sig;
    Arista* ady;
    string nombre;
    friend class Grafo;
};



class Grafo
{
    Vertice *h;
    public:
        void inicializa();
        bool vacio();//pregunta si esta vacio
        int tamanio();//Devuele el tamanio
        Vertice *getVertice(string nombre);//Regresa la direccion del vertice
        void insertaArista(Vertice *origen, Vertice *destino, int valor);//
        void insertaVertice(string nombre);
        void listaAdyacencia();
        void eliminarArista(Vertice *origen, Vertice *destino);
        void anular();
        void eliminarVertice(Vertice *vert);
};


#endif //GRAFO_H
