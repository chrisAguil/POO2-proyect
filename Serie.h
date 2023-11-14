#ifndef SERIE_H
#define SERIE_H

#include "Video.h"

using namespace std;

class Serie: public Video
{
protected:
    string serie, episodio;
public:
    Serie(string tipo, string nombre, int duracion, string genero, float calificacion, string id, int numCalificaciones, string serie, string episodio);
    Serie();
    // sobre escribir el metodo imrpimeXCalif

    friend ostream &operator<<(ostream &os, Serie &s);
};

#endif