#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearClientes(eCliente listaClientes[], int tam)
{
    int ids[5] = {10,11,12,13,14};
    char nombres[5][30] = {"Juan", "Maria", "Alberto", "Mariano", "Marcela"};
    char sexos[5] = {'m', 'f', 'm', 'm', 'f'};

    for(int i=0; i<tam; i++)
    {
        listaClientes[i].id = ids[i];
        strcpy(listaClientes[i].nombre, nombres[i]);
        listaClientes[i].sexo = sexos[i];
    }
}

void mostrarCliente(eCliente unCliente)
{
    printf("%4d %12s %6c\n", unCliente.id, unCliente.nombre, unCliente.sexo);
}

void mostrarClientes(eCliente listaClientes[], int tam)
{
    if(listaClientes != NULL && tam>0)
    {
        printf("\n  ID       NOMBRE   SEXO\n\n");
        for(int i=0; i<tam; i++)
        {
            mostrarCliente(listaClientes[i]);
        }
        printf("\n");
    }
}
