/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Joaquin Canepa.
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/**
 * @brief Le pide al ususario que ingrese una opcion del uno al seis y retorna la misma.
 *
 * @return retorna la opcion elegida por el usuario
 */
int menu();


/**
 * @brief Esta funcion pide un char,ademas un minimo y un maximo para valida un numero y te duvuelve el mismo.
 *
 * @param texto. Este parametro recibe un texto(char).
 * @param minmimo. Este parametro recibe un numero minimo.
 * @param maximo. Este parametro recibe un numero maximo.
 * @return Este retorno, devuelve el numero ingresado por el ususario validado.
 */
int pedirYvalidar(char texto[],float minmimo, float maximo);


/**
 * @brief esta funcion calcula la diferencia de dos numeros y retorna el resultado.
 *
 * @param num1. Este parametro recibe un numero.
 * @param num2. Este parametro otro un numero.
 * @return retorna el resultado de la resta
 */
float calcularDiferencia(float num1, float num2);


/**
 * @brief Esta funcion calcula la multiplicacion entre dos numeros y te retorna el resultado.
 *
 * @param operador1. Este parametro recibe un nuemro.
 * @param operador2 Este parametro recibe otro numero.
 * @return Retorna el resultado entre la multiplicacion.
 */
float multiplicar(float operador1, float operador2);


/**
 * @brief Esta funcion calcula la division entre dos numeros y te retorna el resultado.
 *
 * @param operador1 Este parametro recibe un numero por copia.
 * @param operador2 Este parametro recibe otro numero por copia.
 * @return Este return devuelve el resultado.
 */
float dividir(float operador1, float operador2);


/**
 * @brief Esta funcion te pide 4 numeros flotantes y te los muestra mediante un printf.
 *
 * @param debito Este parametro pide por copia un numero flotante.
 * @param credito Este parametro pide por copia otro numero flotante.
 * @param btc Este parametro pide por copia otro numero flotante.
 * @param precioXkm Este parametro pide por copia un ultimo numero flotante.
 */
void mostrarCalculos (float debito, float credito, float btc, float precioXkm);


/**
 * @brief Esta funcion es exclusivamente para la carga forzada de datos, no pide ni retorna nada, simplemente muestra mediante un printf.
 */
void cargaForzada();

#endif /* FUNCIONES_H_ */
