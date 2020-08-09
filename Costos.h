#ifndef COSTOS_H_INCLUDED
#define COSTOS_H_INCLUDED

class Costo{
    private:
        Vertice * vertice;
        int costo;
    public:
        Costo(Vertice *vertice, int costo);
        ~Costo();
        Vertice * get_vertice();
        void set_vertice(Vertice* vertice);
        int get_costo();
        void set_costo(int costo);
};

Costo::Costo(Vertice *vertice, int costo){
    this->vertice = vertice;
    this->costo = costo;
}

Costo::~Costo(){
    delete vertice;
}

Vertice * Costo::get_vertice(){
    return this->vertice;
}

void Costo::set_vertice(Vertice* vertice){
    this->vertice = vertice;
}

int Costo::get_costo(){
    return this->costo;
}

void Costo::set_costo(int costo){
    this->costo = costo;
}


#endif // COSTOS_H_INCLUDED
