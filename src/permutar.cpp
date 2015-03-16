/**
  * @file permutar.cpp
  * @brief Fichero principal que se ocupa de recoger permutar una imagen de tipo PGM
  *
  * Permite permutar filas de imágenes de tipo PGM
  *
  */


#include <iostream>
#include <cstdlib>
#include <cstring>
#include "permutacion.h"

using namespace std;
int main( int argc, char *argv[] ){

  if( argc != 4 && argc != 5 ){
    cerr << "\n\aError al insertar argumentos.Lea las instrucciones de uso:";
    cout << "\n Uso1: " << argv[0] << " <nombre_imagen_entrada.pgm> <nombre_fichero.per> <nombre_imagen_salida.pgm>\n";
    cout << "\n Uso2: " << argv[0] << " -d <nombre_imagen_entrada.pgm> <nombre_fichero.per> <nombre_imagen_salida.pgm>\n";
    exit(1);
  }
  else{
    Permutacion datos;
    if( strcmp(argv[1], "-d" ) == 0 )
      datos.Decodificar( argv[2], argv[3], argv[4] );
    else 
      datos.Permutar( argv[1], argv[2], argv[3] );
  }

  return 0;
}
/* Fin Fichero: permutar.cpp */
