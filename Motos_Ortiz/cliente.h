#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char sexo;
}eCliente;

/** \brief hardcodea entidades del tipo eCliente
 *
 * \param listaClientes[] array de clientes
 * \param tam tamanio del array
 *
 */
void hardcodearClientes(eCliente listaClientes[], int tam);

/** \brief muestra una entidad de tipo eCliente
 *
 * \param unCliente cliente a mostrar
 *
 */
void mostrarCliente(eCliente unCliente);

/** \brief muestra los clientes ingresados al sistema
 *
 * \param listaClientes[] array de clientes
 * \param tam tamanio del array
 *
 */
void mostrarClientes(eCliente listaClientes[], int tam);

#endif // CLIENTE_H_INCLUDED
