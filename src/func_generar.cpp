/**
  * @file func_generar.cpp
  * @brief Fichero que contiene las implementaciones de las funciones utilizadas para generar ficheros
  *
  */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "func_generar.h"
using namespace std;

void GenerarAleatorio( char *filas, char *opcion, char *file  ){
  if( atoi(filas) > 0 ){
    if( *opcion == 't' )
      GenerarT( atoi(filas), file );
    else{
      if( *opcion == 'b' )
        GenerarB( atoi(filas), file );
      else{
        cerr << " Error al elegir opcion\n";
        cerr << " Opciones: \n\t<t> (fichero de texto)\n\t<b> (fichero binario)\n";
        exit (1);
      }
    }
  }
  else{
    cerr << " Error a elegir el número de filas\n El valor debe ser mayor que 0. " << atoi(filas) << "<=0 \n";
    exit (7);
  }
}

void GenerarT( int filas, char *file ){
  int numero, i = 0, j = 0 , *buffer;
  const char *clave_magica = "MP-PER-T";
  ofstream aleatorio;
  aleatorio.open( file );

  if(!aleatorio){
    cout<<" No se pudo abrir el fichero"<<endl;
    exit (2);
  }

  aleatorio << clave_magica << " ";
  aleatorio << filas << endl;

  buffer = new int [filas];
  srand( time(NULL) );
  while( i < filas ){
    j = 0;
    numero = rand() % filas;
    if( !Esta( numero, buffer, i ) ) 
      buffer[i] = numero;
    else 
      j++;
    i-=j;
    i++;
  }
  for( i = 0; i < filas; i++ )
    aleatorio << buffer[i] << endl;

  aleatorio.close();
  delete [] buffer;
}

void GenerarB( int filas, char *file ){
  int numero, i = 0, j = 0 , *buffer;
  const char *clave_magica = "MP-PER-B";
  ofstream aleatorio;
  aleatorio.open( file, ios::binary );

  if(!aleatorio){
    cerr<<" No se pudo abrir el fichero"<<endl;
    exit (2);
  }

  aleatorio << clave_magica << " ";
  aleatorio << filas << endl;

  buffer = new int[filas];
  srand( time(NULL) );
  while( i < filas ){
    j = 0;
    numero = rand() % filas;
    if( !Esta( numero, buffer, i ) ) 
      buffer[i] = numero;
    else 
      j++;
    i-=j;
    i++;
  }
  
  aleatorio.write(reinterpret_cast<char *>(buffer),filas*sizeof(int));
  if(!aleatorio){
    cerr<<" Problema al escribir los datos"<<endl;
    exit (3);
  }
  aleatorio.close();
}

bool Esta( int numero, int *buffer, int utilizado ){
  bool resultado = false;
  for( int i = 0; i < utilizado && !resultado; i++ )
    if( buffer[i] == numero ) resultado = true;
  return resultado;
}

/* Fin Fichero: func_generar.cpp */
