#include "Video.h"
#include "util.h"
#include <stdexcept>
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------
// Constructor default inicializa los atributos con 
// valores por default pasados con ayuda del constructor 
// con parametros
// -----------------------------------------------------------------

Video::Video():Video("v","","","",0,0,0.0){}

// ------------------------------
// Constructor con parametros
// ------------------------------

Video::Video(string tipo, string nombre, string id, string genero, int duracion, int numCalificaciones, float calificacion)
{
    // inicializamos los atributos
    this->tipo=tipo;
    this->nombre=nombre;
    this->id=id;
    this->genero=genero;
    this->duracion=duracion;
    this->numCalificaciones = 0;
    // utilizamos set para validar la calificacion
    this->calificacion = calificacion;
}

// ----------------------------------
// Sett para validar la calificacion
// ----------------------------------

void Video::setCalificacion(float calificacionPasada){
    // verificamos que la calificacion este entre 0 y 5
    if(calificacionPasada >= 0 && calificacionPasada <= 5)
    {
        if(numCalificaciones == 0) {
            calificacion = calificacionPasada;
            incrementaCalificacion();
        } else {
            float califPromedio = getCalificacion(); 
            int cont = getNumCalificaciones();
            float promedio = (califPromedio*cont+calificacionPasada)/(cont+1);
            calificacion = promedio;
            incrementaCalificacion();
        }
    }
    else if (numCalificaciones == 0)
    {
        calificacion = 0.0;
    }
    else
    { 
        throw std::invalid_argument("Calificacion invalida");
    }
}

// ------------------------------
// Metodos virtuales
// ------------------------------

void Video::incrementaCalificacion(){
    numCalificaciones++;
}

// metodo para imprimir videos por genero
void Video::imprimeXgenero(vector<shared_ptr<Video>> &v, string &genero){
    // recorremos el vector
    for (auto& video : v)
    {
        // si el genero del video es igual al genero que se busca
        if (video->getGenero()==genero)
        {
            // se imprime el video con ayuda del operador sobrecargado
            cout<<*video<<endl;
        }
    }
}

// metodo para imprimir videos por calificacion
void Video::imprimeXcalif(vector<shared_ptr<Video>> &v, float &calif){ 
    // recorremos el vector
    for (auto& video : v)
    {
        // si la calificacion del video es igual a la calificacion que se busca
        if (video->getCalificacion()==calif)
        {
            // se imprime el video con ayuda del operador sobrecargado
            cout<<*video<<endl;
        }
    }
}

// metodo para calificar videos
void Video::calificarVideo(float calificacion){
    cout << "Inicializando calificacion" << endl << endl;

    if (calificacion >= 0 && calificacion <= 5)
    {
            string videoId = getId();
            trim(videoId);
            trim(id);
            if(videoId == id)
            {
                // se asigna el promedio al video
                setCalificacion(calificacion);
                // se aumenta el numero de calificaciones
                cout << "Calificacion agregada" << endl << endl;
                return;
            }
    }
    else{
        cout<<" estoy orgulloso de ti por este proyecto Chris "<<endl;
    }
}

// ------------------------------
// Sobrecarga de operador
// ------------------------------

ostream &operator<<(ostream &os, Video &v){
    // se imprime el video
    os<<v.id<<","<<v.nombre<<","<<v.duracion<<","<<v.genero<<","<<v.calificacion;
    return os; // se regresa el objeto ostream
}