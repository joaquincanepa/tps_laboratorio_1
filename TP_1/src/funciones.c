/*
 * calculos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Joaquin Canepa
 */


#include <stdio.h>
#include <stdlib.h>


//Esta funcion devuelve la opcion de mi menu.
int menu()
{
	int opcion;
	printf("\nPor Favor seleccione una opcion del 1 al 6 ");
	printf("\n1. Ingresar Kilometros \n"
		   "2. Ingresar Precio de Vuelos\n"
		   "3. Calcular todos los costos\n"
		   "4. Informar Resultados\n"
		   "5. Carga forzada de datos \n"
		   "6. Salir\n");
	scanf("%d",&opcion);

	return opcion;
}

//Esta funcion pide ademas de un char dos numeros, uno minimo y un maximo para poder validar un numero y retornarlo.
int pedirYvalidar(char texto[],float minmimo, float maximo)
{
	int numero;
	printf("%s",texto);
	scanf("%d",&numero);

	while(numero < minmimo ||numero>maximo)
	{
		printf("\ningresar un numero  valido: ");
		scanf("%d",&numero);
	}


	return numero;
}

//Esta funcion resta dos numeros y te devuelve el resultado.
float calcularDiferencia(float num1, float num2)
{
	float resultado;
	if(num1>num2)
	{
		resultado=num1-num2;
	}else
	{
		resultado=num2-num1;
	}
	return resultado;
}

//Esta funcion multiplica dos numeros y te devuelve el resutlado.
float multiplicar(float operador1, float operador2)
{
	float resultado;
	resultado=operador1*operador2;

	return resultado;
}

//Esta funcion simplemente divide dos numeros y te devuelve el resultado.
float dividir(float operador1, float operador2)
{
	float resultado;
	resultado=operador1/operador2;

	return resultado;
}

//Esta funcion imprime los precios calculados previamente de debito, credito, btc y unitario.
void mostrarCalculos (float debito, float credito, float btc, float precioXkm )
{
	printf(	"\na)Precio con tarjeta de debito: $%.2f"
			"\nb)Precio con tarjeta de credto: $%.2f"
			"\nc)Precio pagando con Bitcoin: %f BTC"
			"\nd)Mostrar precio Unitario: $%.2f",debito,credito,btc,precioXkm);
}




//Esta funcion es exclusivamente para la carga de datos forzada.
void cargaForzada()
{
	float precioAerolineasDebito, precioAerolineasCredito, precioAerolineasEnBitcoin, precioUnitarioAerolineas;
	float precioLatamDebito, precioLatamCredito, precioLatamEnBitcoin, precioUnitarioLatam;
	float diferencia;

	precioAerolineasDebito=multiplicar(162965,0.9);
	precioAerolineasCredito=multiplicar(162965,1.25);
	precioAerolineasEnBitcoin=dividir(162965,4606954.55);
	precioUnitarioAerolineas=dividir(162965,7090);
	precioLatamDebito=multiplicar(159339,0.9);
	precioLatamCredito=multiplicar(159339,1.25);
	precioLatamEnBitcoin=dividir(159339,4606954.55);
	precioUnitarioLatam=dividir(159339,7090);
	diferencia=calcularDiferencia(159339,162965);
	printf("\nPrecio Aerolineas: $%d ",162965);
	mostrarCalculos(precioAerolineasDebito, precioAerolineasCredito, precioAerolineasEnBitcoin, precioUnitarioAerolineas );
	printf("\n\nPrecio Latam: $%d", 159339);
	mostrarCalculos(precioLatamDebito,precioLatamCredito,precioLatamEnBitcoin, precioUnitarioLatam );
	printf("\n\nLa diferencia es: $%.2f ",diferencia);
}
