#include "menu.h"
#include "BST.h"
#include "aeropuertos.h"
#include <iostream>
#include <string>
#include <ctype.h>

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
    cout << "\t6. Abrir el menu de Vuelos\n";
    cout << "\t7. Salir\n";
    cout << "\tIngrese el numero de la opcion que desea seleccionar: ";
    cin >> opcion;
}


bool Menu::selectorDeOpciones() {

   while(opcion!='7'){
   	 bool estado = true;

    switch (this->opcion) {

        case '0':{
            break;
        }

        case '1': {
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            busca(clave, estado);
            break;
        }

        case '2': {
		    Aeropuertos* aux = new Aeropuertos();
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            cout << "\t-------------------- Alta -------------------------------------\n";
            alta(clave, aux);
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
            
        }

        case '3': {
		    string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            cout << "\t--------------------- Baja -------------------------------------\n";
            baja(clave);
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
        	this->mA.mostrarMenu();
        	this->mA.selectorDeOpciones();
            break;
        }

        case '7': {
            break;
        }

        default: {
            cout << "\tOpcion no valida. Ingrese alguna de las opciones en el menu" << endl;
            estado = true;
            break;
        }
    }
   }
    return estado;
}

 void Menu::alta(string clave, Aeropuertos* aux){
 	aux->cargar_por_teclado();
    diccionario->insert(clave,aux);	
 }
 
void Menu::baja(string clave){
	bool encontrado = true;
	busca(clave, encontrado);
	if(encontrado){
		diccionario->remove(clave);
	}
    cout<<"\n fue dado de baja";
}

bool Menu::busca(string clave, bool estado){
	for (unsigned int i = 0; i < clave.length(); i++){
                clave[i] = toupper(clave[i]);
    }
    if (diccionario->search(clave)){
        cout << "\n\t---------------------- Busqueda ------------------------------\n";
        BSTNode<string>* aeropuerto = diccionario->search(diccionario->get_root(),clave);
        aeropuerto->get_valor()->mostrar_aeropuerto();
        cout << "\n\t--------------------------------------------------------------\n";
        estado=true;
    }
    else {
        cout << "El codigo invalido" <<endl;
        estado=false;
    }
     return estado;       
}
