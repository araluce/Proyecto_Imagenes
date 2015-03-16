#ifndef FUNC_GENERAR_H
#define FUNC_GENERAR_H

/**
  * @file func_generar.h
  * @brief Fichero cabecera para las funciones utilizadas para generar un fichero permutación
  *
  */

/**
  * @brief Recoge la información y deriva a una u otra operación dependiendo de la opción elegida
  * @param filas número de filas que queremos generar
  * @param opcion elección de formato de fichero (binario o texto)
  * @param file nombre del fichero a generar
  */
void GenerarAleatorio( char *filas, char *opcion, char *file  );

/**
  * @brief Genera un fichero de tipo de texto
  * @param filas número de filas que queremos generar
  * @param file nombre del fichero a generar
  */
void GenerarT( int filas, char *file );

/**
  * @brief Genera un fichero de tipo binario
  * @param filas número de filas que queremos generar
  * @param file nombre del fichero a generar
  */
void GenerarB( int filas, char *file );

/**
  * @brief Compara un número aleatorio con los que están en el buffer para comprobar si ha sido o no introducido
  * @param numero ha comparar con los del buffer
  * @param buffer vector de enteros donde se almacenan los números aleatorios ha introducir en el fichero
  * @param utilizado número de espacios ocupados en el vector
  * @return Si el número ha sido o no introducido anteriormente
  */
bool Esta( int numero, int *buffer, int utilizado );

#endif

/* Fin Fichero: func_generar.h */
