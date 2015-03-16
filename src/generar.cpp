/**
  * @file generar.cpp
  * @brief Genera ficheros con 512 numeros aleatorios desde 0 a 512 sin repetir
  *
  * Los ficheros se toman como entradas a otro programa
  *
  */


#include <iostream>
#include <stdlib.h>
#include "func_generar.h"

using namespace std;
int main( int argc, char *argv[] ){

  if( argc != 4 ){
    cerr << "\n\aError al insertar argumentos.Lea las instrucciones de uso:";
    cout << "\n Uso: " << argv[0] << " <numero_filas> <opcion> <nombre_fichero.per>\n";
    exit(1);
  }
  else{
    GenerarAleatorio( argv[1], argv[2], argv[3] );
  }

  return 0;
}
/* Fin Fichero: generar.cpp */
