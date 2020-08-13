#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

class Vuelo{
    private:
        int precio = 0;
        float tiempo = 0;

    public:
        Vuelo(int precio, float tiempo);
        Vuelo();
        Vuelo operator+(Vuelo a);
        Vuelo operator=(Vuelo a);
        void set_precio(int precio);
        int get_precio();
        void set_tiempo(float tiempo);
        float get_tiempo();
};
#endif // VUELO_H_INCLUDED
