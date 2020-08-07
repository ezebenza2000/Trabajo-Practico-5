//Descripcion:Carga y manipula archivos
// Tiene como atributo el archivo "ifstream" y abierto "booleano".
// Los metodos estan ordenados segun un numero 'i)'.
//Nota:Los atributos estan al final


#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include "aeropuertos.h"
#include "Grafo.h"

using namespace std;

class Archivos
{
    public:
        /*Metodos*/

        // PRE : -
        // POST: Crea el objeto.
        Archivos();

        // PRE : -
        // POST: Crea el objeto con el archivo abierto
        Archivos(string ruta);

        // PRE : -
        // POST: Cierra el archivo abierto.
        ~Archivos();

        // PRE : -
        // POST: Abre el archivo de la ruta en modo lectura
        void abrirArchivo(string ruta);

        // PRE : El archivo debe estar abierto
        // POST: Cierra el archivo
        void cerrarArchivo();

        // PRE : -
        // POST: Si el archivo esta abierto devuelve true, de lo contrario false
        bool estaAbierto();

        // PRE : El archivo debe estar abierto
        // POST: Si se llegó al final del archivo devuelve true, de lo contraro false
        bool finalArchivo();

        // PRE: -
        // POST: Devuelve true si existe la ruta del archivo, de lo contrario false
        bool existeRuta(string ruta);

        // PRE : El archivo debe estar abierto
        // POST: Lee la sigiente linea del archivo
        string leerLinea();

        //PRE: Archivo de lectura y puntero a la lista de peliculas que se va a cargar.
     	//POST: Lista cargada.
     	void cargar_aeropuerto(string Datos, Aeropuertos* aeropuerto);

        //PRE: Archivo de lectura y puntero a la lista de peliculas que se va a cargar.
        //POST: Lista cargada.
        void cargar_vuelo(string Datos, Grafo* grafo_vuelos);

    private:
        /*Atributos*/
        ifstream archivo;
        bool abierto;
};
#endif // ARCHIVOS_H
