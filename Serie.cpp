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
void Serie::imprimeXcalif(vector<Video*> &v, float calif){
    vector<Video> temporal;
    for (Video* video : v)
    {
        if (video->getCalificacion()==calif)
        {
            temporal.push_back(*video);
        }
    }
    for (Video video : temporal)
    {
        cout<<video<<endl;
    }
}
void Serie::imprimeXgenero(vector<Video*> &v, string &genero){
    vector<Video> temporal;
    for (Video* video : v)
    {
        if (video->getGenero()==genero)
        {
            temporal.push_back(*video);
        }
    }
    for (Video video : temporal)
    {
        cout<<video<<endl;
    }
}
