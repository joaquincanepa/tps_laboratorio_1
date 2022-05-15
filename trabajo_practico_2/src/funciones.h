/*
 * funciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: joaco
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define FUNCIONES_H_



/**
 * @brief Le pide al ususario que ingrese una opcion del uno al seis y retorna la misma.
 *
 * @return retorna la opcion elegida por el usuario
 */
int menu();

/// \brief imprime el Menu de modificacion
/// \param void
/// \return retorna retorna la opcion elegida por el usuario
int menuModificar();

/// @brief imprime el Menu de informes
/// \param void solo imprime por pantalla cuando es invocada
/// \return retorna retorna la opcion elegida por el usuario
char menuInforme();


/**
 *
 * @param valor guarda un numero flotante
 * @param mensaje
 * @param mensajeError mensaje de error
 * @param min minimo
 * @param max maximo
 * @param reintentos cantitdad de reintentos
 * @return retorna 1 si esta bien
 */
int getFloat(float *valor, char *mensaje, char *mensajeError, int min, int max, int reintentos);


/**
 * @brief
 *
 * @param lugar guarda un entero
 * @param mensaje es un mensaje
 * @param mensajeError mensaje de error
 * @param min minimo
 * @param max maximo
 * @param reintentos cantidad re reintentos
 * @return retorna 1 si esta bien
 */
int getInt(int *lugar, char *mensaje, char *mensajeError, int min, int max, int reintentos);



/**
 * @brief
 *
 * @param lugar guarda un string
 * @param mensaje es un mensaje
 * @param mensajeError mensaje de error
 * @param limite limite
 * @param reintentos cantidad re reintentos
 * @return retorna 1 si esta bien
 */
int getString(char *lugar, char *mensaje, char *mensajeError, int limite, int reintentos);


/**
 * @brief Esta funcion Valida si un dato ingresado es un flotante válido
 *
 * @param cadena
 * @return retorna 1 si es flotante
 */
int isFloat(char* cadena);



/// \param cadena
/// \return int 1 si es int
int isInt(char* cadena);


/**
 * @brief
 *
 * @param array espacio para guardar de forma segura un ingreso de usuario
 * @param limite de caracteres
 * @return
 */
int myGets(char *array, int limite);


#endif /* FUNCIONES_H_ */
