#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearServicios(eServicio listaServicios[], int tam)
{
    int ids[4] = {20000, 20001, 20002, 20003};
    char descripciones[4][26] = {"Limpieza", "Ajuste", "Balanceo", "Cadena"};
    int precios[4] = {250, 300, 17, 190};

    for(int i=0; i<tam; i++)
    {
        listaServicios[i].id = ids[i];
        strcpy(listaServicios[i].descripcion, descripciones[i]);
        listaServicios[i].precio = precios[i];
    }
}
