/**
  * @file imagen.h
  * @brief Fichero cabecera para la clase imagen
  *
  */
#ifndef IMAGEN_3_H
#define IMAGEN_3_H

#include<imagenES.h>

/**
  * @class Imagen
  * @brief Imagen es una matriz donde se guarda una imagen
  */
class Imagen {
  private:
    int filas; ///< filas de la matriz
    int columnas; ///< columnas de la matriz
    unsigned char **L; ///< L puntero que apunta a otro puntero que apunta a su vez a la matriz

  public:

    /**
    * @brief Reserva recursos
    */
    void Crear ();

    /**
    * @brief Devuelve el número de filas de la imgen
    * @return Número de filas de la imagen
    */
    int Filas () const;

    /**
    * @brief Devuelve el número de columnas de la imgen
    * @return Número de columnas de la imagen
    */
    int Columnas () const;

    /**
    * @brief Introduce los datos en la matriz creada
    * @param i son las filas
    * @param j son las columnas
    * @param v son los datos a introducir
    */
    void Set ( int i, int j, unsigned char v );

    /**
    * @brief Devuelve el valor que contiene la posición [i][j]
    * @param i son las filas
    * @param j son las columnas
    */
    unsigned char Get ( int i, int j ) const;

    /**
    * @brief Libera los recursos de la matriz
    */
    void Destruir ();

    /**
    * @brief Destructor
    */
    ~Imagen( void );

    /**
    * @brief Lee una imagen
    * @param file nombre del fichero a leer
    */
    bool LeerImagen( const char file[] );

    /**
    * @brief Guarda la imagen en file
    * @param file nombre del archivo a escribir
    * @return Si se ha escrito correctamente
    */
    bool EscribirImagen( const char file[] ) const;
};

#endif

/* Fin Fichero: imagen.h */
