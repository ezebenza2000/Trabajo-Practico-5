#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

class Vuelo{
    private:
        int precio;
        int tiempo;

    public:
        Vuelo(int precio, int tiempo);
        void set_precio(int precio);
        int get_precio();
        void set_tiempo(int tiempo);
        int get_tiempo();
};

Vuelo :: Vuelo(int precio, int tiempo){
    this->precio = precio;
    this->tiempo = tiempo;
}

void Vuelo :: set_precio(int precio){
    this->precio = precio;
}

int Vuelo :: get_precio(){
    return this->precio;
}

void Vuelo :: set_tiempo(int tiempo){
    this->tiempo = tiempo;
}

int Vuelo :: get_tiempo(){
    return this->tiempo;
}
#endif // VUELO_H_INCLUDED
