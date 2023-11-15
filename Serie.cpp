#include "Serie.h"

#include <iostream>

using namespace std;

Serie::Serie(string tipo, string nombre, int duracion, string genero, float calificacion, string id, int numCalificaciones, string serie, string episodio)
{
    this->id=id;
    this->tipo=tipo;
    this->nombre=nombre;
    this->duracion=duracion;
    this->genero=genero;
    this->numCalificaciones=numCalificaciones;
    this->serie=serie;
    this->episodio=episodio;
    setCalificacion(calificacion);
}
Serie::Serie():Serie("s","",0,"",0.0,"",0,"",""){}


ostream &operator<<(ostream &os, Serie &s) 
{
    os<<s.id<<","<<s.nombre<<","<<s.duracion<<","<<s.genero<<",["<<s.serie<<", "<<s.episodio<<"]"<<s.calificacion;
    return os;
}