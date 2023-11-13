#include "Video.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//constructor default inicializado con el constructor con parametros
Video::Video():Video("v","","","",0,0,0.0){}
//constructor con parametros
Video::Video(string tipo, string genero, string nombre, string id, int duracion, int numCalificaciones, float calificacion):Video(){
    this->tipo=tipo;
    this->genero=genero;
    this->nombre=nombre; 
    this->id=id;
    setCalificacion(calificacion);
    this->duracion=duracion;
    this->numCalificaciones=numCalificaciones;
}

// bloque de setters
void Video::setCalificacion(float calificacion){
    // verificamos que la calificacion este entre 0 y 5
    if(0<calificacion<=5){
        this->calificacion=calificacion;
    }
    else{ 
        this->calificacion=0;
        cout<<"Ingresa un valor valido"<<endl;
    }
}
// metodos de la clase
void Video::imprimeXgenero(vector<Video*> &v, string &genero){
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

void Video::imprimeXcalif(vector<Video*> &v, float calif){
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

void Video::calificarVideo(vector<Video*> &v, string id, float calificacion){
    if (calificacion > 1 && calificacion < 5){
        for (Video *i : v)
        {
            if(i->id==id){
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
    os<<v.id<<","<<v.nombre<<","<<v.duracion<<","<<v.genero<<v.calificacion;
    return os;
}
