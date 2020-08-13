
template < typename Dato >
class Etiqueta
{
public:
    Dato peso_llegada; //Peso acumulado del ultimo camino usado
    string nombre_vertice; // nombre del vertice que representa esta etiqueta
    bool hubo_cambio;//verifica si el peso cambio durante la ultima iteracion
    bool invariante;
    

    // Constructor con parametro
    // PRE: Ninguna
    // POST: Crea una Etiq
    Etiqueta();
    // Destructor
    // PRE: Etiq creada
    // POST: No hace nada
    ~Etiqueta();
    
};

#endif

template < typename Dato >
Etiqueta<Dato>::Etiqueta()
{
    

}

template < typename Dato >
Etiqueta<Dato>::~Etiqueta() {
   
}

