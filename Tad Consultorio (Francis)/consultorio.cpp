#include "Lista_Enla.h"
#include "Cola_Enla.h"

typedef string paciente;

struct medico{
    string codMed;
    Cola<paciente> Pacientes;

};

class consultorio{

    public:

        consultorio(){}
        void altaMedico(medico m);
        void bajaMedico(medico m);
        void listaEspera(paciente p, medico m);
        paciente consultarPaciente (medico m) const;
        void atenderPaciente(paciente p);
        bool comprobarPacientes (medico m);
        //funciones auxiliares
        bool comprobarMedico(medico m); //comprueba que un medico esta dado de alta en el sistema.


    private:
        Lista<medico> listaMedicos;

}

bool consultorio::comprobarMedico(medico m){

    typename Lista<medico>::posicion x;

    for(x=listaMedicos.primera(); x!=listaMedicos.fin(); x = listaMedicos.siguiente(x)){
        medico aux = listaMedicos.elemento(x);
        if(aux.codMed == m.codMed)
            return true;
    }
    return false;
}

void consultorio::altaMedico(medico m){

    if(!comprobarMedico(m))
        listaMedicos.insertar(m, listaMedicos.fin());

}

void consultorio::bajaMedico(medico m){

    if(comprobarMedico(m)){
        typename Lista<medico>::posicion x;
        x=listaMedicos.buscar(m);   //buscamos la posicion del medico indicado en nuestra lista de medicos.
        listaMedicos.eliminar(x);
    }
}

void consultorio::listaEspera(paciente p, medico m){

    if(comprobarMedico(m))
        m.Pacientes.push(p);

}

paciente consultorio::consultarPaciente(medico m) const{

    if(comprobarMedico(m)&& comprobarPacientes(m)  //comprobamos que existe el medico y su cola de pacientes no esta vacia
        return m.Pacientes.frente();   //obtenemos el paciente que esta al principio de la cola de espera dicho medico.

}

void consultorio::atenderPaciente(paciente p){

    typename Lista<medico>::posicion x=listaMedicos.primera();

    while(x!=listaMedicos.fin()){   //recorremos la lista de medicos
        medico m = listaMedicos.elemento(x);
        if(comprobarPacientes(m)){    //si el medico tiene al menos un paciente en la cola(no esta vacia)
            paciente aux = consultarPaciente(m);    //guardamos en aux el paciente que esta al frente de la cola para ser atendido
            if(aux == p)  //si el nombre del paciente a consultar(p) coincide con el paciente del frente(aux) entonces
                m.Pacientes.pop();  //lo atendemos
        }

        x=listaMedicos.siguiente(x);
    }

}

bool consultorio::comprobarPacientes(medico m){

    if(comprobarMedico(m))
        return !(m.Pacientes.vacia());  //si la cola no esta vacia devolvemos true.
}

