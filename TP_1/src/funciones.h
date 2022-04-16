/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Joaquin Canepa.
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


int pedirYvalidar(char texto[],float minmimo, float maximo);

float calcularDiferencia(float num1, float num2);

float multiplicar(float operador1, float operador2);

float divir(float operador1, float operador2);

void mostrarCalculos (float debito, float credito, float btc, float precioXkm);

int menu();

#endif /* FUNCIONES_H_ */