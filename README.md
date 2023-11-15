# POO2-proyect

Se quiere trabajar con dos tipos de videos: películas y series. Todo video tiene un ID, un nombre, una duración y un género (drama, acción, misterio).

Las series tienen episodios y cada episodio tiene un título y temporada a la que pertenece.

Nos interesa conocer la calificación promedio que ha recibido cada uno de los videos. Esta califiación está en escala de 1 a 5 donde 5 es la mejor calificación.

El sistema debe ser capaz de :

- Mostrar los videos en general con sus calificaciones
- Mostrar los episodios de una determinada serie con sus calificaciones
- Mostrar las películas con sus calificaciones

El programa al iniciar cargará un archivo llamado videos.txt,(Este archivo tiene este formato  formatoArchivo.txt Download formatoArchivo.txt), el cual contiene toda la información de las películas y capítulos de serie que se desean consultar y calificar. En este momento ningún video tiene una calificación, estas se irán dando al utilizar el programa.
A continuación el programa mostrará el siguiente menú ciclado es decir mientras no se seleccione la opción de salir volverá a mostrar el menú para seguir interactuando. Abajo se da una explicación de cada opción. (OJO, no estoy colocando acentos de manera intencionada para evitar problemas al momento de que se despliegue el menú) y siempre que se espera que se introduzca un dato del usuario el sistema deberá mostrar lo que se está esperando que se introduzca.
1. Mostrar todo el catalogo con calificaciones.
2. Calificar un video
3. Mostrar peliculas o capitulos con una calificacion minima determinada
4. Mostrar peliculas o capitulos de un cierto genero.
9. Salir
Explicación de cada opción:

1) Mostrar todo el catálogo con calificaciones. Esta opción imprimirá todos los capítulos y películas con las que se ha cargado el sistema. Sólo sin poner al inicio el primer campo que indica si se trata de una película o un capítulo. Además debe agregar al final la calificación promedio que tiene ese video. Si el video aun no ha sido calificado agregará la palabra SC que significa sin calificación. Un ejemplo de salida de esta opción sería. (Puedes formatear la salida para que se visualice mejor como agregando tabulaciones pero no quitando ni agregando datos que no se piden)

20191245,The Lion King,118,drama,3.2
20160150-S02E09,Chapter Nine: The Gate,62,accion,Stranger Things T2,9,4.5
20191246,The Lion King 2,109,drama,SC
20160150-S02E10,Chapter Ten: The Golden,65,accion,Stranger Things T2,10,SC
Los primeros dos capítulos muestran al final 3.2 y 4.5 respectivamente por que es el promedio de las calificaciones que se les han hecho.

Para este punto sobrecarga el operador << para que despliegue la información de los vídeos.

2) Calificar un video. En esta opción el sistema preguntará el ID del vídeo a calificar. A continuación, el sistema pedirá que ingrese la calificación que deseo dar a ese video. La entrada debe ser un número entero entre 1 y 5. Esta entrada debe de validar que el número ingresado no esté fuera de rango, en caso de ser así debe pedir que ingrese un valor válido. Es muy importante que la calificación que se introduzca se pondere con todas las calificaciones que se han realizado a este video, es decir si un vídeo 4 personas ya lo calificaron con 5 y al final una persona lo califica con un 3, entonces la calificación promedio del vídeo es 4.6 no 4.

3) Mostrar películas o capítulos con una calificacion mínima determinada. En esta opción, la persona puede consultar los vídeos que tienen una evaluación promedio mayor o igual a la que introduzca. Cuando se seleccione esta opción el sistema me llevará a otro submenú en el cual me pedirá si quiero ver como resultados películas, capítulos o ambos, Me pedirá que introduzca un entero (Película =1, Capítulo=2, Ambos=3). Validar que la opción que escriba esté en rango. Luego me preguntará la calificación mínima y en aquí sí puedo introducir decimales. El resultado que muestra el sistema es un listado donde sólo me mostrará el ID del vídeo, el nombre y la calificación promedio que tiene. Un ejemplo de esta salida si seleccioné Ambos con calificacación mínima de 4.2 sería. (Puedes formatear la salida para que se visualice mejor como agregando tabulaciones pero no quitando ni agregando datos que no se piden)

20191245,The Lion King,4.5
20160150-S02E09,Chapter Nine: The Gate,4.6
20191246,The Lion King 2,4.2
20160150-S02E10,Chapter Ten: The Golden,4.9

Ojo un vídeo que aun no ha sido calificado no debería de mostrarse en esta opción y recordar como que la calificación promedio se debe obtener como se menciona en el inciso 2.

4) Mostrar películas o capítulos de un cierto genero. En esta opción, la persona puede consultar los vídeos que están clasificados con cierto género. Cuando se seleccione esta opción el sistema me llevará a otro submenú en el cual me pedirá si quiero ver como resultados películas, capítulos o ambos, Me pedirá que introduzca un entero (Película =1, Capítulo=2, Ambos=3). Validar que la opción que escriba esté en rango. Luego me preguntará el género que deseo consultar.. El resultado que muestra el sistema es un listado donde sólo me mostrará el ID del vídeo, el nombre, género y la calificación promedio que tiene. Un ejemplo de esta salida si seleccioné Ambos con género drama sería. (Puedes formatear la salida para que se visualice mejor como agregando tabulaciones pero no quitando ni agregando datos que no se piden)

20191245,The Lion King,drama,4.5
20160150-S02E09,Chapter Nine: The Gate,drama,4.6
20191246,The Lion King 2,drama,4.2
20160150-S02E10,Chapter Ten: The Golden,drama,4.9

El sistema debe validar las entradas que se mencionan. Pueden suponer que el archivo viene sin errores y con el formato que se mencionó. (formatoArchivo.txt Download formatoArchivo.txt)

## Instalación

1. Clona el repositorio en tu máquina local usando `git clone https://github.com/username/repo-name.git`.

2. Navega hasta el directorio del proyecto usando `cd repo-name`.

3. Compila el proyecto. Si estás utilizando g++, puedes hacerlo con `g++ -o ejecutable main.cpp`. Reemplaza `main.cpp` con el nombre de tu archivo fuente y `ejecutable` con el nombre que quieras para el archivo ejecutable.

4. Ejecuta el programa con `./ejecutable`.

Nota: Estas instrucciones asumen que tienes instalado un compilador de C++ como g++ y Git en tu máquina.

## Uso

1. Ejecuta el programa con `./ejecutable`.
2. Verás un menú con varias opciones. Aquí está lo que hace cada opción:
   - `1. Imprimir el catalogo`: Muestra todos los videos disponibles con sus detalles.
   - `2. Calificar video`: Te permite calificar un video. Se te pedirá que ingreses el ID del video y la calificación que deseas darle.
   - `3. Imprimir series por calificacion`: Muestra todas las series ordenadas por calificación.
   - `4. Imprimir peliculas por calificacion`: Muestra todas las películas ordenadas por calificación.
   - `5. Imprimir series por genero`: Te permite ver todas las series de un género específico.
   - `6. Imprimir peliculas por genero`: Te permite ver todas las películas de un género específico.
   - `0. Salir`: Cierra el programa.
3. Para seleccionar una opción, ingresa el número correspondiente y presiona Enter.