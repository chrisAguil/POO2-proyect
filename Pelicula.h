#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
#include <string>

using namespace std;

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(string, string, string, string, int, int, float) : Video(tipo, genero, nombre, id, duracion, numCalificaciones, calificacion){};
};

#endif
