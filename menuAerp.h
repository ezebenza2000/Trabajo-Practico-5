/*
Es solamente una idea lo de usar una cola. no es necesario. pero si lo hacemos de esta manera vamos a necesitar una clase
Cola template.
*/
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
    Grafo Vuelos;
    Cola ruta;

    //cosntructor
    MenuVue(Grafo Vuelos);

    //Mostrar las opciones que el usuario puede elegir
    //Pre-Condicion: -
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario
    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: -
    //Post-Condicion: Procesa la opcion invocando las funciones correspondientes
    bool selectorDeOpciones();

    //Pre-Condicion: -
    //Post-Condicion: Els usuario ingresa los datos por consola
    void interfas(string salida, string destino);

    //Pre-Condicion: -
    //Post-Condicion: mustra la ruta cargada
    void mostrar_ruta()


};
#endif //MENUVUE_H
