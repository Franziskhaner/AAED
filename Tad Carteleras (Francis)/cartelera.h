#include "Lista_Enla.h"

typedef int espectaculo;

struct sala{

    Lista<espectaculo> espectaculos;
};

class carteleras{

    public:
        cartelera(){}
        void añadirSala(sala s);
        void añadirEspectaculo(espectaculo e, sala s);
        void eliminarSala(sala s);
        void eliminarEspectaculo(espectaculo e, sala s);
        Lista<sala> mostrarSala() const;
        Lista<espectaculo> mostrarEspectaculo(sala s) const;
        Lista<espectaculo> mostrarTotalEspectaculos() const;
        Lista<sala> mostrarTotalcartelera() const;
        //funciones auxiliares para comprobar que existen una sala y un espectaculo.
        bool haySala(sala s);
        bool hayEspectaculo(especatulo e, sala s);

    private:
        Lista<sala> cartelera;

};

bool carteleras::haySala(sala s){

    typename Lista<sala>::posicion x;
    for(x=cartelera.primera(); x!=cartelera.fin();x=cartelera.siguiente()){
        if(s == cartelera.elemento(x))
            return true;
    }
    return false;
}

bool carteleras::hayEspectaculo(espectaculo e, sala s){

    typename Lista<sala>::posicion x;
    typename Lista<Lista<espectaculo>>::posicion y;

    for(x=cartelera.primera(); x!=cartelera.fin();x=cartelera.siguiente())
        if(s == cartelera.elemento(x))  //si dicha sala existe, buscamos en su lista de espectaculos el espectaculo pasado:
            for(y=s.espectaculos.primera(); y!=s.espectaculos.fin(); y=s.espectaculos.siguiente())
                if(e == s.espectaculos.elemento(x))
                    return true;

    return false;
}

void carteleras::añadirSala(sala s){

    if(!haySala(s)) //si la sala no existe de antemano la añadimos a nuestra cartelera
        cartelera.insertar(s, cartelera.fin());

}

void carteleras::añadirEspectaculo(espectaculo e, sala s){

    if(!hayEspectaculo(e, s))   //si no existe el espectaculo en dicha sala lo añadimos
        s.espectaculos.insertar(e, s.espectaculos.fin());

}

void carteleras::eliminarSala(sala s){

    if(haySala(s)){
        typename Lista<sala>::posicion x = cartelera.buscar(s); //obtenemos la poscion de dicha sala en la lista con la funcion buscar().
        cartelera.eliminar(x);
    }

}

void carteleras::eliminarEspectaculo(espectaculo e, sala s){

    if(hayEspectaculo(e, s)){
        typename Lista<sala>::posicion x = s.espectaculos.buscar(e); //obtenemos la posicion del espectaculo en dicha sala
        s.espectaculos.eliminar(x);
    }
}

Lista<sala> carteleras::mostrarSala() const{

    return cartelera;   //devolvemos la lista de salas del sistema.
}

Lista<espectaculo> carteleras::mostrarEspectaculo(sala s) const{

    if(haySala(s)){
        return s.espectaculos;
    }
    else{
        sala a;    //Si la sala pasada no existe creamos una sala vacia y la devolvemos
        return a.espectaculos;
    }
}

Lista<espectaculo> carteleras::mostrarTotalEspectaculos() const{

    sala.espectaculos esp;  //creamos una lista de espectaculos para almacenar el conjunto de espectaculos de todas las salas.

    typename Lista<sala>::posicion x;
    typename Lista<Lista<espectaculo>>::posicion y;

    for(x=cartelera.primera(); x!=cartelera.fin(); x=cartelera.siguiente(x)){
        sala s = cartelera.elemento(x);
        for(y=s.espectaculos.primera(); y!=s.espectaculos.fin(); y=s.espectaculos.siguiente(y)){
            espectaculo e = s.espectaculos.elemento(y);
            if(hayEspectaculo(e, y))
                esp.añadirEspectaculo(e, s);
        }
    }


    return esp; //devolvemos la lista de espectaculos.
}

Lista<sala> carteleras::mostrarTotalcartelera() const{

    cartelera c;    //creamos una cartelera que contendra la lista de salas q ofertan al menos un espectaculo.
    typename Lista<sala>::posicion x;
    typename Lista<Lista<espectaculo>>::posicion y;

    for(x=cartelera.primera(); x!=cartelera.fin(); x=cartelera.siguiente(x)){
        sala s = cartelera.elemento(x);
        for(y=s.espectaculos.primera(); y!=s.espectaculos.fin(); y=s.espectaculos.siguiente(y)){
            espectaculo e = s.espectaculos.elemento(y);
            if(hayEspectaculo(e, y))
                c.añadirSala(s);
        }
    }
    return c;   //devolvemos la lista de salas.
}
