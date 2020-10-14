#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearColores(eColor listadoColores[], int tam)
{
    int ids[5] = {10000, 10001, 10002, 10003, 10004};
    char colores[5][21] = {"Gris", "Negro", "Blanco", "Azul", "Rojo"};

    for(int i=0; i<tam; i++)
    {
        listadoColores[i].id = ids[i];
        strcpy(listadoColores[i].nombreColor, colores[i]);
    }
}

void mostrarColor(eColor color)
{
    printf("%5d %8s\n", color.id, color.nombreColor);
}

void mostrarColores(eColor listadoColores[], int tam)
{
    if(listadoColores != NULL && tam>0)
    {
        printf("   ID   COLOR\n\n");
        for(int i=0; i<tam; i++)
        {
            mostrarColor(listadoColores[i]);
        }
    }
    printf("\n");
}
