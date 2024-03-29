#ifndef MENU_H
#define MENU_H

#include "BST.h"
#include "aeropuertos.h"
#include "Grafo.h"

using namespace std;

class Menu {

public:
    BST<string>* diccionario;

    Grafo* grafoVuelos;

    char opcion;

    //cosntructor
    Menu(BST<string>* Diccionario_de_Aeropuertos,Grafo* grafoVuelos);

    //Mostrar las opciones que el usuario puede elegir
    //Pre-Condicion: -
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario
    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: -
    //Post-Condicion: Procesa la opcion invocando las funciones correspondientes
    bool selectorDeOpciones();


    //PRE:Recibe un string
    //POST: La devuelve en mayuscula
    string aMayuscula(string mystr);

private:
    //cosas que claramente no hacen a la interfas y no deberian estar en esta clase.

    //Pre:
    //Post: da de alta un nuevo aeropuerto por teclado
    void alta(string clave, Aeropuertos* aux);

    //Pre:
    //Post:Si la clave es valida da de baja el aeropuerto
    void baja(string clave);

    //Pre:
    //Post: Busca un aeropueto por clave y lo muestra por pantalla
    bool busca(string clave, bool estado);

    void trabaja_grafo(int opcion_grafo);
};
#endif //MENU_H
