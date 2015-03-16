/**
  * @file desplazar.cpp
  * @brief Fichero principal que se ocupa de recoger información para desplazar una imagen
  *
  * Permite desplazar imágenes de tipo PGM
  *
  */


#include <iostream>
#include <stdlib.h>
#include "imagen.h"
#include "transformar.h"

using namespace std;
int main( int argc, char *argv[] ){

  if( argc != 4 ){
    cerr << "\n\aError al insertar argumentos.Lea las instrucciones de uso:";
    cout << "\n Orden: programa <numero_de_posiciones_a_desplazar> <nombre_imagen_entrada.pgm> <nombre_imagen_salida.pgm>";
    exit(1);
  }
  else{
    Imagen imagen;
    if( imagen.LeerImagen( argv[2] ) )
      Desplazar( atoi(argv[1]), imagen );
    else{
      cerr << "\n\aError en la lectura" << endl;
      exit(2);
    }
    if( !imagen.EscribirImagen( argv[3] ) ){
      cerr << "\n\aError en la escritura" << endl;
      exit(3);
    }
  }

  return 0;
}
/* Fin Fichero: desplazar.cpp */
