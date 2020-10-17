#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"

int inicializarTrabajos(eTrabajo listaTrabajos[], int tam)
{
    int error = 1;

    if(listaTrabajos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            listaTrabajos[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}

int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, int id, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios)
{
    int error = 1;
    int indice = buscarLibreTrabajo(listaTrabajos, tamTrabajos);
    eTrabajo nuevoTrabajo;

    if(listaTrabajos != NULL && tamTrabajos > 0 && indice != -1)
    {
        printf("  *** ALTA TRABAJO ***\n\n");

        nuevoTrabajo.id = id;
        nuevoTrabajo.isEmpty = 0;

        mostrarMotos(listaMotos, tamMotos, listaColores, tamColores, listaTipos, tamTipos);
        nuevoTrabajo.idMoto = getInt(30000, 39999, "Ingrese ID de la moto: ");
        mostrarServicios(listaServicios, tamServicios);
        nuevoTrabajo.idServicio = getInt(20000, 20003, "Ingrese ID del servicio: ");
        nuevoTrabajo.fechaTrabajo.dia = getInt(1, 31, "Ingrese dia: ");
        nuevoTrabajo.fechaTrabajo.mes = getInt(1, 12, "Ingrese mes: ");
        nuevoTrabajo.fechaTrabajo.anio = getInt(2020, 2030, "Ingrese anio: ");

        listaTrabajos[indice] = nuevoTrabajo;
        error = 0;
    }

    return error;
}

int buscarLibreTrabajo(eTrabajo listaTrabajos[], int tam)
{
    int indice = -1;

    if(listaTrabajos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listaTrabajos[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

void mostrarTrabajo(eTrabajo trabajo, eMoto listaMotos[], int tamMotos, int id, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios)
{
    char servicio[26];

    printf("  *** TRABAJOS ***\n");
    buscarMotoPorId(listaMotos, tamMotos, trabajo.idMoto, listaColores, tamColores, listaTipos, tamTipos);

    for(int i=0; i<tamServicios; i++)
    {
        if(trabajo.idServicio == listaServicios[i].id)
        {
            strcpy(servicio, listaServicios[i].descripcion);
            break;
        }
    }
    printf("\n   ID   SERVICIO        FECHA\n\n");
    printf("%5d %10s   %2d/%2d/%4d \n\n", trabajo.id, servicio,trabajo.fechaTrabajo.dia, trabajo.fechaTrabajo.mes, trabajo.fechaTrabajo.anio);
    printf("-------------------------------------------------------------------------\n\n");
}

void mostrarTrabajos(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios)
{
    if(listaTrabajos != NULL && tamTrabajos > 0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(listaTrabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(listaTrabajos[i], listaMotos, tamMotos, listaTrabajos[i].idMoto, listaColores, tamColores, listaTipos, tamTipos, listaServicios, tamServicios);
            }
        }
        printf("\n");
    }
}
