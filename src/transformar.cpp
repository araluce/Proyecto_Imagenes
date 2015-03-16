/**
  * @file transformar.cpp
  * @brief Fichero que contiene los algoritmos que modifican las imagenes
  *
  */

#include<cstring>
#include "imagen.h"

void Ocultar(Imagen &imagen, char mensaje[]){
  unsigned char auxmsj, *buffer;
  int byte=0, filas=imagen.Filas(), columnas=imagen.Columnas(), i, j, n=strlen(mensaje);
  buffer = new unsigned char [filas*columnas];
  
  for( i=0; i<filas; i++ )
    for( j=0; j<columnas; j++ )
      buffer[(i*columnas)+j] = imagen.Get(i, j);

  for( i=0; i<n+1; i++ ){
    for( j=0; j<8; j++ ){
      auxmsj=mensaje[i];
      auxmsj=auxmsj<<j;
      auxmsj=auxmsj>>7;
      buffer[byte+j]=buffer[byte+j]>>1;
      buffer[byte+j]=buffer[byte+j]<<1;
      buffer[byte+j]=auxmsj|buffer[byte+j];
    }
    byte+=8;
  }
  for( i=0; i<filas; i++ )
    for( j=0; j<columnas; j++ )
      imagen.Set(i, j, buffer[(i*columnas)+j] );
}

void Revelar( const Imagen& imagen, char mensaje[] ){

  bool terminado=false;
  int MAXMENSAJE=125000, w=0, filas=imagen.Filas(), columnas=imagen.Columnas(), i, j;
  unsigned char temp, auxbuff, *buffer;
  buffer = new unsigned char [filas*columnas];
  
  for( i=0; i<filas; i++ )
    for( j=0; j<columnas; j++ )
      buffer[(i*columnas)+j] = imagen.Get(i, j);

  for( i=0; i<MAXMENSAJE && !terminado; i+=8 ){
    for( j=0; j<8; j++ ){
      auxbuff=buffer[i+j];
      auxbuff<<=7;
      auxbuff>>=j;
      temp|=auxbuff;
    }

    mensaje[w]=temp;

    if(mensaje[w]=='\0')
      terminado=true;

    w++;
    temp='\0';

  }
  delete[] buffer;
}

void Negativo( Imagen &imagen ) {
  unsigned char n;
  int filas=0, columnas=0;

  filas = imagen.Filas();
  columnas = imagen.Columnas();

  for( int i=0; i<filas; i++ ){
    for( int j=0; j<columnas; j++ ){
      n = imagen.Get( i, j );
      imagen.Set( i, j, 255-n );
    }
  }
}

void Desplazar( int posiciones, Imagen &imagen ){
  int filas, columnas;

  filas = imagen.Filas();
  columnas = imagen.Columnas();

  for( int i=0; i<filas; i++ ){
    for( int j=0; j<columnas; j++ ){
      imagen.Set( i, j, ( imagen.Get( i, j ) )<<posiciones );
    }
  }
}

/* Fin Fichero: transformar.cpp */
