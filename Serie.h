#ifndef SERIE_H
#define SERIE_H
#include <vector>
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
    void imprimeXgenero(vector<Video*> &, string &genero)override;
    void imprimeXcalif(vector<Video*> &, float)override;

    friend ostream &operator<<(ostream &os, Serie &s);
};

#endif