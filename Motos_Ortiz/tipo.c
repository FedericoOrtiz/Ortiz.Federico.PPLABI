#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearTipos(eTipo listadoTipos[], int tam)
{
    int ids[4] = {1000, 1001, 1002, 1003};
    char tipos[4][21] = {"Enduro", "Chopera", "Scooter", "Ciclomotor"};

    for(int i=0; i<tam; i++)
    {
        listadoTipos[i].id = ids[i];
        strcpy(listadoTipos[i].descripcion, tipos[i]);
    }
}

void mostrarTipo(eTipo tipo)
{
    printf("%4d %12s\n", tipo.id, tipo.descripcion);
}

void mostrarTipos(eTipo listadoTipos[], int tam)
{
    if(listadoTipos != NULL && tam>0)
    {
        printf("  ID        TIPO\n\n");
        for(int i=0; i<tam; i++)
        {
            mostrarTipo(listadoTipos[i]);
        }
    }
    printf("\n");
}
