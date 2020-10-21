#include <stdio.h>
#include <stdlib.h>
#include "moto.h"
#include "Gets.h"
#include <string.h>
/**********************/
#include "color.h"

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

void hardcodearMotos(eMoto listaMotos[])
{
    int ids[5] = {30000, 30001, 30002, 30003, 30004};
    char marcas[5][21] = {"Zanella", "Honda", "Kawasaki", "Harley Davidson", "Jawa"};
    int idsTipos[5] = {1003, 1003, 1000, 1001, 1001};
    int idsColores[5] = {10002, 10004, 10003, 10001, 10001};
    int cilindradas[5] = {50, 125, 500, 750, 500};
    int idsClientes[5] = {11, 10, 12, 14, 13};

    for(int i=0; i<5; i++)
    {
        listaMotos[i].isEmpty = 0;
        listaMotos[i].id = ids[i];
        strcpy(listaMotos[i].marca, marcas[i]);
        listaMotos[i].idTipo = idsTipos[i];
        listaMotos[i].idColor = idsColores[i];
        listaMotos[i].cilindrada = cilindradas[i];
        listaMotos[i].idCliente = idsClientes[i];
    }
}

int altaMoto(eMoto listaMotos[], int tamMotos, int id, eTipo listaTipos[], int tamTipos, eColor listaColores[], int tamColores, eCliente listaClientes[], int tamClientes)
{
    int error = 1;
    int indice = buscarLibreMoto(listaMotos, tamMotos);
    eMoto nuevaMoto;

    if(listaMotos != NULL && tamMotos>0 && indice != -1)
    {
        printf("\n               *** ALTA MOTO ***\n\n");

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

        mostrarClientes(listaClientes, tamClientes);
        nuevaMoto.idCliente = getInt(10, 14, "Ingrese ID del cliente: ");

        listaMotos[indice] = nuevaMoto;
        error = 0;

    }
    return error;
}

int buscarMotoPorId(eMoto listaMotos[], int tamMotos, int id, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    int r = -1;

    if(listaMotos != NULL && tamMotos>0)
    {
        for(int i=0; i<tamMotos; i++)
        {
            if(id == listaMotos[i].id && listaMotos[i].isEmpty == 0)
            {
                printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);

                r = i;
                break;
            }
        }
    }

    return r;
}

void mostrarMoto(eMoto moto, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    char color[21];
    char tipo[21];
    char cliente[30];

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

    for(int i=0; i<tamClientes; i++)
    {
        if(moto.idCliente == listaClientes[i].id)
        {
            strcpy(cliente, listaClientes[i].nombre);
        }
    }

    printf("%5d %15s %12s %7s %5d %12s\n", moto.id, moto.marca, tipo, color, moto.cilindrada, cliente);
}

void mostrarMotos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
            }
        }
        printf("\n");
    }
}

void modificarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    printf("\n               ***** MODIFICAR MOTO *****\n");

    mostrarMotos(listaMotos, tamMotos, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);

    int id = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");
    int indice = buscarMotoPorId(listaMotos, tamMotos, id, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);

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

int eliminarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)

{
    printf("\n               ***** ELIMINAR MOTO *****\n");

    mostrarMotos(listaMotos, tamMotos, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);

    int r = 1;
    int id = getInt(30000, 39999, "Ingrese ID de la moto(30000-39999): ");
    int indice = buscarMotoPorId(listaMotos, tamMotos, id, listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
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

void mostrarMotosDeUnColor(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        int idColor;
        int flag = 0;

        mostrarColores(listaColores, tamColores);
        idColor = getInt(10000, 10004, "Ingrese ID del color: ");
        printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(idColor == listaMotos[i].idColor && listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                flag = 1;
            }
        }

        if(!flag)
        {
            for(int i=0; i<tamColores; i++)
            {
                if(idColor == listaColores[i].id)
                {
                    printf("            No hay motos de color %s\n", listaColores[i].nombreColor);
                    break;
                }
            }
        }
        printf("\n");
    }
}

