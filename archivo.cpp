
#include"archivo.h"

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
    			}
    			case 2:{
    				aeropuerto->set_nombre(elemento);
    			}
    			case 3:{
    				aeropuerto->set_ciudad(elemento);
    			}
    			case 4:{
    				double aux;
    				stringstream ss(elemento);
    				ss >> aux;
    				aeropuerto->set_superficie(aux);
    			}
    			case 5:{
    				aeropuerto->set_cantidad_terminales(auxEntero);
    			}
    			case 6:{
    				aeropuerto->set_destinos_nacionales(auxEntero);
    			}
    			case 7:{
    				aeropuerto->set_destinos_internacionales(auxEntero);
    			}
    		}
    	}
    }
}
