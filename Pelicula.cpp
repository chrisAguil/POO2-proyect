#include "Pelicula.h"
#include <memory>
#include <iostream>
using namespace std;
Pelicula::Pelicula():Video("p","","","",0,0,0.0){}

void Pelicula::imprimeXcalif(vector<unique_ptr<Video>> &v, float calif){
    for (auto& video : v)
    {
        if (video->getCalificacion()==calif)
        {
            cout<<*video<<endl;
        }
    }
}

void Pelicula::imprimeXgenero(vector<unique_ptr<Video>> &v, string &genero){
    for (auto& video : v)
    {
        if (video->getGenero()==genero)
        {
            cout << *video << endl;
        }
    }
}

