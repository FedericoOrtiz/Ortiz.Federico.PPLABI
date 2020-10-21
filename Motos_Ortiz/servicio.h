#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    int precio;
}eServicio;

/** \brief hardcodea entidades del tipo eServicio
 *
 * \param listaServicios[] array de servicios
 * \param tam tamanio del array
 *
 */
void hardcodearServicios(eServicio listaServicios[], int tam);

/** \brief muestra una entidad eServicio
 *
 * \param servicio servicio a mostrar
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief muestra los servicios ingresados al sistma
 *
 * \param listaServicios[] array de servicios
 * \param tam tamanio del array
 *
 */
void mostrarServicios(eServicio listaServicios[], int tam);

#endif // SERVICIO_H_INCLUDED
