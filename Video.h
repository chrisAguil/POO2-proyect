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
        Video(string, string, string, string, int, int, float);
       //setters
        void setCalificacion(float);
        //getters
        string getGenero(){return genero;}
        string getTipo(){return tipo;}
        int getCalificacion(){return calificacion;}
        string getId(){return id;}
        //metodos de la clase
        // que sentido tienen los metodos guardadGenero y guardarCalif?
        virtual void imprimeXgenero(vector<shared_ptr<Video>> &, string &);
        virtual void imprimeXcalif(vector<shared_ptr<Video>> &, float&);
        virtual void calificarVideo(vector<shared_ptr<Video>> &, string&, float&);

        //funcion amiga 
        friend ostream& operator<<(ostream& os, Video& vd);
};

#endif