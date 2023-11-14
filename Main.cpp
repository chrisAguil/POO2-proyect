#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "Serie.h"
#include "Video.h"
#include "Pelicula.h"

int main()
{

    // ------------------------------------------
    // Variables para la ejecucion del programa
    // ------------------------------------------

    bool continuar = true; // bandera para continuar en el menu
    string id; // id del video a calificar
    float calif; // calificacion del video a calificar

    // hacer dos vectores uno de series y otro de peliculas
    string genero; // genero del video a imprimir
    int opcion = 3; // opcion del menu
    string linea; // linea del archivo
    ifstream archivo; // archivo de texto

    vector<shared_ptr<Video>> videos; // vector inteligente de videos

    // try catch para abrir el archivo
    try
    {
        archivo.open("peliculas.txt"); 

        // si no se pudo abrir el archivo se llama a la excepcion
        if(!archivo.is_open()){throw runtime_error("No se pudo abrir el archivo");}

        while(getline(archivo, linea)) // lee una linea del archivo
        {            
            istringstream iss(linea); // separa la linea en palabras
            
            // variables para guardar los datos de la linea
            string tipo, nombre, genero, id, duracion_str;
            int duracion, numCalificaciones = 0;
            float calificacion = 0; 

            // try catch para leer los datos de la linea y la conversion de string a int
            try
            {
                if(!(iss >> tipo >> id >> nombre >> duracion_str >> genero)) // lee los datos de la linea
                { 
                    throw runtime_error("Error al leer los datos del archivo.");
                }
                // convierte la duracion de string a int
                int duracion = stoi(duracion_str);
                // crea un objeto de tipo Pelicula y lo guarda en el vector inteligente
                videos.push_back(make_shared<Pelicula>(tipo, nombre, id, genero, duracion, 0, 0.0));

            }
            // si no se pudo convertir la duracion a int se llama a la excepcion
            catch(const std::invalid_argument& e)
            {
                std::cerr << "Error al convertir la duracion a un numero" << '\n';
            }
            // si no se pudo leer la linea se llama a la excepcion
            catch(const std::exception& e)
            {
                std::cerr << "Error al leer los datos" << '\n';
            }
        }
        archivo.close();
    }
    // si no se pudo abrir el archivo se llama a la excepcion
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }

    try
    {
        archivo.open("series.txt");

        // si no se pudo abrir el archivo se llama a la excepcion
        if(!archivo.is_open()){throw runtime_error("No se pudo abrir el archivo");}

        while(getline(archivo, linea)) // lee una linea del archivo
        {
            istringstream iss(linea); // separa la linea en palabras

            // variables para guardar los datos de la linea
            // deberia de cambiar los nombres? 
            string tipo, nombre, genero, id, serie, episodio, duracion_str;
            int duracion, numCalificaciones = 0;
            float calificacion = 0;

            // try catch para leer los datos de la linea y la conversion de string a int
            try
            {
                // lee los datos de la linea sino se puede thorow exception
                if (!(iss >> tipo >> id >> nombre >> duracion_str >> genero >> serie >> episodio)) 
                {
                    throw runtime_error("Error al leer los datos del archivo.");
                }
                // convierte la duracion de string a int
                int duracion = stoi(duracion_str);
                // crea un objeto de tipo Serie y lo guarda en el vector inteligente
                videos.push_back(make_shared<Serie>(tipo, nombre, duracion, genero, 0, id, 0, serie, episodio));
            }
            // si no se pudo convertir la duracion a int se llama a la excepcion
            catch(const std::invalid_argument& e)
            {
                std::cerr << "Error al convertir la duracion a un numero" << '\n';
            }    
            // si no se pudo leer la linea se llama a la excepcion
            catch(const std::exception& e)
            {
                std::cerr << "Error al leer los datos" << '\n';
            }
        }
        archivo.close();
    }
    // si no se pudo abrir el archivo se llama a la excepcion
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // ------------------------------
    // Menu
    // ------------------------------

    while (opcion != 0 && continuar)
    {
        std::cout << "1. Imprimir el catalogo" << std::endl;
        std::cout << "2. Calificar video" << std::endl;
        std::cout << "3. Imprimir series por calificacion" << std::endl;
        std::cout << "4. Imprimir peliculas por calificacion" << std::endl;
        std::cout << "5. Imprimir series por genero" << std::endl;
        std::cout << "6. Imprimir peliculas por genero" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        // ------------------------------
        // Switchs para las opciones
        // ------------------------------

        switch (opcion)
        {

        // ------------------------------
        // Caso 1
        // ------------------------------

        case 1:
            // imprime el catalogo
            std::cout << "Catalogo: " << std::endl;
            // iterar sobre el vector de videos
            for(auto& v: videos){std::cout << *v << std::endl;}
            break;

        // ------------------------------
        // Caso 2
        // ------------------------------
        
        case 2:
            // califica un video, no importa si es serie o pelicula
            std::cout << "Que calificacion quieres darle al video? " << std::endl;
            std::cin >> calif;
            std::cout << "Que video quieres calificar? (introduce su id)" << std::endl;
            std::cin >> id;
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

        // ------------------------------
        // Caso 3
        // ------------------------------

        case 3:
            // imprime series por calificacion
            for( auto& v: videos)
            {
                // si el tipo del video es serie
                // se imprime la serie con su calificacion
                if(v->getTipo() == "s"){v->imprimeXcalif(videos, calif);}
            }
            break;

        // ------------------------------
        // Caso 4
        // ------------------------------

        case 4:
            // imprime peliculas por calificacion
            for( auto& v: videos)
            {
                // si el tipo del video es pelicula
                // se imprime la pelicula con su calificacion
                if(v->getTipo() == "p"){v->imprimeXcalif(videos, calif);}
            }
            break;

        // ------------------------------
        // Caso 5
        // ------------------------------

        case 5:
            // imprime series por genero
            std::cout << "Que genero te gustaria ver? " << std::endl;
            std::cin >> genero;
            for( auto& v: videos)
            {
                // si el tipo del video es serie
                // se imprime la serie con su genero
                if(v->getTipo() == "s"){v->imprimeXgenero(videos, genero);}
            }
            break;

        // ------------------------------
        // Caso 6
        // ------------------------------

        case 6:
            // imprime peliculas por genero
            std::cout << "Que genero te gustaria ver? " << std::endl;
            std::cin >> genero;
            
            for( auto& v: videos)
            {
                // si el tipo del video es pelicula
                // se imprime la pelicula con su genero
                if(v->getTipo() == "p"){v->imprimeXgenero(videos, genero);}
            }
            break;

        // ------------------------------
        // Caso 0
        // ------------------------------

        case 0:
            // salir
            std::cout << "Saliendo..." << std::endl;
            continuar = false;
            break;

        // ------------------------------
        // Caso default
        // ------------------------------
        
        default:
            // opcion no valida
            std::cout << "Opcion no valida" << std::endl;
            break;
        }
    }
    return 0;
}