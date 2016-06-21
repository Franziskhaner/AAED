#include "Lista_Vec.h"
#include <iostream>

using namespace std;

struct paciente{
    string codPaciente;
    float gravedad;
};

class hospital{

    public:
        hospital(size_t tamamax1, size_t tamamax2);
        void ingreso(string codigo, float gravedad);
        void alta(string codigo);
        void muerte(string codigo);
        void pacientesUCI() const;
        void pacientesPlanta() const;
        void pacientesGravedad(float gravedad) const:
        ~hospital();

    private:
        Lista<paciente> pacientesUCI_;
        Lista<paciente> pacientesPlanta_;
        int UCImax_;   //tamaño de la UCI.
        int Plantamax_;  //tamaño de la Planta.
};

inline hospital::hospital(size_t tamamax1, size_t tamamax2):
    UCImax_(tamamax1), Plantamax_(tamamax2){}

inline void hospital::ingreso(string cod, float gravedad){

    assert();   //comprobamos que hay sitio en las plantas.

    paciente p; //creo el paciente que voy a ingresar
    p.codPaciente = cod; //con el codigo dado
    p.gravedad = gravedad;  //y la gravedad dada.

    //segun su gravedad lo ingresamos en una planta u otra:

    typename Lista::posicion x;
    paciente aux;

    if(gravedad >=1 || gravedad <=5 && ){   //Si esta entre 1 y 5 ingresara en la UCI
        for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){    //Recorremos la UCI
            aux = pacientesUCI_.elemento(x);    //accedemos al paciente de la posicion actual
            if(p.gravedad<aux.gravedad)     //Si la gravedad del nuevo paciente es menor(mas prioritario) a la del actual,
                pacientesUCI_.insertar(pacientesUCI_.anterior(x), p);   //lo ingresamos una posicion anterior,
            else if(p.gravedad > aux.gravedad)
                pacientesUCI_.insertar(pacientesUCI_.siguiente(x), p);  //si no lo ingresamos detras de éste.
        }
    }
    else if(gravedad >=6 || gravedad <=9){
        pacientesPlanta_.insertar(pacientesPlanta_.primera(), p);
    }

}

inline void hospital::alta(string cod){


    typename Lista::posicion x;
    paciente aux;

    for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){    //Recorremos la UCI
        aux = pacientesUCI_.elemento(x);    //accedemos al paciente de la posicion actual
        if(cod==aux.codPaciente)    //buscamos el paciente que coincida con el codigo dado
            pacientesUCI_.eliminar(x);     //si lo encontramos eliminamos al paciente de la planta, es decir, se le da de alta.
    }

}

inline void hospital::muerte(string cod){

    typename Lista::posicion x;
     paciente aux;

    for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){    //Recorremos la UCI
        aux = pacientesUCI_.elemento(x);    //accedemos al paciente de la posicion actual
        if(aux.codPaciente==cod)    //buscamos el paciente que coincida con el codigo dado
            aux.gravedad=0;     //si lo encontramos ponemos su gravedad a 0 es decir, ha muerto.
    }
    //Ahora hay que disminuir en una posicion todos los pacientes a partir del que ha muerto, pues hay una posicion libre en dicha planta.


}

inline void hospital::pacientesUCI() const{

    typename Lista::posicion x;
    paciente aux;
    int cont=1;

    cout << "Pacientes ingresados en UCI:" << endl;

    for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){
        aux = pacientesUCI_.elemento(x);
        cout << "Paciente nº " << cont << endl;
        cout << "Codigo del paciente: " << aux.codPaciente << "\n" << "Gravedad del paciente:" << aux.gravedad << endl;
        cont++;
    }

}

inline void hospital::pacientesPlanta() const{

    typename Lista::posicion x;
    paciente aux;
    int cont=1;

    cout << "Pacientes ingresados en UCI:" << endl;

    for(x = pacientesPlanta_.primera(); x!= pacientesPlanta_.fin(); x=pacientesPlanta_.siguiente(x)){
        aux = pacientesPlanta_.elemento(x);
        cout << "Paciente nº " << cont << endl;
        cout << "Codigo del paciente: " << aux.codPaciente << "\n" << "Gravedad del paciente:" << aux.gravedad << endl;
        cont++;
    }
}

inline void hospital::pacientesGravedad(float gravedad) const{

    typename Lista::posicion x;
    paciente aux;

    for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){    //Recorremos la UCI
        aux = pacientesUCI_.elemento(x);    //accedemos al paciente de la posicion actual
        if(gravedad==aux.gravedad)    //buscamos el paciente que coincida con la gravedad dada
            cout << "Codigo del paciente: " << aux.codPaciente << "\n" << "Gravedad del paciente:" << aux.gravedad << endl;  //si lo encontramos lo mostramos por pantalla.
    }

    for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){    //Recorremos la Planta
        aux = pacientesUCI_.elemento(x);    //accedemos al paciente de la posicion actual
        if(gravedad==aux.gravedad)    //buscamos el paciente que coincida con la gravedad dada
            cout << "Codigo del paciente: " << aux.codPaciente << "\n" << "Gravedad del paciente:" << aux.gravedad << endl;  //si lo encontramos lo mostramos por pantalla.
    }

}

inline hospital::~hospital(){

    typename Lista::posicion x;

    for(x = pacientesUCI_.primera(); x!= pacientesUCI_.fin(); x=pacientesUCI_.siguiente(x)){   //eliminamos a todos los pacientes de la UCI.
        pacientesUCI_.eliminar(x);
    }

    for(x = pacientesPlanta_.primera(); x!= pacientesPlanta_.fin(); x=pacientesPlanta_.siguiente(x)){   //eliminamos a todos los pacientes de la planta.
        pacientesPlanta_.eliminar(x);
    }
}
