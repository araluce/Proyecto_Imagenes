#ifndef PERMUTACION_H
#define PERMUTACION_H

/**
  * @file permutacion.h
  * @brief Fichero cabecera para la clase permutación
  *
  */
#include "imagen.h"

/**
  * @class Permutacion
  * @brief Permutacion permuta filas de una imagen
  */
class Permutacion{
  private:
    Imagen perm; ///< imagen permutada
    int *fichero; ///< fichero que almacena las permutaciones
    int filas; ///< filas de la imagen
    Imagen copia; ///< copia de la imagen
  public:
    /**
    * @brief Guarda el fichero
    * @param datos nombre del fichero
    */
    void AlmacenaFichero( const char *datos );

    /**
    * @brief Modifica la imagen fila a fila
    * @param fila es la fila a modificar
    */
    void Modificar( int fila );

    /**
    * @brief Se encarga de todo el proceso de permutado
    * @param entrada nombre de entrada de la imagen
    * @param datos nombre del fichero que contiene la información
    * @param salida nombre de salida de la imagen
    */
    void Permutar( const char *entrada, const char *datos, const char *salida );

    /**
    * @brief Comprueba si falta alguna fila o si se repiten
    * @return Si se han escrito correctamente todas las filas o falta alguna
    */
    bool EstanTodos( );

    /**
    * @brief Decodifica una imagen
    * @param entrada nombre de entrada de la imagen
    * @param datos nombre del fichero que contiene la información
    * @param salida nombre de salida de la imagen
    */
    void Decodificar( const char *entrada, const char *datos, const char *salida );

    /**
    * @brief Busca la fila y devuelve la posicion en el que está
    * @param f fila a buscar
    * @return La posición en la que se ha encontrado la fila en el fichero
    */
    int Busca( int f );
    
};

#endif

/* Fin Fichero: permutacion.h */
