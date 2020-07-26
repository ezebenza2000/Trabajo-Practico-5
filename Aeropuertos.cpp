#include "Aeropuertos.h"
#include <iostream>

//Constructor de la clase.
//POST: Construye la clase con los datos proporcionados.
Aeropuertos :: Aeropuertos(string nombre, string ciudad, string pais, double superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales){
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->pais = pais;
    this->superficie = superficie;
    this->cantidad_terminales = cantidad_terminales;
    this->destinos_nacionales = destinos_nacionales;
    this->destinos_internacionales = destinos_internacionales;
}

//POST: Devuelve el nombrel aeropuerto.
string Aeropuertos :: get_nombre(){
    return this->nombre;
}

//POST: Devuelve el nombre de la ciudad donde se ubica el aeropuerto.
string Aeropuertos :: get_ciudad(){
    return this->ciudad;
}

//POST: Devuelve el pais donde se encuentra el aeropuerto.
string Aeropuertos :: get_pais(){
    return this->pais;
}

//POST: Devuelve la superficie en hilometros cuadrados del aeropuerto.
double Aeropuertos :: get_superficie(){
    return this->superficie;
}

//POST: Devuelve la cantidad de terminales del aeropuerto.
int Aeropuertos :: get_cantidad_terminales(){
    return this->cantidad_terminales;
}

//POST: Devuelve la cantidad de destinos nacionales del aeropuerto.
int Aeropuertos :: get_destinos_nacionales(){
    return this->destinos_nacionales;
}

//POST: Devuelve la cantidad de destinos internacionales del aeropuerto.
int Aeropuertos :: get_destinos_internacionales(){
    return this->destinos_internacionales;
}

//POST: Imprime por pantalla todos los datos del aeropuerto
void Aeropuertos :: mostrar_aeropuerto(){
    cout << "Nombre: " << nombre << "ciudad: " << ciudad << "pais: " << pais << "superficie: " << superficie << "terminales: " << cantidad_terminales << "destinos nacionales: " << destinos_nacionales << "destinos internacionales: " << destinos_internacionales << endl;
}