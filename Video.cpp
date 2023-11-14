#include "Video.h"
#include <memory>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//constructor default inicializado con el constructor con parametros
Video::Video():Video("v","","","",0,0,0.0){}
// constructor con parametros
Video::Video(string tipo, string nombre, string id, string genero, int duracion, int numCalificaciones, float calificacion){
    this->tipo=tipo;
    this->nombre=nombre;
    this->id=id;
    this->genero=genero;
    this->duracion=duracion;
    this->numCalificaciones=0;
    this->calificacion=0.0;
}
// bloque de setters
void Video::setCalificacion(float calificacion){
    // verificamos que la calificacion este entre 0 y 5
    if(calificacion >= 0 && calificacion <= 5)
    {
        this->calificacion=calificacion;
    }
    else{ 
        this->calificacion=0;
        cout<<"Ingresa un valor valido"<<endl;
    }
}
// metodos de la clase
void Video::imprimeXgenero(vector<shared_ptr<Video>> &v, string &genero){
    for (auto& video : v)
    {
        if (video->getGenero() == genero)
        {
            cout<<*video<<endl;
        }
    }
}

void Video::imprimeXcalif(vector<shared_ptr<Video>> &v, float &calif){
    for (auto& video : v)
    {
        if (video->getCalificacion() == calif)
        {
            cout<<*video<<endl;
        }
    }
}

void Video::calificarVideo(vector<shared_ptr<Video>> &v, string &id, float &calificacion){
    if (calificacion >= 1 && calificacion <= 5){
        for (auto& i : v)
        {
            if(i->id == id)
            {
                int califPromedio=i->calificacion;
                int cont=i->numCalificaciones;
                float promedio= round((califPromedio*cont+calificacion)/(cont+1));
                
                i->calificacion=promedio;
                i->numCalificaciones++;
                return;
            }
            cout<<"Id no encontrado"<<endl;
        }
    }
    cout << "valor invalido" << endl;
}

ostream &operator<<(ostream &os, Video &v){
    os<<v.id<<","<<v.nombre<<","<<v.duracion<<","<<v.genero<<","<<v.calificacion;
    return os;
}
