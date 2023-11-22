#include "Serie.h"

#include "util.h"

#include <iostream>

using namespace std;

Serie::Serie(string tipo, string nombre, int duracion, string genero, float calificacion, string id, int numCalificaciones, string serie, string episodio)
{
    this->id=id;
    this->tipo=tipo;
    this->nombre=nombre;
    this->duracion=duracion;
    this->genero=genero;
    this->numCalificaciones=numCalificaciones;
    this->serie=serie;
    this->episodio=episodio;
    this->calificacion=calificacion; 
    this->numEpisodio = 0;
}
Serie::Serie():Serie("s","",0,"",0.0,"",0,"",""){}

void Serie::incrementaCalificacion() 
{
    numEpisodio++;
}

void Serie::calificarVideo(float calificacionPasada) 
{
    cout << "Inicializando calificacion" << endl << endl;

    if (calificacionPasada >= 0 && calificacionPasada <= 5)
    {
            string serieId = getId();
            trim(serieId);
            trim(id);
            if(serieId == id)
            {
                // se asigna el promedio al video
                setCalificacion(calificacionPasada);
                // se aumenta el numero de calificaciones
                cout << "Calificacion agregada" << endl << endl;
                return;
            }
    }
    else{
        cout << "Calificacion invalida" << endl << endl;
    }
}

void Serie::setCalificacion(float calificacionPasada) 
{
    // verificamos que la calificacion este entre 0 y 5
    if(calificacionPasada >= 0 && calificacionPasada <= 5)
    {
        if(numEpisodio == 0) {
            calificacion = calificacionPasada;
            incrementaCalificacion();
        } 
        else 
        {
            float califPromedio = getCalificacion(); 
            int cont = getNumCalificaciones();
            float promedio = (califPromedio*cont+calificacionPasada)/(cont+1);
            calificacion = promedio;
            incrementaCalificacion();
        }
    }
    else if (numEpisodio == 0)
    {
        calificacion = 0.0;
        incrementaCalificacion();
    }
    else
    {
        throw invalid_argument("La calificacion debe estar entre 0 y 5");
    }
}

ostream &operator<<(ostream &os, Serie &s) 
{
    os<<s.id<<","<<s.nombre<<","<<s.duracion<<","<<s.genero<<",["<<s.serie<<", "<<s.episodio<<"]"<<s.calificacion;
    return os;
}

// observaciones:   no se estan calificacndo correctamente las series
//                  imprimir por calif no funciona como se espera