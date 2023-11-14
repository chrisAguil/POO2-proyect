#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "Serie.h"
#include "Video.h"
#include "Pelicula.h"

using namespace std;

int main(){
    // debo de sacar los datos de un archivo de texto
    // y guardarlos en un vector de objetos de tipo Video

    bool continuar = true; // bandera para continuar en el menu
    string id; // id del video a calificar
    float calif; // calificacion del video a calificar

    // hacer dos vectores uno de series y otro de peliculas
    string genero; // genero del video a imprimir
    int opcion = 3; // opcion del menu
    string linea; // linea del archivo
    ifstream archivo; // archivo de texto

    vector<shared_ptr<Video>> videos;

    archivo.open("peliculas.txt");

    if(archivo.is_open())
    {
        while(getline(archivo, linea))
        { // lee una linea del archivo
            
            istringstream iss(linea); // separa la linea en palabras
            
            string tipo, nombre, genero, id, duracion_str;
            int duracion, numCalificaciones = 0;
            float calificacion = 0; 

            if(!(iss >> tipo >> id >> nombre >> duracion_str >> genero)) // lee los datos de la linea
            { 
                
                cerr << "Error al leer los datos del archivo.\n";
            }

            else 
            {
                // convierte la duracion de string a int
                int duracion = stoi(duracion_str);
                // crea un objeto de tipo Pelicula y lo guarda en el vector inteligente
                videos.push_back(make_shared<Pelicula>(tipo, nombre, id, genero, duracion, 0, 0.0));
            }
        }
        archivo.close();
    }
    else // si abrio el archivo fallo
    {
        cout << "No se pudo abrir el archivo" << endl;
    }

    archivo.open("series.txt");
    
    if(archivo.is_open())
    {
        while(getline(archivo, linea))
        {
            istringstream iss(linea);

            string tipo, nombre, genero, id, serie, episodio, duracion_str;
            int duracion, numCalificaciones = 0;
            float calificacion = 0;

            if (!(iss >> tipo >> id >> nombre >> duracion_str >> genero >> serie >> episodio)) 
            {
                cerr << "Error al leer los datos del archivo.\n";
            }

            else 
            {
                int duracion = stoi(duracion_str);
                videos.push_back(make_shared<Serie>(tipo, nombre, duracion, genero, 0, id, 0, serie, episodio));
            }
        }
        archivo.close();
    }
    else { cout << "No se pudo abrir el archivo" << endl; }
    
    while (opcion != 0 && continuar)
    {
        // menu
        cout << "1. Imprimir el catalogo" << endl;
        cout << "2. Calificar video" << endl;
        cout << "3. Imprimir series por calificacion" << endl;
        cout << "4. Imprimir peliculas por calificacion" << endl;
        cout << "5. Imprimir series por genero" << endl;
        cout << "6. Imprimir peliculas por genero" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        // switch para las opciones
        switch (opcion)
        {
        case 1:
            // imprime el catalogo
            cout << "Catalogo: " << endl;
            // iterar sobre el vector de videos
            for(auto& v: videos){cout << *v << endl;}
            break;
        case 2:
            // califica un video, no importa si es serie o pelicula
            cout << "Que calificacion quieres darle al video? " << endl;
            cin >> calif;
            cout << "Que video quieres calificar? (introduce su id)" << endl;
            cin >> id;
            // iterar sobre el vector de videos
            for(auto& v: videos)
            {
                // si el id del video es igual al id que se busca y no tiene calificaciones
                if(v->getId() == id && v->getNumCalificaciones() == 0)
                {
                    // se le asigna la calificacion al video
                    v->setCalificacion(calif);
                }
                // si el id del video es igual al id que se busca y ya tiene calificaciones
                // se le asigna la calificacion al video con otro metodo que las promedia
                else {v->calificarVideo(videos, id, calif);}
            }
            break;
        case 3:
            // imprime series por calificacion
            for( auto& v: videos)
            {
                // si el tipo del video es serie
                // se imprime la serie con su calificacion
                if(v->getTipo() == "s"){v->imprimeXcalif(videos, calif);}
            }
            break;
        case 4:
            // imprime peliculas por calificacion
            for( auto& v: videos)
            {
                // si el tipo del video es pelicula
                // se imprime la pelicula con su calificacion
                if(v->getTipo() == "p"){v->imprimeXcalif(videos, calif);}
            }
            break;
        case 5:
            // imprime series por genero
            cout << "Que genero te gustaria ver? " << endl;
            cin >> genero;
            for( auto& v: videos)
            {
                // si el tipo del video es serie
                // se imprime la serie con su genero
                if(v->getTipo() == "s"){v->imprimeXgenero(videos, genero);}
            }
            break;
        case 6:
            // imprime peliculas por genero
            cout << "Que genero te gustaria ver? " << endl;
            cin >> genero;
            
            for( auto& v: videos)
            {
                // si el tipo del video es pelicula
                // se imprime la pelicula con su genero
                if(v->getTipo() == "p"){v->imprimeXgenero(videos, genero);}
            }
            break;
        case 0:
            // salir
            cout << "Saliendo..." << endl;
            continuar = false;
            break;
        default:
            // opcion no valida
            cout << "Opcion no valida" << endl;
            break;
        }
    }
    return 0;
}