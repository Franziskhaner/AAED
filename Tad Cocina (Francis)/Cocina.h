#include "Lista_Vec.h"

typedef struct mueble{
    int anchura;
}

class Cocina{

    public:
        Cocina();
        bool comprobar(const mueble&, int p);
        void añadir_mueble(const mueble&, int p);
        mueble devolver_mueble(int pos);
        void eliminar_mueble(int pos);
        void mover_mueble(int pos);
        ~cocina();

    private:
        Lista<mueble> L;
        int Lmax_;   //longitud de la cocina
        typename Lista<mueble>::posicion buscar(int posicion); //funcion auxiliar que nos convierte una posicion de tipo int(dada por el
                                                            //usuario del TAD Cocina) a un tipo 'posicion' del TAD Lista.
};

//funcion buscar

typename Lista<mueble>::posicion Cocina::buscar(int pos){

    typename Lista<mueble>::posicion x = L.primera();

    for(int i=0; i < pos; i++){
        x = L.siguiente(x);
    }

}
inline Cocina::Cocina(size_t tamamax):Lmax_(tamamax){}

inline bool Cocina::comprobar(const mueble& m, int p){

    typename Lista<mueble>::posicion x = cocina::buscar(p); //guardamos en x la posicion de la lista que ocupa el mueble dado en la cocina
                                                    //a traves de la posicion que nos da el suario a traves de la funcion
    mueble n = L.elemento(x);

    return(m.anchura <= n.anchura);

}

inline void Cocina::añadir_mueble(const mueble& m, int p){

    bool aux;

    aux = cocina::comprobar(m, p);

    typename Lista<mueble>::posicion x = c.buscar(p);

    if(aux)
         L.insertar(m, x);
}

inline mueble Cocina::devolver_mueble(int pos){

    assert(pos <= Lmax_);   //Comprobamos que la posicion dada esta dentro del tamño de nuestra cocina.

    typename Lista<mueble>::posicion x = cocina::buscar(p);

    return L.elemento(x);

}


inline void Cocina::eliminar(int pos){

    assert(pos <= Lmax_);

    typename Lista<mueble>::posicion x = cocina::buscar(p);

    L.eliminar(x);

}

inline void Cocina::mover_mueble(int pos){

    assert(pos <= Lmax_);
    typename Lista<mueble>::posicion x = cocina::buscar(p);

    mueble m = L.elemento(x);
    bool aux = cocina::comprobar(m, pos-1);

    if(aux)
        cocina::añadir_mueble(m, pos-1);


}

inline Cocina::~Cocina(){

    for(typename Lista<mueble>::posicion x = L.primera(); x != L.fin(); x = L.siguiente(x)){
        L.eliminar(x);
    }
}

#endif
