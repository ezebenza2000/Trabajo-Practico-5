#ifndef MENUVUE_H
#define MENUVUE_H

#include "Grafo.h"
#include "aeropuertos.h"
#include "t_menu.h"

using namespace std;

class MenuVue: private t_menu{

public:
    BST<string>* diccionario;

    char opcion;

    //cosntructor
    MenuVue(BST<string>* Diccionario_de_Aeropuertos);

    //Mostrar las opciones que el usuario puede elegir
    //Pre-Condicion: -
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario
    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: -
    //Post-Condicion: Procesa la opcion invocando las funciones correspondientes
    bool selectorDeOpciones();


};
#endif //MENUVUE_H
