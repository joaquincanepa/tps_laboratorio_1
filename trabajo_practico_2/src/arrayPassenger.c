/*
 * arrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: joaquin Canepa
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#include "funciones.h"

/*
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(ePassenger* list, int TAM)
{
	int i;
	int retorno = -1;
	if(list != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++){
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}



int addPassenger(ePassenger* list, int index, int id, char* name, char* lastName, float price, int typePassenger, char* flycode)
{
	int retorno = -1;

	if( list != NULL && id > -1) {

		retorno = 0;

		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		strcpy(list[index].flycode, flycode);
		list[index].isEmpty = 0;
		list[index].statusFlight = 1;

	}
	return retorno;
}


int findPassengerById(ePassenger* list, int TAM,int id) {

	int index = -1;
	int i;
	if(list != NULL && TAM > 0 && id > 0){
		for(i = 0; i < TAM; i++){

			if(list[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}



int findPassengerIndex(ePassenger* list, int TAM)
{
	int index = -1;
	int i;

	if(list != NULL && TAM > 0) {
		for(i = 0; i < TAM; i++){
			if( list[i].isEmpty == 1) {
				index = i;
				break;
			}
		}

	}
	return index;
}



int removePassenger(ePassenger* list, int TAM, int id)
{
	int index;
	int retorno = -1;
	index = findPassengerById(list, TAM, id);

	if(index > -1 && list != NULL && id > -1){
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}


int sortPassenger(ePassenger* list, int TAM){

	int i, j, retorno;
	ePassenger pasajerosOrdenado;
	retorno = -1;

	if(list != NULL && TAM > 0 ){
		retorno = 0;
		for(i = 0; i < TAM-1; i++) {

			for(j = 1; j < TAM; j++)

				if( list[i].isEmpty == 0 &&
						(strcmp(list[i].lastName, list[j].lastName) < 1 ||
						(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].typePassenger > list[j].typePassenger)
						)) {
					pasajerosOrdenado = list[i];
					list[i] = list[j];
					list[j] = pasajerosOrdenado;
				}


		}
	}
	return retorno;
}


int printPassenger(ePassenger* list, int TAM, eTypePassenger* tipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus) {
	int i, j, k, retorno;
	retorno = -1;

	if(list != NULL && TAM > 0 && tipoPasajero != NULL && lenTipoPasajero > 0){
		retorno = 0;

		printf("\n===================================================================================================================\n");
		printf("| Id  |      Apellido      |       Nombre       |   Precio   | Codigo de Vuelo |  Tipo de Pasajero  |  Estado de Reserva |\n");
		printf("===================================================================================================================\n");
		for(i = 0; i < TAM; i++) {

			for(j = 0 ; j < lenTipoPasajero; j++){

				for(k = 0; k < lenStatus; k++){

					if(		list[i].isEmpty == 0 &&
							list[i].typePassenger == tipoPasajero[j].typePassenger
							&& list[i].statusFlight == status[k].statusFlight){

						printf("| %-3d | %-18s | %-18s | %10.2f | %-10s | %-18s | %-18s |\n", list[i].id,
								list[i].lastName, list[i].name, list[i].price, list[i].flycode,
								tipoPasajero[j].description, status[k].statusDescription);
						break;
					}
				}
			}
		}
		printf("===================================================================================================================\n");
	}
	return retorno;
}



int sortPassengerByFlyCode(ePassenger* list, int TAM){

	int i, j, retorno;
	ePassenger pasajerosOrdenado;
	retorno = -1;

	if(list != NULL && TAM > 0 ){
		retorno = 0;
		for(i = 0; i < TAM-1; i++) {

			for(j = 1; j < TAM; j++)

				if( list[i].isEmpty == 0 &&
					(strcmp(list[i].flycode, list[j].flycode) < 1)) {

					pasajerosOrdenado = list[i];
					list[i] = list[j];
					list[j] = pasajerosOrdenado;
				}
		}
	}
	return retorno;
}



ePassenger askPassengerData(int id, eTypePassenger* TipoPasajero, int lenTipoPasajero)
{
	ePassenger list;

	printf("Ingrese los datos del pasajero");// 162);
	printf("\nCodigo del pasajero registrado:%d",id);

	list.id=id;

	getString(list.name, "Ingrese el nombre del pasajero:", "Error, reintente nuevamente", 51, 5);

	getString(list.lastName, "Ingrese el apellido del pasajero:", "Error, reintente nuevamente", 51, 5);

	getFloat(&list.price, "Ingrese el precio del vuelo:", "Error, reintente nuevamente", 0, 1000000, 5);


	printf("Por favor Ingrese el tipo de vuelo:\n");
	printTipoPasajero(TipoPasajero, lenTipoPasajero);
	getInt(&list.typePassenger, "", "Error, reintente nuevamente", 1, 100, 5);

	getString(list.flycode, "Ingrese el código del vuelo:", "Error, reintente nuevamente", 11, 5);

	return list;
}



int printTipoPasajero(eTypePassenger* list, int TAM)
{
	int i, retorno;
	retorno = -1;

	if(list != NULL && TAM > 0){

		printf("*****Tipos de vuelos:*****\n");
		printf("|===========================|\n");
		printf("| Código | Descripción      |\n");
		printf("|===========================|\n");
		for(i = 0; i < TAM; i++) {
			printf("| %-6d | %-17s|\n", list[i].typePassenger, list[i].description);
			printf("|===========================|\n");
		}
		retorno = 0;
	}
	return retorno;
}


int changePassengerData(ePassenger* list, int TAM, int index, eTypePassenger* TipoPasajero, int lenTipoPasajero){

	int retorno;
	int opcion;
	char banderaSalir;
	banderaSalir = 'N';
	retorno = -1;

	if(list != NULL && TAM > 0 && index > -1){

		retorno = 0;
		do{
			opcion = menuModificar();

			switch(opcion){
				case 1:
					printf("Nombre a modificar: %s", list[index].name);
					getString(list[index].name, "Ingrese nuevamente el NOMBRE:", "Error, reintente nuevamente", 51, 5);
				break;
				case 2:
					printf("Apellido a modificar: %s", list[index].lastName);
					getString(list[index].lastName, "Ingrese nuevamente el APELLIDO:", "Error, reintente nuevamente", 51, 5);
				break;
				case 3:
					printf("Precio a modificar: %.2f", list[index].price);
					getFloat(&list[index].price, "Ingrese nuevamente el precio del pasaje:", "Error, reintente nuevamente", 0, 1000000, 5);
				break;
				case 4:
					printf("Codigo del tipo de vuelo a modificar: %d\n", list[index].typePassenger);
					printf("Ingrese nuevamente el codigo del tipo de vuelo\n");
					printTipoPasajero(TipoPasajero, lenTipoPasajero);
					getInt(&list[index].typePassenger, "", "Error, reintente nuevamente", 1, 100, 5);
				break;
				case 5:
					printf("Código de vuelo a modificar: %s", list[index].flycode);
					getString(list[index].flycode, "Ingrese nuevamente el código de vuelo:", "Error, reintente nuevamente", 11, 5);
				break;
				case 6:
					printf("\nSalio del submenu modificar");
					banderaSalir ='S';

				break;
				default:
					printf("Error seleccione una opcion del 1 al 6");
					break;
				}
			} while(banderaSalir != 'S');

	}
	return retorno;
}


int makeCalculation(ePassenger* list, int TAM){

	int i,  retorno, pasajeroSuperanPrecioPromedio, cantidad;
	retorno = -1;
	float total = 0.0;
	float promedio = 0.0;
	cantidad = 0;
	pasajeroSuperanPrecioPromedio = 0;

	if(list != NULL && TAM > 0 ){
		retorno = 0;

		for(i = 0; i < TAM-1; i++) {
			if( list[i].isEmpty == 0) {
				total = total + list[i].price;
				cantidad++;
			}
		}
		if(cantidad > 0){

			promedio = total / (float)cantidad;

			for(i = 0; i < TAM-1; i++) {
				if( list[i].isEmpty == 0 && list[i].price > promedio) {

					pasajeroSuperanPrecioPromedio++;
				}
			}

			printf("Calculos de pasajes.\n");
			printf("El total de precios es : %.2f\n El promedio de los precios: %.2f\n", total, promedio);
			printf("La cantidad de pasajeros que supera el promedio es: %d.\n", pasajeroSuperanPrecioPromedio);

		} else {
			printf("Error cargue pasajeros.\n");
		}

	}
	return retorno;
}


int filterPassenger(ePassenger* list, ePassenger* auxiliar, int TAM){

	int i, retorno;
	retorno = -1;

	initPassengers(auxiliar, TAM);

	if(list != NULL && TAM > 0 ){

		for(i = 0; i < TAM-1; i++) {
			if( list[i].isEmpty == 0 && list[i].statusFlight == 1 ){
				auxiliar[i] = list[i];
			}
		}

		retorno = 0;
	}
	return retorno;
}


int printsInformes(ePassenger* list, int TAM, eTypePassenger* TipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus)
{

	int retorno;
	char opcion;
	char banderaSalir;
	ePassenger auxiliar[TAM];

	banderaSalir = 'N';
	retorno = -1;

	if(list != NULL && TAM > 0){

		retorno = 0;
		do{

			opcion = menuInforme();

			switch(opcion){
				case '1':
					sortPassenger(list, TAM);
					printPassenger(list, TAM, TipoPasajero, lenTipoPasajero, status, lenStatus);
				break;
				case '2':
					makeCalculation(list, TAM);
				break;
				case '3':
					filterPassenger(list, auxiliar, TAM);
					sortPassengerByFlyCode(auxiliar, TAM);
					printPassenger(auxiliar, TAM, TipoPasajero, lenTipoPasajero, status, lenStatus);
				break;
				case '4':
					printf("salio del submenu informe");
					banderaSalir='S';


				break;
				}
			} while(banderaSalir != 'S');

	}
	return retorno;
}
