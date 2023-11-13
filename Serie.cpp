#include "Serie.h"
#include <string>
#include <iostream>
using namespace std;

using namespace std;

Serie::Serie(string tipo, string nombre, int duracion, string genero, float calificacion, string id, int numCalificaciones, string serie, string episodio):Video(tipo, genero, nombre, id, duracion, numCalificaciones, calificacion){
    this->tipo=tipo;
}
Serie::Serie():Serie("s","",0,"",0.0,"",0,"",""){}


ostream &operator<<(ostream &os, Serie &s) 
{
    os<<s.id<<","<<s.nombre<<","<<s.duracion<<","<<s.genero<<",["<<s.serie<<", "<<s.episodio<<"]"<<s.calificacion;
    return os;
}
void Serie::imprimeXcalif(vector<unique_ptr<Video>> &v, float calif){
    for (auto& video : v)
    {
        if (video->getCalificacion()==calif)
        {
            cout << *video << endl;
        }
    }
}
void Serie::imprimeXgenero(vector<unique_ptr<Video>> &v, string &genero){
    for (auto& video : v)
    {
        if (video->getGenero()==genero)
        {
            cout << *video << endl;
        }
    }
}
