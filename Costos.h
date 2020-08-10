#ifndef COSTOS_H_INCLUDED
#define COSTOS_H_INCLUDED

#include "Vertice.h"

class Costo{
    private:
        Vertice * vertice;
        int costo;
    public:
        Costo(Vertice *vertice, int costo);
        ~Costo();
        Costo();
        Vertice * get_vertice();
        void set_vertice(Vertice* vertice);
        int get_costo();
        void set_costo(int costo);
};

#endif // COSTOS_H_INCLUDED
