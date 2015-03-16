/**
  * @file revelar.cpp
  * @brief Fichero con definiciones para revelar mensajes en imágenes
  *
  * Permite revelar mensajes en imágenes de tipo PGM
  *
  */

#include<iostream>
#include<transformar.h>
#include<imagenES.h>
using namespace std;

int main( int n_arg, char *argv[] ){

  if( n_arg != 2 ){
    cerr << "\n\aError al insertar argumentos.Lea las instrucciones de uso:";
    cerr << "\n Orden: <programa> <nombre_imagen.pgm>" << endl << endl;
    return 1;
  }

  else{
    Imagen imagen;
    char mensaje[125000];

    cerr << "\nRevelando..." << endl;

    if( imagen.LeerImagen( argv[1] ) )
      Revelar( imagen, mensaje );
    else{
      cerr << "\n\aError en la lectura" << endl;
      return 2;
    }

    cout << mensaje;
    cerr << endl;
  }

  return 0;
}


/* Fin Fichero: revelar.cpp */
