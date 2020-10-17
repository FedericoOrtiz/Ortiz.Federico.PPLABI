#include <stdio.h>
#include <stdlib.h>
#include "moto.h"
#include "Gets.h"
#include <string.h>

int inicializarMotos(eMoto listaMotos[], int tam)
{
    int error = 1;

    if(listaMotos != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            listaMotos[i].isEmpty = 1;
        }

        error = 0;
    }

    return error;
}

int buscarLibreMoto(eMoto listaMotos[], int tam)
{
    int indice = -1;

    if(listaMotos != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listaMotos[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaMoto(eMoto listaMotos[], int tamMotos, int id, eTipo listaTipos[], int tamTipos, eColor listaColores[], int tamColores)
{
    int error = 1;
    int indice = buscarLibreMoto(listaMotos, tamMotos);
    eMoto nuevaMoto;

    if(listaMotos != NULL && tamMotos>0 && indice != -1)
    {
        printf("  *** ALTA MOTO ***\n\n");

        nuevaMoto.id = id;
        nuevaMoto.isEmpty = 0;
        getString(nuevaMoto.marca, 3, 20, "Ingrese marca: ");
        mostrarTipos(listaTipos, tamTipos);
        nuevaMoto.idTipo = getInt(1000, 1003, "Ingrese ID del tipo: ");
        mostrarColores(listaColores, tamColores);
        nuevaMoto.idColor = getInt(10000, 10004, "Ingrese ID del color: ");

        do
        {
            nuevaMoto.cilindrada = getInt(50, 750, "Ingrese Cilindrada(50-125-500-600-750): ");
        }while(nuevaMoto.cilindrada != 50 && nuevaMoto.cilindrada != 125 && nuevaMoto.cilindrada != 500 && nuevaMoto.cilindrada != 600 && nuevaMoto.cilindrada != 750);

        listaMotos[indice] = nuevaMoto;
        error = 0;

    }
    return error;
}

int buscarMotoPorId(eMoto listaMotos[], int tamMotos, int id, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos)
{
    int r = -1;

    if(listaMotos != NULL && tamMotos>0)
    {
        for(int i=0; i<tamMotos; i++)
        {
            if(id == listaMotos[i].id && listaMotos[i].isEmpty == 0)
            {
                printf("\n   ID           MARCA         TIPO   COLOR    CC\n\n");
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos);

                r = i;
                break;
            }
        }
    }

    return r;
}

void mostrarMoto(eMoto moto, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos)
{
    char color[21];
    char tipo[21];

    for(int i=0; i<tamColores; i++)
    {
        if(moto.idColor == listaColores[i].id)
        {
            strcpy(color, listaColores[i].nombreColor);
            break;
        }
    }

    for(int i=0; i<tamTipos; i++)
    {
        if(moto.idTipo == listaTipos[i].id)
        {
            strcpy(tipo, listaTipos[i].descripcion);
            break;
        }
    }

    printf("%5d %15s %12s %7s %5d\n", moto.id, moto.marca, tipo, color, moto.cilindrada);
}

void mostrarMotos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        printf("   ID           MARCA         TIPO   COLOR    CC\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos);
            }
        }
        printf("\n");
    }
}

void modificarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos)
{
    printf("\n               ***** MODIFICAR MOTO *****\n\n");

    int id = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");
    int indice = buscarMotoPorId(listaMotos, tamMotos, id, listaColores, tamColores, listaTipos, tamTipos);

    if(listaMotos != NULL && tamMotos>0 && indice != -1)
    {
        eMoto auxMoto = listaMotos[indice];
        int opcion;
        char salir = 'n';

        do
        {
            printf("\n1. MODIFICAR COLOR\n");
            printf("2. MODIFICAR CILINDRADA\n");
            printf("3. VOLVER AL MENU\n\n");
            opcion = getInt(1, 3, "Ingrese una opcion: ");
            system("cls");

            switch(opcion)
            {
                case 1:
                    mostrarColores(listaColores, tamColores);
                    auxMoto.idColor = getInt(10000, 10004, "Reingrese ID del color: ");
                    break;

                case 2:
                    do
                    {
                        auxMoto.cilindrada = getInt(50, 750, "Reingrese Cilindrada(50-125-500-600-750): ");
                    }while(auxMoto.cilindrada != 50 && auxMoto.cilindrada != 125 && auxMoto.cilindrada != 500 && auxMoto.cilindrada != 600 && auxMoto.cilindrada != 750);
                    break;

                case 3:
                    salir = getChar("Confirma los cambios realizados? (s/n): ");
                    if(salir == 's')
                    {
                        listaMotos[indice] = auxMoto;
                    }
                    printf("Volviendo al Menu ...\n\n");
                    break;
            }
        }while(salir != 's');
    }
    else
    {
        printf("No existe una moto con el ID %d\n\n", id);
    }
}

int eliminarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos)
{
    printf("\n               ***** ELIMINAR MOTO *****\n\n");

    int r = 1;
    int id = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");
    int indice = buscarMotoPorId(listaMotos, tamMotos, id, listaColores, tamColores, listaTipos, tamTipos);
    char confirma = 'n';

    if(listaMotos != NULL && tamMotos>0 && indice != -1)
    {
        confirma = getChar("\nConfirma eliminar esta moto? (s/n): ");

        if(confirma == 's')
        {
            listaMotos[indice].isEmpty = 1;
            printf("\nBaja realizada con exito\n\n");
            r = 0;
        }
        else
        {
            printf("\nBaja cancelada\n\n");
        }
    }
    else
    {
        printf("No existe una moto con el ID %d\n\n", id);
    }

    return r;
}
