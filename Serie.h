#ifndef SERIE_H
#define SERIE_H
#include <memory>
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
    void imprimeXgenero(vector<shared_ptr<Video>> &, string &genero)override;
    void imprimeXcalif(vector<shared_ptr<Video>> &, float)override;

    friend ostream &operator<<(ostream &os, Serie &s);
};

#endif