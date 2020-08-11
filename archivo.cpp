
#include"archivo.h"
#include "Grafo.h"
#include "Vertice.h"

Archivos::Archivos(){
    abierto = false;
}

Archivos::Archivos(string camino){
    abrirArchivo(camino);
}

Archivos::~Archivos(){
    if(this->abierto){
        this->cerrarArchivo();
    }
}

void Archivos::abrirArchivo(string camino){

    try{
        if(this->abierto){
            throw abierto;
        }
        archivo.open(camino);
        abierto = true;
        if(archivo.fail()){
            abierto = false;
            throw abierto;
        }
    }
    catch(bool &e){
        if(e){
            cout<<"\t-- AVISO -- Ya hay un archivo con ese nombre abierto! " << endl;
        }else{
            cout<<"\t-- AVISO -- No se pudo abrir el archivo \"" << camino << "\"" << endl;
        }
    }
}

void Archivos::cerrarArchivo(){
    archivo.close();
    abierto = false;
}

bool Archivos::estaAbierto(){
    return abierto;
}

bool Archivos::finalArchivo(){
    return archivo.eof();
}

bool Archivos::existeRuta(string ruta) {
    ifstream archivo(ruta);
    bool existe = archivo.good();
    archivo.close();
    return existe;
}

string Archivos::leerLinea(){
    string dato;
    getline(archivo,dato);
    return dato;
}

void Archivos :: cargar_aeropuerto(string datos, Aeropuertos* aeropuerto){
    int numeroDeDato = 0;
    int marcaIndice = 0;
    for(unsigned int i = 0; i<= datos.length(); i++){
    	if(datos[i] == ' ' || i == datos.length()){
    		string elemento = datos.substr(marcaIndice,i-marcaIndice);
    		numeroDeDato++;
    		marcaIndice = i+1;
    		int auxEntero;
    		stringstream ss(elemento);
    		ss >> auxEntero;
    		switch(numeroDeDato){
    			case 1:{
    				aeropuerto->set_clave(elemento);
                    break;
    			}
    			case 2:{
    				aeropuerto->set_nombre(elemento);
                    break;
    			}
    			case 3:{
    				aeropuerto->set_ciudad(elemento);
                    break;
    			}
    			case 4:{
    				double aux;
    				stringstream ss(elemento);
    				ss >> aux;
    				aeropuerto->set_superficie(aux);
                    break;
    			}
    			case 5:{
    				aeropuerto->set_cantidad_terminales(auxEntero);
                    break;
    			}
    			case 6:{
    				aeropuerto->set_destinos_nacionales(auxEntero);
                    break;
    			}
    			case 7:{
    				aeropuerto->set_destinos_internacionales(auxEntero);
                    break;
    			}
    		}
    	}
    }
}

void Archivos :: cargar_vuelo(string datos, Grafo* grafo_vuelos){
    int numeroDeDato = 0;
    int marcaIndice = 0;
    string aux1String;
    string aux2String;
    int auxTiempo;
    int auxPrecio;
    for(unsigned int i = 0; i<= datos.length(); i++){
        if(datos[i] == ' ' || i == datos.length()){
            string elemento = datos.substr(marcaIndice,i-marcaIndice);
            numeroDeDato++;
            marcaIndice = i+1;
            int auxEntero;
            stringstream ss(elemento);
            ss >> auxEntero;
            switch(numeroDeDato){
                case 1:{
                    aux1String = elemento;
                    break;
                }
                case 2:{
                    if(!(grafo_vuelos->getVertice(aux1String))) grafo_vuelos->inserta_vertice(aux1String);
                    if(!(grafo_vuelos->getVertice(elemento))) grafo_vuelos->inserta_vertice(elemento);
                    aux2String = elemento;
                    break;
                }
                case 3:{
                    auxTiempo = auxEntero;
                    break;
                }
                case 4:{
                    auxPrecio = auxEntero;
                    grafo_vuelos->inserta_arista(aux1String,aux2String,auxPrecio,auxTiempo);
                    break;
                }
            }
        }
    }
}
