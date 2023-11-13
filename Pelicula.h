#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(string, string, string, string, int, int, float) : Video(tipo, genero, nombre, id, duracion, numCalificaciones, calificacion){};
        void imprimeXgenero(vector<unique_ptr<Video>> &videos, string &genero) override;
        void imprimeXcalif(vector<unique_ptr<Video>> &videos, float) override;

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
