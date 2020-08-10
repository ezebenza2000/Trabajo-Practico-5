#include "menuVue.h"
#include "BST.h"
#include "aeropuertos.h"
#include <iostream>
#include <string>
#include <ctype.h>

MenuVue :: MenuVue(Grafo Vuelos){
    this->Vuelos = Vuelos;
    this->opcion = 0;
}

void MenuVue::mostrarMenu(){

    cout << "\n\t1. Consultar por menor costo";
    cout << "\t2. Consultar por menor duracion";
    cout << "\t3. Volver";

}


bool MenuVue::selectorDeOpciones() {

    bool estado = true;

    switch (this->opcion) {

        case '0':{
            break;
        }

        case '1': {
            string salida, destino;
            interfas(salida, destino);
            cout << "\t-------------------- Su ruta fue -------------------------------------\n";
            this->ruta=camino_minimo(salida, destino, '1');
            ruta.mostrar();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '2': {
            string salida, destino;
            interfas(salida, destino);
            cout << "\t-------------------- Su ruta fue -------------------------------------\n";
            this->ruta=camino_minimo(salida, destino, '2');
            ruta.mostrar();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
            
        }
        
        case '3': {
            
            
            cout << "\n\t------->\n";
            estado = false;
            break;
            
        }

        default: {
            cout << "\tOpcion no valida. Ingrese alguna de las opciones en el menu" << endl;
            estado = true;
            break;
        }
    }
    return estado;
}


