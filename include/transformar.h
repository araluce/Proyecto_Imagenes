/**
  * @file transformar.h
  * @brief Fichero cabecera para los operadores de imágenes
  *
  * Permite ocultar y revelar mensajes y desplazar y pasar a negativo imágenes de tipo PGM
  *
  */


#include "imagen.h"

#ifndef TRANSFORMAR_H
#define TRANSFORMAR_H
/**
  * @brief Desplaza un numero de posiciones una imagen tipo PGM
  *
  * @param posiciones numero de desplazamientos.
  * @param imagen zona de memoria que se manipula para obtener la nueva imagen.
  */
void Desplazar( int posiciones, Imagen &imagen ) ;

/**
  * @brief Obtiene el negativo de una imagen tipo PGM
  *
  * @param imagen zona de memoria que se manipula para obtener la nueva imagen.
  */
void Negativo( Imagen &imagen ) ;

/**
  * @brief Oculta un mensaje en una imagen de tipo PGM
  *
  * @param imagen zona de memoria que se manipula para incluir un mensaje en la imagen.
  * @param mensaje a insertar en la imagen.
  */
void Ocultar(Imagen &imagen, char mensaje[]);

/**
  *@brief Algoritmo para revelar los mensajes ocultos en las imagenes.
  *
  *@param imagen zona de memoria que se manipula para obtener el mensaje previamente ocultado.
  *@param mensaje vector de caracteres que se pasa como referencia y que contendrá el mensaje obtenido.
  */
void Revelar( const Imagen &imagen, char mensaje[] );

#endif

/* Fin Fichero: transformar.h */
