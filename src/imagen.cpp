/**
  * @file imagen.cpp
  * @brief Fichero que recoge las definiciónes de los métodos de la clase Imagen
  *
  */

#include "imagen.h"

int Imagen::Filas() const{
  return filas;
}

int Imagen::Columnas() const{
  return columnas;
}

void Imagen::Crear( ){
  int total = filas*columnas;

  L = new unsigned char *[filas];
  L[0] = new unsigned char [total];
  for( int i=1; i<filas; i++ )
    L[i] = L[i-1] + columnas;
}

void Imagen::Set( int i, int j, unsigned char v ){
  L[i][j] = v;
}

unsigned char Imagen::Get( int i, int j ) const{
  return L[i][j];
}

void Imagen::Destruir(){
  delete [] L[0];
  delete [] L;
}

Imagen::~Imagen( void ){
  Destruir();
}

bool Imagen::LeerImagen( const char file[] ){
  bool exito = false;
  if( LeerTipoImagen( file, filas, columnas ) == 1 ){
    Crear( );
    unsigned char *buffer = new unsigned char[filas*columnas];
    if( LeerImagenPGM( file, filas, columnas, buffer ) ){
      for(int i = 0; i<filas;i++)
	for(int j = 0; j<columnas; j++)
	  Set( i, j, buffer[(i*columnas)+j] );
      exito = true;
    }
  delete [] buffer;
  }
  return exito;
}

bool Imagen::EscribirImagen( const char file[] ) const{
  bool exito = false;
  unsigned char *buffer = new unsigned char[filas*columnas];
  for(int i = 0; i<filas;i++)
    for(int j = 0; j<columnas; j++)
      buffer[(i*columnas)+j] = Get(i, j);
  if( EscribirImagenPGM( file, *L, filas, columnas ) )
    exito = true;
  delete [] buffer;
  return exito;
}

/* Fin Fichero: imagen.cpp */
