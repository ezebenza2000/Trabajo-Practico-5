#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

class Vuelo{
    private:
        int precio = 0;
        int tiempo = 0;

    public:
        Vuelo(int precio, int tiempo);
        void set_precio(int precio);
        int get_precio();
        void set_tiempo(int tiempo);
        int get_tiempo();
};
#endif // VUELO_H_INCLUDED
