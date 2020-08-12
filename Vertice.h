#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include <iostream>
#include "Arista.h"

using namespace std;

class Arista;

class Vertice{
  private:
    Vertice *sig; //sig representa el vertice que le sigue en la lista.
    Arista *ady;  //ady reprenseta su primer arista adyacente.
    string nombre;
  public:
    Vertice (string nombre);
    ~Vertice();
    void set_sig_vertice(Vertice * siguiente);
    Vertice * get_sig_vertice();
    void set_adyacente(Arista * adyacente);
    Arista * get_adyacente();
    void set_nombre(string nombre);
    string get_nombre();
};

#endif // VERTICE_H_INCLUDED
