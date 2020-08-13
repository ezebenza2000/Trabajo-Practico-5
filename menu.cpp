#include "menu.h"
#include "BST.h"
#include "aeropuertos.h"
#include <iostream>
#include <string>
#include <ctype.h>

Menu :: Menu(BST<string>* Diccionario_de_Aeropuertos,Grafo* grafoVuelos){
    this->diccionario = Diccionario_de_Aeropuertos;
    this->grafoVuelos = grafoVuelos;
    this->opcion = 0;
}

void Menu::mostrarMenu(){

    cout << "\n\t1. Consultar aeropuerto s\n";
    cout << "\t2. Alta\n";
    cout << "\t3. Baja\n";
    cout << "\t4. InOrder\n";
    cout << "\t5. Ancho\n";
    cout << "\t6. Abrir el menu de Grafos\n";
    cout << "\t7. Salir\n";
    cout << "\tIngrese el numero de la opcion que desea seleccionar: ";
    cin >> opcion;
}

string Menu::aMayuscula(string mystr){
	for (unsigned int i = 0; i < mystr.length(); i++){
                mystr[i] = toupper(mystr[i]);
    }
    return mystr;
}


bool Menu::selectorDeOpciones() {

    bool estado = true;

    switch (this->opcion) {

        case '0':{
            break;
        }

        case '1': {
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            clave = aMayuscula(clave);
            busca(clave, estado);
            break;
        }

        case '2': {
		    Aeropuertos* aux = new Aeropuertos();
            string clave;
            cout << "Ingrese un codigo IATA: ";
            cin >> clave;
            clave = aMayuscula(clave);
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
            clave = aMayuscula(clave);
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
            int opcion_grafo;
            do{
                cout << "\n1. Consultar por menor costo";
                cout << "\n2. Consultar por menor duracion";
                cout << "\n3. Ver grafo"<< endl;
                cout << "Eleccion: ";
                cin >> opcion_grafo;
            }while(opcion_grafo < 1 && opcion_grafo > 3);
            trabaja_grafo(opcion_grafo);
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

void Menu :: trabaja_grafo(int opcion_grafo){


    if (1 <= opcion_grafo && opcion_grafo <= 2){
        string salida,destino;
        cout << "Ingrese el aeropuerto de origen: " << endl;
        cin >> salida;
        cout << "Ingrese el aeropuerto de destino: " << endl;
        cin >> destino;
        salida = aMayuscula(salida);
        destino = aMayuscula(destino);
        if(opcion_grafo == 1){
            grafoVuelos->camino_minimo(salida,destino,1); //costo
        }
        else if(opcion_grafo == 2){
            grafoVuelos->camino_minimo(salida,destino,2); //duracion
        }
    }
    else if (opcion_grafo == 3){
        grafoVuelos->listaAdyacencia();
    }
    else{
        cout << "\nopcion invalida\n";
    }
}
