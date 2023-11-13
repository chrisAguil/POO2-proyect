#include "Pelicula.h"
#include <iostream>
using namespace std;
Pelicula::Pelicula():Video("p","","","",0,0,0.0){}

void Pelicula::imprimeXcalif(vector<Video*> &v, float calif){
    vector<Video*> temporal;
    for (Video* video : v)
    {
        if (video->getCalificacion()==calif)
        {
            temporal.push_back(video);
        }
    }
    for (Video* video : temporal)
    {
        cout<<*video<<endl;
    }
}

void Pelicula::imprimeXgenero(vector<Video*> &v, string &genero){
    vector<Video*> temporal;
    for (Video* video : v)
    {
        if (video->getGenero()==genero)
        {
            temporal.push_back(video);
        }
    }
    for (Video* video : temporal)
    {
        cout<<*video<<endl;
    }
}

