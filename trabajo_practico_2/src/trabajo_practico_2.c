/*
 ============================================================================
 Name        : trabajo_practico_2.c
 Author      : Joaquin Canepa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#include "funciones.h"
#define TAM 2000
#define TAM_ESTADO 2
#define TAM_TIPO_PASAJERO 3



int main(void) {
	setbuf(stdout, NULL);


	ePassenger Pasajeros[TAM], auxPasajero;
	eTypePassenger TipoPasajeros[TAM_TIPO_PASAJERO] = {{1, "Turista"}, { 2, "Ejecutivo"}, {3, "Primera clase"}};
	eStatusFlight EstadoReserva[TAM_ESTADO] = {{1, "Activo"}, {2, "Cancelado"}};
	int opcion=-1;
	int id = 1000;
	int idAux;
	int cantPasajeros = 0;
	int auxRemover;
	int resultadoAux;
	int respuestaAdd=-1;
	int auxFind=-1;


	initPassengers(Pasajeros, TAM);
	while(opcion!=0)
	{
		opcion = menu();

		switch(opcion){
			case 1:
				auxFind = findPassengerIndex(Pasajeros, TAM);
				if( auxFind>-1){
					auxPasajero = askPassengerData(id, TipoPasajeros, TAM_TIPO_PASAJERO);
					respuestaAdd = addPassenger(Pasajeros, auxFind, auxPasajero.id, auxPasajero.name, auxPasajero.lastName, auxPasajero.price, auxPasajero.typePassenger, auxPasajero.flycode);

					if(respuestaAdd == 0){
						cantPasajeros++;
						id++;
						printf("Agregaste un pasajero !!.\n");
						respuestaAdd = -1;
					}
					auxFind = -1;
				} else {
					printf("No hay espacio, Vuelo completo\n");
				}
				break;
			case 2:

				if(cantPasajeros > 0){
					getInt(&idAux, "Ingrese id del pasajero a modificar", "Error, reintente nuevamente", 1, 1000000, 5);
					auxFind = findPassengerById(Pasajeros, TAM, idAux);
					if(auxFind > -1){
						changePassengerData(Pasajeros, TAM, auxFind, TipoPasajeros, TAM_TIPO_PASAJERO);
					} else {
						printf("Error el codigo ingresado, no esta ingresado correctamente\n");
					}
					auxFind = -1;


				} else{
					printf("Error, primero debe ingresar un pasajero\n");
				}

			break;
			case 3:

				if(cantPasajeros > 0){
					getInt(&auxRemover, "Ingrese id del pasajero que desea borrar:", "Error, reingrese un numero mayor a 0", 0, 100000, 5);
					resultadoAux = removePassenger(Pasajeros, TAM, auxRemover);
					if(resultadoAux == 0 ){
						printf("Pasajero Borrado !!!\n");
					} else{
						printf("Error no se ha podido borrar el pasajero\n");
					}

				} else {
					printf("Error, primero debe ingresar un pasajero\n");
				}

			break;
			case 4:

				if(cantPasajeros > 0){

					printsInformes(Pasajeros, TAM, TipoPasajeros, TAM_TIPO_PASAJERO, EstadoReserva, TAM_ESTADO);

				} else {
					printf("Error, primero debe ingresar un pasajero\n");
				}
			break;
			case 5:
				opcion=0;
				break;

			default:
				printf("Error seleccione una opcion del 1 al 5 ");
			break;
		}
	}

}
