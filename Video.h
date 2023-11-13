#ifndef VIDEO_H
#define VIDEO_H

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
        Video(string, string, string, string, int, int, float); //constructor con parametors
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
        virtual void imprimeXgenero(vector<Video*> &, string &genero) = 0;
        virtual void imprimeXcalif(vector<Video*> &, float) = 0;
        virtual void calificarVideo(vector<Video*> &, string, float);

        //funcion amiga 
        friend ostream& operator<<(ostream& os, Video& vd);
};

#endif