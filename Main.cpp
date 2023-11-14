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
    vector<unique_ptr<Video>> Peliculas; // vector de videos
    vector<unique_ptr<Video>> Series; // vector de series
    int opcion = 3; // opcion del menu
    string linea; // linea del archivo
    ifstream archivo; // archivo de texto
    // funcion split() para separar los datos de la linea
    // leer de dos archivos
    // uno de peliculas y otro de series

    archivo.open("peliculas.txt");
    if(archivo.is_open()){
        while(getline(archivo, linea)){
            istringstream iss(linea);
            string tipo, nombre, genero, id, serie, episodio;
            int duracion, numCalificaciones = 0;
            float calificacion = 0; 
            // aqui debo de crear el vector de objetos de tipo Video
            // la clase serie tiene mas argumentos como los instancio
            iss >> tipo >> id >> nombre >> duracion >> genero;
            Peliculas.push_back(make_unique<Pelicula>(tipo, genero, nombre, id, duracion, 0, 0));
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
            string tipo, nombre, genero, id, serie, episodio;
            int duracion, numCalificaciones = 0;
            float calificacion = 0;
            // aqui debo de crear el vector de objetos de tipo Video
            // la clase serie tiene mas argumentos como los instancio
            if (!(iss >> tipo >> id >> nombre >> duracion >> genero >> serie >> episodio)) {
                // La operación de lectura falló. Maneja el error aquí.
                cerr << "Error al leer los datos del archivo.\n";
            }else {
                iss >> tipo >> id >> nombre >> duracion >> genero >> serie >> episodio;
                Series.push_back(make_unique<Serie>(tipo, nombre, duracion, genero, 0, id, 0, serie, episodio));
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
        cout << "1. Imprimir Peliculas" << endl;
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
            // imprime el Peliculas
            cout << "Peliculas" << endl;
            for(auto& v: Peliculas){
                cout << *v << endl;
            }
            cout << "Series" << endl;
            for(auto& v: Series){
                cout << *v << endl;
            }
            break;
        case 2:
            // califica un video, no importa si es serie o pelicula
            cout << "Que calificacion quieres darle al video? " << endl;
            cin >> calif;
            cout << "Que video quieres calificar? (introduce su id)" << endl;
            cin >> id;
            for(auto& v: Peliculas){
                if(v->getId() == id && v->getCalificacion() == 0){
                    v->setCalificacion(calif);
                    break;
                }
                else{
                    v->calificarVideo(Peliculas, id, calif);
                    break;
                }
            }
            break;
        case 3:
            // imprime series por calificacion
            for( auto& v: Series){
                if(v->getTipo() == "s"){
                    v->imprimeXcalif(Peliculas, calif);
                    break;
                }
            }
            break;
        case 4:
            // imprime peliculas por calificacion
            for( auto& v: Peliculas){
                if(v->getTipo() == "p"){
                    v->imprimeXcalif(Peliculas, calif);
                    break;
                }
            }
            break;
        case 5:
            // imprime series por genero
            for( auto& v: Series){
                cout << "Que genero te gustaria ver? " << endl;
                cin >> genero;
                v->imprimeXgenero(Series, genero);
                break;
            }
            break;
        case 6:
            for( auto& v: Peliculas){
                cout << "Que genero te gustaria ver? " << endl;
                cin >> genero;
                v->imprimeXgenero(Peliculas, genero);
                break;
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

// si sobrecargo el operador << para imprimir el objeto diferente
// cuando imprimo el Peliculas sea imprime correctamente?

// me convendría hacer que video fuera una clase abstracta?
// haciendo clases puras a imprimirXgenero y imprimirXcalif
// para asi en cada una de ellas sobrecargar el operador <<
// y asi imprimir correctamente el objeto

// que tendria que hacer si la clase serie tiene dos atributos extras
// que la clase video no tiene?
// podria agregarlos a la clase serie heredando de video, pero esto 
// me impide recopilar correctamente los datos del archivo de texto
// idea: puedo crear un if cuando recopile los datos del archivo de texto
//       para que si el tipo es s, entonces recopile los datos de la clase
// como lo implemento?

// como asigno correctamente al vector de objetos de tipo Video
// los datos del archivo de texto?

// cual es la diferencia entre hacer el vector de punteros de tipo Video?
