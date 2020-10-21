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

int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, int id, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes)
{
    int error = 1;
    int indice = buscarLibreTrabajo(listaTrabajos, tamTrabajos);
    eTrabajo nuevoTrabajo;

    if(listaTrabajos != NULL && tamTrabajos > 0 && indice != -1)
    {
        printf("\n               *** ALTA TRABAJO ***\n");

        nuevoTrabajo.id = id;
        nuevoTrabajo.isEmpty = 0;

        mostrarMotos(listaMotos, tamMotos, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
        do
        {
        nuevoTrabajo.idMoto = getInt(30000, 39999, "Ingrese ID de la moto: ");
        }while(buscarMotoPorId(listaMotos, tamMotos, nuevoTrabajo.idMoto, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes) == -1);
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

void mostrarTrabajo(eTrabajo trabajo, eServicio listaServicios[], int tamServicios)
{
    char servicio[26];

    for(int i=0; i<tamServicios; i++)
    {
        if(trabajo.idServicio == listaServicios[i].id)
        {
            strcpy(servicio, listaServicios[i].descripcion);
            break;
        }
    }
    printf("%5d %10s   %02d/%02d/%4d \n\n", trabajo.id, servicio,trabajo.fechaTrabajo.dia, trabajo.fechaTrabajo.mes, trabajo.fechaTrabajo.anio);
}

void mostrarTrabajos(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes)
{
    if(listaTrabajos != NULL && tamTrabajos > 0)
    {
        printf("\n               *** TRABAJOS ***\n");
        for(int i=0; i<tamTrabajos; i++)
        {
            if(listaTrabajos[i].isEmpty == 0)
            {
                buscarMotoPorId(listaMotos, tamMotos, listaTrabajos[i].idMoto, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                printf("\n   ID   SERVICIO        FECHA\n\n");
                mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicios);
                printf("-------------------------------------------------------------------------\n");
            }
        }
        printf("\n");
    }
}

void mostrarUnaMotoConSusTrabajos(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes)
{
    if(listaTrabajos != NULL && tamTrabajos>0)
    {
        int idMoto;
        int indice;
        int flag = 0;
        mostrarMotos(listaMotos, tamMotos, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
        idMoto = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");
        indice = buscarMotoPorId(listaMotos, tamMotos, idMoto, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
        printf("\n               *** TRABAJOS ***\n");

        if(indice != -1)
        {
            printf("\n   ID   SERVICIO        FECHA\n\n");
            for(int i=0; i<tamTrabajos; i++)
            {
                if(listaTrabajos[i].idMoto == idMoto && listaTrabajos[i].isEmpty == 0)
                {
                    mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicios);
                    flag = 1;
                }
            }

            if(!flag)
            {
                printf("\nNo se le han realizado trabajos a esta moto\n\n");
            }
        }
        else
        {
            printf("\nNo existe una moto con el ID %d\n\n", idMoto);
        }
    }
}

void mostrarUnaMotoConImporteTotal(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes)
{
    if(listaTrabajos != NULL && tamTrabajos>0)
    {
        int idMoto;
        int indice;
        int flag = 0;
        int importe = 0;
        mostrarMotos(listaMotos, tamMotos, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
        idMoto = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");
        indice = buscarMotoPorId(listaMotos, tamMotos, idMoto, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);

        if(indice != -1)
        {
            for(int i=0; i<tamTrabajos; i++)
            {
                for(int j=0; j<tamServicios; j++)
                {
                    if(listaTrabajos[i].idMoto == idMoto && listaTrabajos[i].idServicio == listaServicios[j].id && listaTrabajos[i].isEmpty == 0)
                    {
                        importe = importe + listaServicios[j].precio;
                        flag = 1;
                    }
                }
            }

            if(!flag)
            {
                printf("\nNo se le han realizado trabajos a esta moto\n\n");
            }
            else
            {
                printf("\nImporte total de los trabajos: $%d\n\n", importe);
            }
        }
        else
        {
            printf("\nNo existe una moto con el ID %d\n\n", idMoto);
        }
    }
}

void mostrarMotosDeUnServicio(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes)
{
    if(listaTrabajos != NULL && tamTrabajos>0)
    {
        int idServicio;
        int flag = 0;
        mostrarServicios(listaServicios, tamServicios);
        idServicio = getInt(20000, 20003, "Ingrese ID del servicio: ");

        for(int i=0; i<tamTrabajos; i++)
        {
            for(int j=0; j<tamMotos; j++)
            {
                if(listaTrabajos[i].idServicio == idServicio &&  listaTrabajos[i].idMoto == listaMotos[j].id && listaTrabajos[i].isEmpty == 0)
                {
                    buscarMotoPorId(listaMotos, tamMotos, listaTrabajos[i].idMoto, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                    printf("\n   ID   SERVICIO        FECHA\n\n");
                    mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicios);
                    printf("-------------------------------------------------------------------------\n");
                    flag = 1;
                }
            }
        }

        if(!flag)
        {
            char servicio[26];
            for(int i=0; i<tamServicios; i++)
            {
                if(idServicio == listaServicios[i].id)
                {
                    strcpy(servicio, listaServicios[i].descripcion);
                    break;
                }
            }

            printf("\nNo se han realizado servicios de %s\n\n", servicio);
        }
    }
}

void mostrarTrabajosPorFecha(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios, eCliente listaClientes[], int tamClientes)
{
    if(listaTrabajos != NULL && tamTrabajos>0)
    {
        eFecha unaFecha;
        int flag = 0;
        unaFecha.dia = getInt(1, 31, "Ingrese dia: ");
        unaFecha.mes = getInt(1, 12, "Ingrese mes: ");
        unaFecha.anio = getInt(2020, 2030, "Ingrese anio: ");

        for(int i=0; i<tamTrabajos; i++)
        {
            if(unaFecha.dia == listaTrabajos[i].fechaTrabajo.dia && unaFecha.mes == listaTrabajos[i].fechaTrabajo.mes && unaFecha.anio == listaTrabajos[i].fechaTrabajo.anio)
            {
                buscarMotoPorId(listaMotos, tamMotos, listaTrabajos[i].idMoto, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                printf("\n   ID   SERVICIO        FECHA\n\n");
                mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicios);
                printf("-------------------------------------------------------------------------\n");
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("\nNo se han realizado servicios el dia %02d/%02d/%4d\n\n", unaFecha.dia, unaFecha.mes, unaFecha.anio);
        }

    }
}

void hardcodearTrabajos(eTrabajo listaTrabajos[])
{
    int ids[4] = {40000, 40001, 40002, 40003};
    int idsMotos[4] = {30000, 30003, 30003, 30004};
    int idsServicios[4] = {20001, 20001, 20003, 20002};
    eFecha fechas[4] = { {2,2,2020}, {3,3,2020}, {5,2,2020}, {7,6,2020} };

    for(int i=0; i<4; i++)
    {
        listaTrabajos[i].isEmpty = 0;
        listaTrabajos[i].id = ids[i];
        listaTrabajos[i].idMoto = idsMotos[i];
        listaTrabajos[i].idServicio = idsServicios[i];
        listaTrabajos[i].fechaTrabajo = fechas[i];
    }

}
