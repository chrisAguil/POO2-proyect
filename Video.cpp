#include "Video.h"
#include <memory>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// -----------------------------------------------------------------
// Constructor default inicializa los atributos con 
// valores por default pasados con ayuda del constructor 
// con parametros
// -----------------------------------------------------------------

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
    setCalificacion(calificacion);
    this->numCalificaciones = 0;
    // utilizamos set para validar la calificacion
    setCalificacion(calificacion);
}

// ----------------------------------
// Sett para validar la calificacion
// ----------------------------------


// ----------------------------------
// Sett para validar la calificacion
// ----------------------------------

void Video::setCalificacion(float calificacion){
    // verificamos que la calificacion este entre 0 y 5
    if(calificacion >= 0 && calificacion <= 5)
    {
    if(calificacion >= 0 && calificacion <= 5)
    {
        this->calificacion=calificacion;
    }
    else
    { 
    else
    { 
        this->calificacion=0;
        cout<<"Ingresa un valor valido"<<endl;
    }
}

// ------------------------------
// Metodos virtuales
// ------------------------------

// metodo para imprimir videos por genero

// ------------------------------
// Metodos virtuales
// ------------------------------

// metodo para imprimir videos por genero
void Video::imprimeXgenero(vector<shared_ptr<Video>> &v, string &genero){
    // recorremos el vector
    // recorremos el vector
    for (auto& video : v)
    {
        if (video->getGenero() == genero)
        {
            // se imprime el video con ayuda del operador sobrecargado
            // se imprime el video con ayuda del operador sobrecargado
            cout<<*video<<endl;
        }
    }
}

// metodo para imprimir videos por calificacion
void Video::imprimeXcalif(vector<shared_ptr<Video>> &v, float &calif){ 
    // recorremos el vector
// metodo para imprimir videos por calificacion
void Video::imprimeXcalif(vector<shared_ptr<Video>> &v, float &calif){ 
    // recorremos el vector
    for (auto& video : v)
    {
        if (video->getCalificacion() == calif)
        {
            // se imprime el video con ayuda del operador sobrecargado
            // se imprime el video con ayuda del operador sobrecargado
            cout<<*video<<endl;
        }
    }
}

// metodo para calificar videos
// metodo para calificar videos
void Video::calificarVideo(vector<shared_ptr<Video>> &v, string &id, float &calificacion){
    // se vuelve a validar la calificacion
    if (calificacion >= 1 && calificacion <= 5)
    {
        // recorremos el vector
    // se vuelve a validar la calificacion
    if (calificacion >= 1 && calificacion <= 5)
    {
        // recorremos el vector
        for (auto& i : v)
        {
            if(i->id == id)
            {
                int califPromedio=i->calificacion;
                int cont=i->numCalificaciones;
                float promedio= round((califPromedio*cont+calificacion)/(cont+1));
                
                // se asigna el promedio al video
                // se asigna el promedio al video
                i->calificacion=promedio;
                // se aumenta el numero de calificaciones
                // se aumenta el numero de calificaciones
                i->numCalificaciones++;
                return;
            }
            else
            {
                // si no se encuentra el id el video no existe
                cout<<"Id no encontrado"<<endl;
                break;
            }
            else
            {
                // si no se encuentra el id el video no existe
                cout<<"Id no encontrado"<<endl;
                break;
            }
        }
    }
    cout << "valor invalido" << endl;
}

// ------------------------------
// Sobrecarga de operador
// ------------------------------

// ------------------------------
// Sobrecarga de operador
// ------------------------------

ostream &operator<<(ostream &os, Video &v){
    // se imprime el video
    // se imprime el video
    os<<v.id<<","<<v.nombre<<","<<v.duracion<<","<<v.genero<<","<<v.calificacion;
    return os; // se regresa el objeto ostream
    return os; // se regresa el objeto ostream
}