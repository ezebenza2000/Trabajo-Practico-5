#ifndef VERTICES_H_INCLUDED
#define VERTICES_H_INCLUDED

#include "Vertice.h"

class VerticeVertice{
    private:
        Vertice * primero;
        Vertice * segundo;
    public:
        VerticeVertice(Vertice * primero, Vertice * segundo);
        ~VerticeVertice();
        void set_primero(Vertice * primero);
        void set_segundo(Vertice * segundo);
        Vertice* get_primero();
        Vertice* get_segundo();
};


#endif // VERTICES_H_INCLUDED
