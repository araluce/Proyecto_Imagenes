/**
  * @file negativo.cpp
  * @brief Fichero principal que se ocupa de recoger información para cambiar una imagen a negativo
  *
  * Permite pasar a negativo imágenes de tipo PGM
  *
  */


#include <iostream>
#include <stdlib.h>
#include "imagen.h"
#include "transformar.h"

using namespace std;
int main( int argc, char *argv[] ){

  if( argc != 3 ){
    cerr << "\n\aError al insertar argumentos.Lea las instrucciones de uso:";
    cout << "\n Orden: <programa> <nombre_imagen_entrada.pgm> <nombre_imagen_salida.pgm>";
    exit(1);
  }
  else{
    Imagen imagen;
    if( imagen.LeerImagen( argv[1] ) )
      Negativo( imagen );
    else{
      cerr << "\n\aError en la lectura" << endl;
      exit(2);
    }
    if( !imagen.EscribirImagen( argv[2] ) ){
      cerr << "\n\aError en la escritura" << endl;
      exit(3);
    }
  }

  return 0;
}
/* Fin Fichero: negativo.cpp */
