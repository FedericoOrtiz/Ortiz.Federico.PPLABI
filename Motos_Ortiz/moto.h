#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "cliente.h"


typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int idCliente;
    int isEmpty;
}eMoto;

/** \brief Inicializa el array de motos poniendo el campo isEmpty en 0
 *
 * \param listaMotos[] array de motos
 * \param tam tamanio del array
 * \return retorna (1) si hay un error [listaMotos == NULL || tam<0] - 0 si esta Ok
 *
 */
int inicializarMotos(eMoto listaMotos[], int tam);

/** \brief hardcodea 5 entidadades de tipo eMoto
 *
 * \param listaMotos[] array de motos
 *
 */
void hardcodearMotos(eMoto listaMotos[]);

/** \brief busca un espacio libre en el array
 *
 * \param listaMotos[] array de motos
 * \param tam tamanio del array
 * \return retorna (1) si hay un error [listaMotos == NULL || tam<0] - (0) si esta Ok
 *
 */
int buscarLibreMoto(eMoto listaMotos[], int tam);

/** \brief crea una nueva entidad eMoto y la aniade al sistema
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param id proximo id
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 * \return retorna (1) si hay un error [listaMotos == NULL || tam<0] o si no hay espacio - (0) si esta Ok
 *
 */
int altaMoto(eMoto listaMotos[], int tamMotos, int id, eTipo listaTipos[], int tamTipos, eColor listaColores[], int tamColores, eCliente listaClientes[], int tamClientes);


/** \brief muestra una entidad de tipo eMoto
 *
 * \param moto entidad a mostrar
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMoto(eMoto moto, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);


/** \brief muestra todas las motos ingresadas al sistema
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMotos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief busca una moto por su Id
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 * \return retorna su indice en el array - (-1) si hay un error [listaMotos == NULL || tam<0]
 *
 */
int buscarMotoPorId(eMoto listaMotos[], int tamMotos, int id, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief permite al usuario modificar los campos color y cilindrada de una moto
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void modificarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief permite al usuario eliminar una moto al seleccionarla por id
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 * \return retorna (1) si hay un error [listaMotos == NULL || tam<0] o si se cancela la baja - (0) si esta Ok
 *
 */
int eliminarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief muestra las motos de un color seleccionado por el usuario
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMotosDeUnColor(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief muestra las motos de un tipo seleccionado por el usuario
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMotosDeUnTipo(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief muestra las motos de la mayor cilindrada registrada
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMotosMayorCilindrada(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief muestra todas las motos divididas por tipo
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarMotosPorTipo(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief muestra la cantidad de motos de un color y tipo seleccionados por el usuario
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarCantidadMotosDeUnColorYUnTipo(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

/** \brief muestra los colores de moto mas elegidos por los clientes
 *
 * \param listaMotos[] array de motos
 * \param tamMotos tamanio del array
 * \param listaColores[] array de colores
 * \param tamColores tamanio del array
 * \param listaTipos[] array de tipos de moto
 * \param tamTipos tamanio del array
 * \param listaClientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarColoresMasElegidos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes);

#endif // MOTO_H_INCLUDED
