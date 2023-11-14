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
    // funcion split() para separar los datos de la linea
    // leer de dos archivos
    // uno de peliculas y otro de series
    vector<shared_ptr<Video>> videos;
    archivo.open("peliculas.txt");
    if(archivo.is_open()){
        while(getline(archivo, linea)){
            istringstream iss(linea);
            string tipo, nombre, genero, id, duracion_str;
            int duracion, numCalificaciones = 0;
            float calificacion = 0; 
            // aqui debo de crear el vector de objetos de tipo Video
            // la clase serie tiene mas argumentos como los instancio
            if(!(iss >> tipo >> id >> nombre >> duracion_str >> genero)){
                // La operación de lectura falló. Maneja el error aquí.
                cerr << "Error al leer los datos del archivo.\n";
            }else {
                int duracion = stoi(duracion_str);
                videos.push_back(make_shared<Pelicula>(tipo, nombre, id, genero, duracion, 0, 0.0));
                }
            // Peliculas.push_back(make_unique<Pelicula>(tipo, genero, nombre, id, duracion, 0, 0));
            // pasarlos al constructor
        }
        archivo.close();
    }
    else{
        cout << "No se pudo abrir el archivo" << endl;
    }

    archivo.open("series.txt");
    if(archivo.is_open()){
        while(getline(archivo, linea)){
            istringstream iss(linea);
            string tipo2, nombre2, genero2, id2, serie2, episodio2, duracion_str2;
            int duracion2, numCalificaciones2 = 0;
            float calificacion2 = 0;
            if (!(iss >> tipo2 >> id >> nombre2 >> duracion_str2 >> genero >> serie2 >> episodio2)) {
                // La operación de lectura falló. Maneja el error aquí.
                cerr << "Error al leer los datos del archivo.\n";
            }else {
                int duracion2 = stoi(duracion_str2);
                videos.push_back(make_shared<Serie>(tipo2, nombre2, duracion2, genero2, 0, id2, 0, serie2, episodio2));
            }
            // pasarlos al constructor
        }
        archivo.close();
    }
    else{
        cout << "No se pudo abrir el archivo" << endl;
    }
    
    while (opcion != 0 && continuar)
    {
        cout << "1. Imprimir el catalogo" << endl;
        cout << "2. Calificar video" << endl;
        cout << "3. Imprimir series por calificacion" << endl;
        cout << "4. Imprimir peliculas por calificacion" << endl;
        cout << "5. Imprimir series por genero" << endl;
        cout << "6. Imprimir peliculas por genero" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            // imprime el catalogo
            cout << "Catalogo: " << endl;
            for(auto& v: videos){
                cout << *v << endl;
            }
            break;
        case 2:
            // califica un video, no importa si es serie o pelicula
            cout << "Que calificacion quieres darle al video? " << endl;
            cin >> calif;
            cout << "Que video quieres calificar? (introduce su id)" << endl;
            cin >> id;
            for(auto& v: videos){
                if(v->getId() == id && v->getNumCalificaciones() == 0){
                    v->setCalificacion(calif);
                }
                else{
                    v->calificarVideo(videos, id, calif);
                }
            }
            break;
        case 3:
            // imprime series por calificacion
            for( auto& v: videos){
                if(v->getTipo() == "s"){
                    v->imprimeXcalif(videos, calif);
                }
            }
            break;
        case 4:
            // imprime peliculas por calificacion
            for( auto& v: videos){
                if(v->getTipo() == "p"){
                    v->imprimeXcalif(videos, calif);
                }
            }
            break;
        case 5:
            // imprime series por genero
            for( auto& v: videos){
                cout << "Que genero te gustaria ver? " << endl;
                cin >> genero;
                v->imprimeXgenero(videos, genero);
            }
            break;
        case 6:
            for( auto& v: videos){
                cout << "Que genero te gustaria ver? " << endl;
                cin >> genero;
                v->imprimeXgenero(videos, genero);
            }
        
            break;
        case 0:
            cout << "Saliendo..." << endl;
            continuar = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
    
    return 0;
}