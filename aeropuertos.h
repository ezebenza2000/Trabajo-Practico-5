#ifndef AEROPUERTOS_H
#define AEROPUERTOS_H

#include <string>

using namespace std;

class Aeropuertos
{
private:
    string IATA;
    string nombre;
    string ciudad;
    string pais;
    double superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;

public:
    //Constructor de la clase.
    //POST: Construye la clase con los datos proporcionados.
    Aeropuertos(string IATA, string nombre, string ciudad, string pais, double superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales);

    Aeropuertos();

    //POST: Devuelve el codigo IATA del aeropuerto.
    string get_clave();

    //POST: Devuelve el nombre del aeropuerto.
    string get_nombre();

    //POST: Devuelve el nombre de la ciudad donde se ubica el aeropuerto.
    string get_ciudad();

    //POST: Devuelve el pais donde se encuentra el aeropuerto.
    string get_pais();

    //POST: Devuelve la superficie en hilometros cuadrados del aeropuerto.
    double get_superficie();

    //POST: Devuelve la cantidad de terminales del aeropuerto.
    int get_cantidad_terminales();

    //POST: Devuelve la cantidad de destinos nacionales del aeropuerto.
    int get_destinos_nacionales();

    //POST: Devuelve la cantidad de destinos internacionales del aeropuerto.
    int get_destinos_internacionales();

    //POST: Imprime por pantalla todos los datos del aeropuerto
    void mostrar_aeropuerto();

    //POST: setea el codigo IATA del aeropuerto.
    void set_clave(string clave);

    //POST: setea el nombre del aeropuerto.
    void set_nombre(string nombre);

    //POST: setea el nombre de la ciudad donde se ubica el aeropuerto.
    void set_ciudad(string ciudad);

    //POST: setea el pais donde se encuentra el aeropuerto.
    void set_pais(string pais);

    //POST: setea la superficie en hilometros cuadrados del aeropuerto.
    void set_superficie(double superficie);

    //POST: setea la cantidad de terminales del aeropuerto.
    void set_cantidad_terminales(int cantidad_terminales);

    //POST: setea la cantidad de destinos nacionales del aeropuerto.
    void set_destinos_nacionales(int destinos_nacionales);

    //POST: setea la cantidad de destinos internacionales del aeropuerto.
    void set_destinos_internacionales(int destinos_internacionales);

    //POST: carga el aeropuerto por teclado.
    void cargar_por_teclado();
};

#endif //AEROPUERTOS_H
