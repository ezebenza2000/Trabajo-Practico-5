#include "menu.h"
#include "BST.h"
#include "aeropuertos.h"
#include <iostream>

Menu :: Menu(BST<string>* Diccionario_de_Aeropuertos){
    this->diccionario = Diccionario_de_Aeropuertos;
    this->opcion = 0;
}

void Menu::mostrarMenu(){

    cout << "\n\t1. Consultar aeropuerto s\n";
    cout << "\t2. Alta\n";
    cout << "\t3. Baja\n";
    cout << "\t4. InOrder\n";
    cout << "\t5. Ancho\n";
    cout << "\t6. Salir\n";
    cout << "\tIngrese el numero de la opcion que desea seleccionar: ";
    cin >> opcion;
}

bool Menu::selectorDeOpciones() {

    bool estado;

    switch (this->opcion) {

        case '0':{
            break;
        }

        case '1': {
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            cout << "\n\t---------------------- Busqueda ------------------------------\n";
            BSTNode<string>* aeropuerto = diccionario->search(diccionario->get_root(),clave);
            aeropuerto->get_valor()->mostrar_aeropuerto();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '2': {
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            cout << "\t--------------------- Baja -------------------------------------\n";
            diccionario->remove(clave);
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '3': {
            Aeropuertos* aux = new Aeropuertos();
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            cout << "\t-------------------- Alta -------------------------------------\n";
            diccionario->insert(clave,aux);
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '4': {
        	cout << "\t-------------------- Recorrido IO-------------------------------\n";
            diccionario->print_in_order();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }
        
        case '5': {
        	cout << "\t-------------------- Recorrido PN-------------------------------\n";
            diccionario->print_por_niveles();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '6': {
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
