#include "marca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearMarcas(eMarca listaMarcas[], int tam)
{
    int idsMarcas[5] = {50000, 50001, 50002, 50003, 50004};
    char marcas[5][21] =  {"Zanella", "Honda", "Yamaha", "Kawasaki", "Ducati"};

    for(int i=0; i<tam; i++)
    {
        listaMarcas[i].id = idsMarcas[i];
        strcpy(listaMarcas[i].marca, marcas[i]);
    }
}

void mostrarMarca(eMarca marca)
{
    printf("%5d %8s\n", marca.id, marca.marca);
}

void mostrarMarcas(eMarca listaMarcas[], int tam)
{
    if(listaMarcas !=NULL && tam>0)
    {
        printf("  ID MARCAS\n\n");
        for(int i=0; i<tam; i++)
        {
            mostrarMarca(listaMarcas[i]);
        }
        printf("\n");
    }
}
