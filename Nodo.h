#ifndef NODO_H
#define NODO_H

template < typename Dato >
class Nodo
{
private:
    Dato* dato; // Dato a almacenar
    Nodo* psig; // Puntero a otro nodo
public:
    // Constructor con parametro
    // PRE: Ninguna
    // POST: Crea un nodo con el dato d
    // y el puntero a NULL
    Nodo(Dato* d);
    // Destructor
    // PRE: Nodo creado
    // POST: No hace nada
    ~Nodo();
    // Setea el dato (lo cambia)
    // PRE: el nodo tiene que estar creado
    // d tiene que ser un dato válido
    // POST: el nodo queda con el dato d
    void set_dato(Dato* d);
    // Setear el puntero al siguiente nodo
    // PRE: nodo creado y ps válido
    // POST: el puntero al siguiente apuntará a ps
    void set_siguiente(Nodo* ps);
    // Obtener el dato
    // PRE: nodo creado
    // POST: devuelve el dato que contiene el nodo
    Dato* get_dato();

    // Obtener el puntero al nodo siguiente
    // PRE: nodo creado
    // POST: Devuelve el puntero al siguiente nodo
    // si es el último devuelve NULL
    Nodo* get_siguiente();
};

#endif

template < typename Dato >
Nodo<Dato>::Nodo(Dato* d)
{
    dato = d;
    psig = 0;
}

template < typename Dato >
Nodo<Dato>::~Nodo() {
    psig = 0;
    delete psig;
    dato = 0;
    delete dato;
}

template < typename Dato >
void Nodo<Dato>::set_dato(Dato* d)
{
    dato = d;
}

template < typename Dato >
void Nodo<Dato>::set_siguiente(Nodo* ps)
{
    psig = ps;
}

template < typename Dato >
Dato* Nodo<Dato>::get_dato()
{
    return dato;
}


template < typename Dato >
Nodo<Dato>* Nodo<Dato>::get_siguiente()
{
    return psig;
}