void mostrarMotosDeUnTipo(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        int idTipo;
        int flag = 0;

        mostrarTipos(listaTipos, tamTipos);
        idTipo = getInt(1000, 1003, "Ingrese ID del tipo: ");
        printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(idTipo == listaMotos[i].idTipo && listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                flag = 1;
            }
        }

        if(!flag)
        {
            for(int i=0; i<tamTipos; i++)
            {
                if(idTipo == listaTipos[i].id)
                {
                    printf("            No hay motos del tipo %s\n", listaTipos[i].descripcion);
                    break;
                }
            }
        }
        printf("\n");
    }
}

void mostrarMotosMayorCilindrada(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        int maxCC = 0;

        for(int i=0; i<tamMotos; i++)
        {
            if(listaMotos[i].cilindrada>maxCC && listaMotos[i].isEmpty == 0)
            {
                maxCC = listaMotos[i].cilindrada;
            }
        }

        printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(listaMotos[i].cilindrada == maxCC && listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
            }
        }
        printf("\n");
    }
}

void mostrarMotosPorTipo(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        int flag = 0;

        for(int i=0; i<tamTipos; i++)
        {
            printf("               Motos del tipo: %s\n\n", listaTipos[i].descripcion);
            printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
            for(int j=0; j<tamMotos; j++)
            {
                if(listaTipos[i].id == listaMotos[j].idTipo && listaMotos[j].isEmpty == 0)
                {
                    mostrarMoto(listaMotos[j], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                    flag = 1;
                }
            }

            if(!flag)
            {
                printf("            No hay motos de este tipo\n");
            }
            printf("\n------------------------------------------------------------------------\n");
            flag = 0;
        }
    }
}

void mostrarCantidadMotosDeUnColorYUnTipo(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        int idColor;
        int idTipo;
        char color[21];
        char tipo[21];
        int cantMotos = 0;

        mostrarColores(listaColores, tamColores);
        idColor = getInt(10000, 10004, "Ingrese ID del color: ");
        mostrarTipos(listaTipos, tamTipos);
        idTipo = getInt(1000, 1003, "Ingrese ID del tipo: ");

        printf("\n   ID           MARCA         TIPO   COLOR    CC      CLIENTE\n\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(listaMotos[i].idColor == idColor && listaMotos[i].idTipo == idTipo && listaMotos[i].isEmpty == 0)
            {
                mostrarMoto(listaMotos[i], listaColores, tamColores, listaTipos, tamTipos, listaClientes, tamClientes);
                cantMotos++;
            }
        }

        for(int i=0; i<tamColores; i++)
        {
            if(idColor == listaColores[i].id)
            {
                strcpy(color, listaColores[i].nombreColor);
                break;
            }
        }

        for(int i=0; i<tamTipos; i++)
        {
            if(idTipo == listaTipos[i].id)
            {
                strcpy(tipo, listaTipos[i].descripcion);
                break;
            }
        }
        printf("\nMotos de color %s y del tipo %s: %d\n\n", color, tipo, cantMotos);
    }
}

void mostrarColoresMasElegidos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eCliente listaClientes[], int tamClientes)
{
    if(listaMotos != NULL && tamMotos>0)
    {
        int cantidadMotosPorColor[5] = {0};
        eColor auxColores[5];

        for(int i=0; i<tamColores; i++)
        {
            auxColores[i] = listaColores[i];
        }

        for(int i=0; i<tamColores; i++)
        {
            for(int j=0; j<tamMotos; j++)
            {
                if(auxColores[i].id == listaMotos[j].idColor)
                {
                    cantidadMotosPorColor[i]++;
                }
            }
        }

        for(int i=0; i<tamColores; i++)
        {
            if(cantidadMotosPorColor[i] != 0)
            {
                printf("\nCantidad de motos del color %s: %d\n", auxColores[i].nombreColor, cantidadMotosPorColor[i]);
            }
        }
        printf("\n");
    }
}
