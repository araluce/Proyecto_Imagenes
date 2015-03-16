/**
  * @file permutacion.cpp
  * @brief Fichero que contiene la implementación de los métodos de la clase Permutacion
  *
  * Algoritmos de permutación de imágenes
  *
  */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "permutacion.h"
using namespace std;

void QuickSort(int* izq, int* der);

void Permutacion::AlmacenaFichero( const char *datos ){
  int i = 0;
  char *clave_magica;
  char space;
  clave_magica = new char [8];

  ifstream info;
  info.open( datos, ios::in );
  if(!info){
    cerr<<" No se pudo abrir el fichero"<<endl;
    exit(1);
  }
  else{
    info >> clave_magica;
    if( clave_magica[7] == 'T' ){
      info >> filas;
      fichero = new int [filas];
      for( i = 0; i < filas; i++ )
        info >> fichero[i];
      info.close();
      if( !EstanTodos() ){
        cerr << " Secuencia de numeros en el fichero \"" << datos << "\" incorrecta.\n";
        cerr << " No estan todas las filas o se salen del rango.\n";
        exit(2);
      }
    }
    else{
      info.close();
      
      ifstream info;
      info.open( datos, ios::binary );
      if(!info){
        cerr << " No se pudo abrir el fichero"<<endl;
        exit(1);
      }
      
      info >> clave_magica;
      info >> filas;
      info.get(space);
      fichero = new int[filas];
      info.read(reinterpret_cast<char *>(fichero),filas*sizeof(int));
      if(!info){
          cerr << " Problema al leer datos"<<endl;
          exit(3);
      }
      if( !EstanTodos() ){
        cerr << " Secuencia de numeros en el fichero \"" << datos << "\" incorrecta.\n";
        cerr << " No estan todas las filas o se salen del rango.\n";
        exit(2);
      }
      info.close();
    }
  }
}

void Permutacion::Modificar( int fila ){
  unsigned char *aux;
  int columnas = perm.Columnas();

  aux = new unsigned char [columnas];

  for( int col = 0; col < columnas; col++ ){
    aux[col] = copia.Get( fichero[fila], col );
    perm.Set( fila, col, aux[col] );
  }
}

void Permutacion::Permutar( const char *entrada, const char *datos, const char *salida ){
  if( perm.LeerImagen( entrada ) ){
    copia.LeerImagen( entrada );
    AlmacenaFichero( datos );
    for( int i = 0; i < filas; i++ )
      Modificar( i );
    if( !perm.EscribirImagen( salida ) ){
      cerr << "\a Error al escribir la imagen";
      exit(4);
    }
  }
  else{
    cerr << "\a Error en la lectura de la imagen" << endl;
    exit(5);
  }
}

void Permutacion::Decodificar( const char *entrada, const char *datos, const char *salida ){
  if( perm.LeerImagen( entrada ) ){
    int n;
    unsigned char *aux;
    int columnas = perm.Columnas();
    
    copia.LeerImagen( entrada );
    AlmacenaFichero( datos );
    for( int i = 0; i < filas; i++ ){
      n = Busca( i );
      aux = new unsigned char [columnas];

      for( int col = 0; col < columnas; col++ ){
        aux[col] = copia.Get( fichero[n], col );
        perm.Set( fichero[i], col, aux[col] );
      }
    }
    if( !perm.EscribirImagen( salida ) ){
      cerr << "\a Error al escribir la imagen";
      exit(4);
    }
  }
  else{
    cerr << "\a Error en la lectura de la imagen" << endl;
    exit(5);
  }
}

bool Permutacion::EstanTodos( ){
  int copiafichero[filas];
  bool verdad = true;

  for( int i=0; i < filas; i++ )
    copiafichero[i] = fichero[i];
  QuickSort( copiafichero, copiafichero + filas-1 );
  if( copiafichero[0] != 0 ) verdad = false;
  for( int i = 0; i < filas-1 && verdad; i++ )
    if( copiafichero[i+1] != copiafichero[i]+1 )
        verdad = false;
  return verdad;
}

int Permutacion::Busca( int f ){
  for( int i = 0; i < filas; i++ ){
    if( fichero[i] == f )
      return i;
  }
  exit(6);
}

void QuickSort(int* izq, int* der){
  if(der<izq) return;
  int pivot=*izq;
  int * ult=der;
  int* pri=izq;
  int temp;

  while(izq<der) {
    while(*izq<=pivot && izq<der+1) izq++;
    while(*der>pivot && der>izq-1) der--;
    if(izq<der) {
      temp = *izq;
      *izq = *der;
      *der = temp;
    }
  }

  temp = *pri;
  *pri = *der;
  *der = temp;
  QuickSort(pri,der-1);
  QuickSort(der+1,ult);
}
/* Fin Fichero: permutacion.cpp */
