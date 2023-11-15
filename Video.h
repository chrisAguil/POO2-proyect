#ifndef VIDEO_H
#define VIDEO_H

#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Video{
    protected:
        string tipo, genero, 
               nombre, id;
        float calificacion;
        int duracion, numCalificaciones;
        
    public:
        Video(); //constructor default
        Video(string, string, string, string, int, int, float);

       // setters
        virtual void setCalificacion(float);

        // getters
        virtual string getGenero(){return genero;}
        virtual string getTipo(){return tipo;}
        virtual float getCalificacion(){return calificacion;}
        virtual int getNumCalificaciones(){return numCalificaciones;}
        virtual string getId(){return id;}

        // metodos virtuales
        virtual void incrementaCalificacion();
        virtual void imprimeXgenero(vector<shared_ptr<Video>> &, string &);
        virtual void imprimeXcalif(vector<shared_ptr<Video>> &, float&);
        virtual void calificarVideo(float);

        // funcion amiga 
        friend ostream& operator<<(ostream& os, Video& vd);
};

#endif