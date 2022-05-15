/*
 * arrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: joaquin Canepa
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int typePassenger;
	char description[40];
} eTypePassenger;

typedef struct{
	int statusFlight;
	char statusDescription[40];
} eStatusFlight;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} ePassenger;



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int TAM);


/**\brief add in a existing list of passengers the values received as parameters
* in the first empty position
 * @param list
 * @param index
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flycode
 * @return
 */
int addPassenger(ePassenger* list, int index, int id, char* name, char* lastName, float price, int typePassenger, char* flycode);


/// \brief find a Passenger by Id en returns the index position in array.
/// \param list Passenger*
/// \param len int
/// \param id int
/// \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
int findPassengerById(ePassenger* list, int TAM,int id);



/// \brief busca un espacio libre en el array de pasajeros
/// \param list passenger*
/// \param len int largo del array ePassenger
/// \return int Return (-1) if Error [Return index if Ok]
int findPassengerIndex(ePassenger* list, int TAM);


/// \brief Remove a Passenger by Id (put isEmpty Flag in 1)
/// \param list Passenger*
/// \param len int
/// \param id int
/// \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int removePassenger(ePassenger* list, int TAM, int id);

/// \brief ordena el Array de pasajero por apellido y código de pasajero ambos de forma ascendente.
/// \param puntero de ePassenger
/// \param len: largo del array ePassenger
/// \return un entero -1 para error  0 para OK
int sortPassenger(ePassenger* list, int TAM);


/// \brief imprime los pasajeros cargados
/// \param puntero de ePassenger
/// \param TAM: largo del array ePassenger
/// \param puntero de eTypePassenger
/// \param lenTipoPasajero del array de tipo de pasajero
/// \return retorna 0 si esta bien
int printPassenger(ePassenger* list, int TAM, eTypePassenger* tipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus);



/// \brief Esta funcion ordena el Array de pasajero por codigo de vuelo.
/// \param puntero de ePassenger
/// \param TAM: tamanio del arrayr
/// \return retorna 0 si esta bien
int sortPassengerByFlyCode(ePassenger* list, int TAM);



/// \brief  cargar un pasajero
/// \param id para modificar
/// \param eTypePassenger array del tipo de pasajero
/// \param lenTipoPasajero tamanio del array
/// \return retorna el auxiliarPasenger
ePassenger askPassengerData(int id, eTypePassenger* TipoPasajero, int lenTipoPasajero);



/// \brief imprime los tipos de pasajeros
/// \param puntero de eTypePassenger
/// \param TAM largo del array
/// \return retorna un entero
int printTipoPasajero(eTypePassenger* list, int TAM);

/// \brief modifica los datos
/// \param puntero de ePassenger
/// \param TAM del array Passenger
/// \param index indice a modificar
/// \param puntero de eTipoPasajero
/// \param lenTipoAlbum del array de LenTipoPasajero
/// \return retorna un entero
int changePassengerData(ePassenger* list, int TAM, int index, eTypePassenger* TipoPasajero, int lenTipoPasajero);




/// \brief Calcula total, promedio de los precios y ademas cuántos pasajeros superan el precio promedio.
/// \param array de pasajeros
/// \param TAM de pasajeros
/// \return retorna 0 si esta todo ok
int makeCalculation(ePassenger* list, int TAM);

/// \brief filtra el array por estado activo.
/// \param puntero de ePassenger
/// \param TAM: tamanio del array ePassenger
/// \return retorna 0 si esta todo ok
int filterPassenger(ePassenger* list, ePassenger* auxiliar, int TAM);



/**
 * @brief muestra la informacion acorde a la elección del usuario.
 *
 * @param list puntero de ePassenger
 * @param TAM tamanio del array de pasajeros
 * @param TipoPasajero TipoPasajeros(turista,etc)
 * @param lenTipoPasajero TAM_TIPO_PASAJERO
 * @param status EstadoReserva(activo,cancelado)
 * @param lenStatus TAM_ESTADO
 * @return
 */
int printsInformes(ePassenger* list, int TAM, eTypePassenger* TipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus);


#endif /* ARRAYPASSENGER_H_ */
