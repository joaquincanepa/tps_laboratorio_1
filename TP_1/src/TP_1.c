/*
 ============================================================================
 Name        : TP1_Canepa_Joaquin.c
 Author      : C?nepa Joaquin.
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
int opcion=-1;
float km;
float precioLatam;
float precioAerolineas;
int banderaPrimerOp=0,banderaSegundaOp=0,banderaTercerOp=0;
float diferencia;
float precioAerolineasDebito, precioAerolineasCredito, precioAerolineasEnBitcoin, precioUnitarioAerolineas;
float precioLatamDebito, precioLatamCredito, precioLatamEnBitcoin, precioUnitarioLatam;

while(opcion!=0)
	{
		opcion=menu();
		switch(opcion)
		{
			case 1://ingresar y validar km.
				km=pedirYvalidar("\nIngrese los kilometros entre 8 y 16000:",8,16000);
				banderaPrimerOp=1;
				printf("kilometros ingresados !!");
				break;
			case 2://ingresar y validar precios.
				if(banderaPrimerOp==1)
				{
					precioAerolineas=pedirYvalidar("\nIngrese Precio de vuelos Aerolineas entre 2000 y 500000:",2000,500000);
					precioLatam=pedirYvalidar("\nIngrese Precio de Latam entre 2000 y 500000:",2000,500000);
					banderaSegundaOp=1;
					printf("kilometros ingresados y Precios ingresados !!");
				}
				else{
					printf("Error debe ingresar primero los km\n");
				}
				break;
			case 3://calcular costos
				if(banderaPrimerOp==1 && banderaSegundaOp==1)
				{
					precioAerolineasDebito=multiplicar(precioAerolineas,0.9);
					precioAerolineasCredito=multiplicar(precioAerolineas,1.25);
					precioAerolineasEnBitcoin=dividir(precioAerolineas,4606954.55);
					precioUnitarioAerolineas=dividir(precioAerolineas,km);
					precioLatamDebito=multiplicar(precioLatam,0.9);
					precioLatamCredito=multiplicar(precioLatam,1.25);
					precioLatamEnBitcoin=dividir(precioLatam,4606954.55);
					precioUnitarioLatam=dividir(precioLatam,km);
					diferencia=calcularDiferencia(precioLatam,precioAerolineas);
					banderaTercerOp=1;
					printf("\n Calculos Realizados, ingrese la opcion 4 para ver los resultados!!");
				}
				else if(banderaPrimerOp==1 && banderaSegundaOp==0)
				{
					printf("Error, Faltan ingresar los precios de los vuelos\n");
				}
				else if(banderaPrimerOp==0)
				{
					printf("Error, faltan ingresar los kilometros y los precios \n");
				}
				else{
					printf("Error, faltan ingresar los kilometros y los precios de los vuelos\n");
				}
				break;
			case 4://mostrar costos.
				if(banderaTercerOp==1)
				{
					printf("\nPrecio Aerolineas: $%.2f ",precioAerolineas);
					mostrarCalculos(precioAerolineasDebito, precioAerolineasCredito, precioAerolineasEnBitcoin, precioUnitarioAerolineas );
					printf("\n\nPrecio Latam: $%.2f", precioLatam);
					mostrarCalculos(precioLatamDebito,precioLatamCredito,precioLatamEnBitcoin, precioUnitarioLatam );
					printf("\n\nLa diferencia es: $%.2f ",diferencia);
					opcion=0;
				}else if(banderaPrimerOp==0 || banderaSegundaOp==0){
					printf("Error, No estan ingresados todos los datos necesarios\n");
				}
				else if(banderaTercerOp == 0){
					printf("Error, no estan calculados los costos\n");
				}
				break;
			case 5://carga forzada.
				cargaForzada();
				opcion=0;
				break;
			case 6:
				opcion=0;
				break;
			default:
				printf("Error seleccione una opcion del 1 al 6 ");
				break;
		}
	}
		return 0;
}
