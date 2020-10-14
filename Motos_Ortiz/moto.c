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

int buscarLibre(eMoto listaMotos[], int tam)
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

int altaMoto(eMoto listaMotos[], int tamMotos, int id, eTipo listaTipos[], int tamTipos, eColor listaColores[], int tamColores, eMarca listaMarcas[], int tamMarcas)
{
    int error = 1;
    int indice;
    int auxIdMarca;


    eMoto nuevaMoto;

    if(listaMotos != NULL && tamMotos>0 && id>0)
    {
        printf("  *** ALTA MOTO ***\n\n");
        indice = buscarLibre(listaMotos, tamMotos);

        if(indice == -1)
        {
            printf("Sistema completo\n");
        }
        else
        {
            nuevaMoto.id = id;
            nuevaMoto.isEmpty = 0;

            mostrarMarcas(listaMarcas, tamMarcas);
            auxIdMarca = getInt(50000, 50004, "Ingrese ID de la marca: ");
            for(int i=0; i<tamMarcas; i++)
            {
                if(auxIdMarca == listaMarcas[i].id)
                {
                    strcpy(nuevaMoto.marca, listaMarcas[i].marca);
                    break;
                }
            }

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
    }
    return error;
}

int buscarMotoPorId(eMoto listaMotos[], int tam)
{
    int r = -1;
    int auxId;

    if(listaMotos != NULL && tam>0)
    {
        auxId = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");

        for(int i=0; i<tam; i++)
        {
            if(auxId == listaMotos[i].id && listaMotos[i].isEmpty == 0)
            {
                printf("\n   ID   MARCA   TIPO   COLOR   CILINDRADA\n");

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
        }
    }

    for(int i=0; i<tamTipos; i++)
    {
        if(moto.idTipo == listaTipos[i].id)
        {
            strcpy(tipo, listaTipos[i].descripcion);
        }
    }

    printf("5d %8s %12s %8s %9d\n", moto.id, moto.marca, tipo, color, moto.cilindrada);
}

void mostrarMotos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos)
{
    int flag = 0;

    if(listaMotos != NULL && tamMotos>0)
    {
        printf("   ID   MARCA        TIPO   COLOR  CILINDRADA\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("No hay motos en la lista\n\n");
        }
    }
}
