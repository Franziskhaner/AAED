template <typename T>
struct Vagon{
    T elemento;
};

class tren(){

    public:
        tren();
        void desp_izq();
        void desp_der();
        void eliminar();
        void insertar(Vagon v);
        Vagon& observar();
        const Vagon& observar() const;
        bool vacio() const;

    private:
        Pila<Vagon> p1, p2;
}

tren::tren(){}

void tren::desp_izq(){

    p2.push(p1.tope())
    p1.pop();
    if(p1.vacia()){
       p1.push(p2.tope());
       p2.pop();
    }

}

void tren::desp_der(){

    if(!p2.vacia()){
        p1.push(p2.tope());
        p2.pop();
    }
}

void tren::eliminar(){

    assert(!p1.vacia());
    p1.pop();
    if(p1.vacia()){
        if(!p2.vacia()){
            p1.push(p2.tope());
            p2.pop();
        }
    }
}

void tren::insertar(Vagon v){

    p1.push(v);
}

Vagon& tren::observar(){

    return p1.tope();
}

const Vagon& tren::observar() const{

    return p1.tope();
}

bool tren::vacio() const{

    return(p1.vacia());
}


