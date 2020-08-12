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
    ~Arista();
    Arista * get_arista();
    void set_sig_arista(Arista * siguiente);
    Vertice * get_adyacente();
    void set_sig_adyacente(Vertice * adyacente);
    void set_origen(string origen);
    string get_origen();
    float get_precio();
    float get_tiempo();
    Vuelo* get_vuelo();

};


#endif // ARISTA_H_INCLUDED
