#ifndef VIDEO_H
#define VIDEO_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

class Video{
    protected:
        string tipo, genero, nombre, id;
        float calificacion;
        int duracion, numCalificaciones;
    public:
        Video(); //constructor default
        Video(string, string, string, string, int, int, float)
        : tipo(tipo), genero(genero), nombre(nombre), id(id), duracion(duracion), numCalificaciones(numCalificaciones), calificacion(calificacion) {}; //constructor con parametors
        //setters
        void setCalificacion(float);
        //getters
        // haz un getter para id 
        string getGenero(){return genero;}
        string getTipo(){return tipo;}
        int getCalificacion(){return calificacion;}
        string getId(){return id;}
        //metodos de la clase
        // que sentido tienen los metodos guardadGenero y guardarCalif?
        virtual void imprimeXgenero(vector<unique_ptr<Video>> &, string &genero) = 0;
        virtual void imprimeXcalif(vector<unique_ptr<Video>> &, float) = 0;
        virtual void calificarVideo(vector<unique_ptr<Video>> &, string, float);

        //funcion amiga 
        friend ostream& operator<<(ostream& os, Video& vd);
};

#endif