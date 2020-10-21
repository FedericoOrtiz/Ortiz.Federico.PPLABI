#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "moto.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    int isEmpty;
    eFecha fechaTrabajo;
}eTrabajo;

/** \brief inicializa el array de trabajos poniendo el campo isEmpty en 0
 *
 * \param listaTrabajos[] array de trabajos
 * \param tam tamanio del array
 * \return retorna (1) si hay un error [listaTrabajos == NULL || tam<0] - 0 si esta Ok
 *
 */
int inicializarTrabajos(eTrabajo listaTrabajos[], int tam);

/** \brief crea una nueva entidad eTrabajo y la aniade al sistema
 *
 * \param listaTrabajos[] array de trabajos
 * \param tamTrabajos tamanio del array
 * \param id proximo id
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] eColor
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 * \return retorna (1) si hay un error [listaTrabajos == NULL || tam<0] o si no hay espacio - (0) si esta Ok
 *
 */
int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, int id, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes);

/** \brief busca un espacio libre en el array
 *
 * \param listaTrabajos[] array de trabajos
 * \param tam tamanio del array
 * \return retorna (1) si hay un error [listaTrabajos == NULL || tam<0] - (0) si esta Ok
 *
 */
int buscarLibreTrabajo(eTrabajo listaTrabajos[], int tam);

/** \brief muestra una entidad eTrabajo
 *
 * \param trabajo trabajo a mostrar
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio listaServicios[], int tamServicios);

/** \brief muestra todos los trabajos ingresados al sistema
 *
 * \param listaTrabajos[] array de trabajos
 * \param tamTrabajos tamanio del array
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarTrabajos(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes);

/** \brief muestra una moto con sus respectivos trabajos realizados
 *
 * \param listaTrabajos[] array de trabajos
 * \param tamTrabajos tamanio del array
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarUnaMotoConSusTrabajos(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes);

/** \brief muestra una moto con su importe total de trabajos
 *
 * \param listaTrabajos[] array de trabajos
 * \param tamTrabajos tamanio del array
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarUnaMotoConImporteTotal(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes);

/** \brief muestra todas las motos a las cuales se les haya realizado un servicio seleccionado por el usuario
 *
 * \param listaTrabajos[] array de trabajos
 * \param tamTrabajos tamanio del array
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMotosDeUnServicio(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes);

/** \brief muestra los trabajos realizados en una fecha ingresada por el usuario
 *
 * \param listaTrabajos[] array de trabajos
 * \param tamTrabajos tamanio del array
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaServicios[] array de servicios
 * \param tamServicios tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarTrabajosPorFecha(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes);

/** \brief hardcodea 4 entidades del tipo eTrabajo
 *
 * \param listaTrabajos[] array de trabajos
 * \return void
 *
 */
void hardcodearTrabajos(eTrabajo listaTrabajos[]);

#endif // TRABAJO_H_INCLUDED
