#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include <iostream>

using namespace std;

class Pelicula:public Video
{
    public:
        Pelicula();
        // constructor con parametros
        Pelicula(string tipo, string nombre, string id, string genero, int duracion, int numCalificaciones, float calificaciones) 
        : Video(tipo, nombre, id, genero, duracion, numCalificaciones, calificacion){};           
};

#endif