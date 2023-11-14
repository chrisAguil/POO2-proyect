#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include <iostream>

using namespace std;

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(string tipo, string nombre, string id, string genero, int duracion, int numCalificaciones, float calificaciones) 
        : Video(tipo, nombre, id, genero, duracion, numCalificaciones, calificacion){};
        friend ostream& operator<<(ostream& os, Pelicula& p){
            os<<"Tipo: "<<p.tipo<<endl;
            os<<"Genero: "<<p.genero<<endl;
            os<<"Nombre: "<<p.nombre<<endl;
            os<<"Id: "<<p.id<<endl;
            os<<"Duracion: "<<p.duracion<<endl;
            os<<"Calificacion: "<<p.calificacion<<endl;
            return os;
        };   
};

#endif
