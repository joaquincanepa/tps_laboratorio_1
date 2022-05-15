/*
 * funciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: joaco
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#include "funciones.h"



//Esta funcion devuelve la opcion de mi menu.
int menu(){

	int opcion;

	printf("\nMENU PRINCIPAL:\n\n");
	printf("1) Ingresar Pasajero\n");
	printf("2) Modificar datos del pasajero\n");
	printf("3) Dar de baja un pasajero\n");
	printf("4) Informacion\n");
	printf("5) Salir\n");
	printf("6) Carga forzada\n");
	scanf("%d", &opcion);
	return opcion;

}

//Esta funcion devuelve la opcion de mi SubmenuModificar.
int menuModificar(){
	int opcion;

	printf("\nUSTED ESTA EN EL MENU DE MODIFICACIONES. ¿QUE DESEA MODIFICAR?:\n\n");// 163);
	printf("1) Nombre\n");
	printf("2) Apellido\n");
	printf("3) Precio\n");
	printf("4) Tipo de vuelo\n");
	printf("5) Codigo de vuelo\n");
	printf("6) Salir\n");
	scanf("%d", &opcion);
	return opcion;


}


//Esta funcion devuelve la opcion de mi SubmenuInforme.
char menuInforme(){
	char opcion;

	printf("\n¿QUE DESEA INFOMAR?:\n\n");
	printf("1) Listado de pasajeros por orden alfabetico y tipo de pasajero.\n");
	printf("2) Total y promedio de los precios de los pasajes.\n");
	printf("3) Listado de pasajeros por codigo de vuelo .\n");
	printf("4) SALIR\n");

	fflush(stdin);
	scanf("%c", &opcion);

	while(opcion < '1' || opcion > '4'){
		printf("Error, reingrese opciones (1 a 4)\n");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	return opcion;
}




int getFloat(float *valor, char *mensaje, char *mensajeError, int min, int max, int reintentos){

	int retorno = -1;
    char datoIngresado[40];
	int flagEsValido;
	float auxValor;

	if(valor != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 ) {

		retorno = 0;

		do{
			printf("\n%s", mensaje);

			myGets(datoIngresado, 40);

			flagEsValido = isFloat(datoIngresado);

			if (flagEsValido){
				auxValor = atof(datoIngresado);

				if(auxValor >= min && auxValor <= max) {

					*valor = auxValor;
					retorno = 1;
					break;
				}

			}
			printf("\n%s\n", mensajeError);
			reintentos--;

		} while(reintentos >= 0 );
	}

	return retorno;
}



int getInt(int *lugar, char *mensaje, char *mensajeError, int min, int max, int reintentos){

	int retorno = -1;
    char datoIngresado[100];
	int flagEsValido;
	int auxValor;

	if(lugar != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 ) {

		retorno = 0;

		do{
			printf("\n%s", mensaje);

			myGets(datoIngresado, 100);

			flagEsValido = isFloat(datoIngresado);

			if (flagEsValido){
				auxValor = atoi(datoIngresado);

				if(auxValor >= min && auxValor <= max) {

					*lugar = auxValor;
					retorno = 1;
					break;
				}

			}
			printf("\n%s", mensajeError);
			reintentos--;

		} while(reintentos >= 0 );
	}

	return retorno;
}



int getString(char *lugar, char *mensaje, char *mensajeError, int limite, int reintentos){

	int retorno = -1;
    char datoIngresado[limite];
	int flagEsValido;

	if(lugar != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0 ) {

		retorno = 0;

		do{
			printf("\n%s", mensaje);

			flagEsValido = myGets(datoIngresado, limite);


			if (flagEsValido == 1){
				strncpy(lugar, datoIngresado, limite);
				retorno = 1;
				break;

			}
			printf("\n%s", mensajeError);
			reintentos--;

		} while(reintentos >= 0 );
	}

	return retorno;
}



//Esta funcion Valida si un dato ingresado es un flotante válido
int isFloat(char* cadena) {

	int contadorPuntos = 0;
    int i, largoCadena;
    int retorno = -1;
	largoCadena = strlen(cadena);

	if(cadena != NULL && largoCadena > 0){

		retorno = 1;

		for(i = 0; i < largoCadena || cadena[i] != '\0'; i++) {

			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}

			if(cadena[i] == '.') {
				contadorPuntos++;
				continue;
			}

			if(cadena[i] > '9' || cadena[i] < '0' || contadorPuntos > 1){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*
 Esta funcion Valida si un dato ingresado es un entero válido
 */
int isInt(char* cadena) {

	int retorno = -1;
	int i, largoCadena;

	largoCadena = strlen(cadena);
	if(cadena != NULL && largoCadena > 0){

		retorno = 1;

		for(i = 0; i < largoCadena || cadena[i] != '\0'; i++) {

			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}

			if(cadena[i] > '9' || cadena[i] < '0' ){
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}



 //Esta funcione Pide un dato por consola y lo guarda en una variable de forma segura
int myGets(char *array, int limite) {

	int retorno = -1;
	char bufferString[4024];

	if( array != NULL && limite > 0){

		retorno = 0;

		fflush(stdin);

		if( fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if( bufferString[ strlen(bufferString) -1] == '\n'){
				bufferString[ strlen(bufferString) -1] = '\0';
			}
			if(strlen(bufferString) <= limite)
			{
				strncpy(array, bufferString, limite);
				retorno = 1;
			}
		}

	}


	return retorno;
}
