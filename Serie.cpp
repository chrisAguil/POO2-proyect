#include "Serie.h"

#include <iostream>

using namespace std;

Serie::Serie():Serie("s","",0,"",0.0,"",0,"",""){}

Serie::Serie():Serie("s","",0,"",0.0,"",0,"",""){}

Serie::Serie(string tipo, string nombre, int duracion, string genero, float calificacion, string id, int numCalificaciones, string serie, string episodio):Video(tipo, genero, nombre, id, duracion, numCalificaciones, calificacion)
{
    this->tipo=tipo;
}

ostream &operator<<(ostream &os, Serie &s) 
{
    os<<s.id<<","<<s.nombre<<","<<s.duracion<<","<<s.genero<<",["<<s.serie<<", "<<s.episodio<<"]"<<s.calificacion;
    return os;
}