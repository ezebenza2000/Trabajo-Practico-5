#ifndef AEROPUERTOS_H
#define AEROPUERTOS_H

#include <string>

using namespace std;

class Aeropuertos
{
private:
    string nombre;
    string ciudad;
    string pais;
    int superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;

public:
    //Constructor de la clase.
    //POST: Construye la clase con los datos proporcionados.
    Aeropuertos(string nombre, string ciudad, string pais, int superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales);

    //POST: Devuelve el nombrel aeropuerto.
    string get_nombre();

    //POST: Devuelve el nombre de la ciudad donde se ubica el aeropuerto.
    string get_ciudad();

    //POST: Devuelve el pais donde se encuentra el aeropuerto.
    string get_pais();

    //POST: Devuelve la superficie en hilometros cuadrados del aeropuerto.
    int get_superficie();

    //POST: Devuelve la cantidad de terminales del aeropuerto.
    int get_cantidad_terminales();

    //POST: Devuelve la cantidad de destinos nacionales del aeropuerto.
    int get_destinos_nacionales();

    //POST: Devuelve la cantidad de destinos internacionales del aeropuerto.
    int get_destinos_internacionales();

    //POST: Imprime por pantalla todos los datos del aeropuerto
    void mostrar_aeropuerto();
};

#endif //AEROPUERTOS_H