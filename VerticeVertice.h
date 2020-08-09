#ifndef VERTICES_H_INCLUDED
#define VERTICES_H_INCLUDED

class VerticeVertice{
    private:
        Vertice * primero;
        Vertice * segundo;
    public:
        VerticeVertice(Vertice * primero, Vertice * segundo);
        ~VerticeVertice();
        void set_primero(Vertice * primero);
        void set_segundo(Vertice * segundo);
        Vertice* get_primero();
        Vertice* get_segundo();
};

VerticeVertice::VerticeVertice(Vertice * primero, Vertice * segundo){
    this->primero = primero;
    this->segundo = segundo;
}

VerticeVertice::~VerticeVertice(){
    primero = 0;
    delete primero;
    segundo = 0;
    delete segundo;
}


void VerticeVertice::set_primero(Vertice * primero){
    this->primero = primero;
}


void VerticeVertice::set_segundo(Vertice * segundo){
    this->segundo = segundo;
}


Vertice* VerticeVertice::get_primero(){
    return this->primero;
}


Vertice* VerticeVertice::get_segundo(){
    return this->segundo;
}


#endif // VERTICES_H_INCLUDED
