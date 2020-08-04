#include "archivo.h"
#include "BST.h"
#include "BSTNode.h"
#include "menu.h"
#include "aeropuertos.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string RUTA = "aeropuertos.txt";

int main(){
	BST<string>* diccionarioAeropuertos = new BST<string>();
	Archivos archivoDeAeropuertos;
	archivoDeAeropuertos.abrirArchivo(RUTA);
	while(!(archivoDeAeropuertos.finalArchivo())){

		string datos = archivoDeAeropuertos.leerLinea();
        if (datos != ""){
            Aeropuertos* aeropuerto = new Aeropuertos();
            archivoDeAeropuertos.cargar_aeropuerto(datos,aeropuerto);
            diccionarioAeropuertos->insert(aeropuerto->get_clave(),aeropuerto);
        }
	}
	Menu menu(diccionarioAeropuertos);
	while(menu.opcion != '7'){
		menu.mostrarMenu();
		menu.selectorDeOpciones();
	}
	delete diccionarioAeropuertos;
	return 0;
}
