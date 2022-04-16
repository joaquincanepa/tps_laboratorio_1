/*
 * calculos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Joaquin Canepa
 */


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief
 *
 * @param texto
 * @param minmimo
 * @param maximo
 * @return
 */
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

/**
 * @brief
 *
 * @param num1
 * @param num2
 * @return
 */
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
/**
 * @brief
 *
 * @param operador1
 * @param operador2
 * @return
 */
float multiplicar(float operador1, float operador2)
{
	float resultado;
	resultado=operador1*operador2;

	return resultado;
}
/**
 * @brief
 *
 * @param operador1
 * @param operador2
 * @return
 */
float divir(float operador1, float operador2)
{
	float resultado;
	resultado=operador1/operador2;

	return resultado;
}
/**
 * @brief
 *
 * @param debito
 * @param credito
 * @param btc
 * @param precioXkm
 */
void mostrarCalculos (float debito, float credito, float btc, float precioXkm )
{
	printf(	"\na)Precio con tarjeta de debito: $%.2f"
			"\nb)Precio con tarjeta de credto: $%.2f"
			"\nc)Precio pagando con Bitcoin: $%f BTC"
			"\nd)Mostrar precio Unitario: $%.2f",debito,credito,btc,precioXkm);
}

/**
 * @brief
 *
 * @return
 */
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



