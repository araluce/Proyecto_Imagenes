/**
  * @file ocultar.cpp
  * @brief Fichero con definiciones para la ocultación de mensajes en imágenes
  *
  * Permite ocultar mensajes en imágenes de tipo PGM
  *
  */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "imagen.h"
#include "transformar.h"
using namespace std;

int main( int n_arg, char *argv[]){

  if( n_arg != 3 ){
    cerr << "\n\aError al insertar argumentos.Lea las instrucciones de uso:";
    cerr << "\n Orden: <programa> <nombre_imagen_entrada.pgm> <nombre_imagen_salida.pgm>" << endl << endl;
    exit(1);
  }
  else{
    Imagen imagen;
    char mensaje[125000];
    int i = 0; //ESTO NO LO INCLUÍ EN LA PRÁCTICA FINAL (ME BAJÓ MUCHÍSIMA NOTA)

    while( cin ){
      cin.get( mensaje[i] );
      i++;
    }

    if( imagen.LeerImagen( argv[1] ) )
      Ocultar( imagen, mensaje );
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
/* Fin Fichero: ocultar.cpp */
