#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>

using namespace std;

class Archivo
{
public:
    //Constructor
    //PRE: -.
    //POST: Objeto archivo creado.
    Archivo(){};
    //Destructor
    //PRE: Objeto archivo creado.
    //Libera recursos, memoria, etc.
    ~Archivo(){};
    //PRE: Variable archivo de lectura por parametro.
    //POST: Devuelve booleana depende de si se pudo abrir el archivo o no.
    bool existe_archivo(ifstream archivo);
};

#endif //ARCHIVO_H
