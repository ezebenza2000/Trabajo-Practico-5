#include "archivo.h"
#include "BST.h"
#include "BSTNode.h"
#include "menu.h"
#include "aeropuertos.h"
#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string RUTA_AEROPUERTOS = "aeropuertos.txt";
const string RUTA_VUELOS = "vuelos.txt";

int main(){
	BST<string>* diccionarioAeropuertos = new BST<string>();
	Grafo* grafoVuelos = new Grafo();
	Archivos archivoDeAeropuertos;
	archivoDeAeropuertos.abrirArchivo(RUTA_AEROPUERTOS);
	while(!(archivoDeAeropuertos.finalArchivo())){
		string datos = archivoDeAeropuertos.leerLinea();
        if (datos != ""){
            Aeropuertos* aeropuerto = new Aeropuertos();
            archivoDeAeropuertos.cargar_aeropuerto(datos,aeropuerto);
            diccionarioAeropuertos->insert(aeropuerto->get_clave(),aeropuerto);
        }
	}
	Archivos archivoDeVuelos;
	archivoDeVuelos.abrirArchivo(RUTA_VUELOS);
	while(!(archivoDeVuelos.finalArchivo())){
		string datos = archivoDeVuelos.leerLinea();
        if (datos != ""){
            archivoDeVuelos.cargar_vuelo(datos,grafoVuelos);
        }
	}
	Menu menu(diccionarioAeropuertos,grafoVuelos);
	while(menu.opcion != '7'){
		menu.mostrarMenu();
		menu.selectorDeOpciones();
	}
	delete grafoVuelos;
	delete diccionarioAeropuertos;
	return 0;
}
