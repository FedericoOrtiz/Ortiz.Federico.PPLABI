#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
}eColor;

/** \brief hardcodea entidades del tipo eColor
 *
 * \param listadoColores[] array de colores
 * \param tam tamanio del array
 *
 */
void hardcodearColores(eColor listadoColores[], int tam);

/** \brief muestra una entidad de tipo eColor
 *
 * \param color color a mostrar
 *
 */
void mostrarColor(eColor color);

/** \brief muestra los colores ingresados al sistema
 *
 * \param listadoColores[] array de colores
 * \param tam tamanio del array
 *
 */
void mostrarColores(eColor listadoColores[], int tam);

#endif // COLOR_H_INCLUDED
