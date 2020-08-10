#ifndef ARISTA_H_INCLUDED
#define ARISTA_H_INCLUDED
#include "Vertice.h"
#include "Vuelo.h"
#include <iostream>


using namespace std;

class Vertice;

class Arista{
  private:
    Arista *sig; //sig representa la siguiente arista.
    Vertice *ady; //ady representa el vertice al que apunta.
    Vuelo *viaje;
    string origen;

  public:
    Arista(Vuelo * viaje);
    Arista * get_arista();
    void set_sig_arista(Arista * siguiente);
    Vertice * get_adyacente();
    void set_sig_adyacente(Vertice * adyacente);
    void set_origen(string origen);
    string get_origen();
    int get_precio();
    int get_tiempo();

};


#endif // ARISTA_H_INCLUDED
