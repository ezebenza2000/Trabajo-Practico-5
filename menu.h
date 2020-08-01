#ifndef MENU_H
#define MENU_H

#include "BST.h"
#include "aeropuertos.h"

using namespace std;

class Menu{

public:
    BST<string>* diccionario;

    char opcion;

    //cosntructor
    Menu(BST<string>* Diccionario_de_Aeropuertos);

    //Mostrar las opciones que el usuario puede elegir
    //Pre-Condicion: -
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario
    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: -
    //Post-Condicion: Procesa la opcion invocando las funciones correspondientes
    bool selectorDeOpciones();
};
#endif //MENU_H
