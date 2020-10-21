#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
}eTipo;

/** \brief hardcodea entidades del tipo eTipo
 *
 * \param listadoTipos[] array de tipos de moto
 * \param tam tamanio del array
 *
 */
void hardcodearTipos(eTipo listadoTipos[], int tam);

/** \brief muestra una entidad eTipo
 *
 * \param tipo tipo de moto a mostrar
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief muestra los tipos de moto ingresados al sistema
 *
 * \param listadoTipos[] array de tipos de moto
 * \param tam tamanio del array
 *
 */
void mostrarTipos(eTipo listadoTipos[], int tam);

#endif // TIPO_H_INCLUDED


