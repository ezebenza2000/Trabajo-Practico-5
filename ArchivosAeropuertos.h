#include "Archivo.h"
#include "BST.h"
#include <fstream>
#include <string>

using namespace std;

class ArchivoAeropuertos :: public Archivo 
{
 public:
     //Constructor
     //PRE: -.
     //POST: Objeto archivo creado.
     ArchivoAeropuertos(){};
     //Destructor
     //PRE: Objeto archivo creado.
     //Libera recursos, memoria, etc.
     ~ArchivoAeropuertos(){};

     //PRE: Recibe un string
     //POST: Devuelve el string sin guion medio
     string limpiar_string(string dato);

     //PRE: Archivo de lectura y puntero a la lista de peliculas que se va a cargar.
     //POST: Lista cargada.
     void cargar_aeropuerto(ifstream archivo, Aeropuertos aeropuerto);
     
     //POST: Devuelve booleana depende de si pudo leer el archivo o no.
     bool lee_archivo(string nombre_archivo, BST<string> * diccionario);
};