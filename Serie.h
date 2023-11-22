#ifndef SERIE_H
#define SERIE_H

#include "Video.h"

using namespace std;

class Serie: public Video
{
protected:
    string serie, 
           episodio;
    int numEpisodio;

public:
    Serie(string tipo, string nombre, 
          int duracion, string genero, 
          float calificacion, string id, 
          int numCalificaciones, 
          string serie, string episodio);
    Serie();
    // sobre escribir el metodo 
    void incrementaCalificacion() override;
    void calificarVideo(float) override;
    void setCalificacion(float) override;
    int getNumCalificaciones() override {return numEpisodio;}

    friend ostream &operator<<(ostream &os, Serie &s);
};

#endif
// 360 lineas de codigo