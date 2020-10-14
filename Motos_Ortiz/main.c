/*******************************************************************
* Programa: Service de Motos
* Objetivo: Realizar Altas, Bajas y Modificaciones en un sistema para administrar hasta 1000 motos
*
* Version: 1.0
* Autor: Federico Agustin Ortiz
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "moto.h"
#include "Gets.h"

#define TAM_TIPOS 4
#define TAM_COLORES 5
#define TAM_SERVICIOS 4
#define TAM_MARCAS 5
#define TAM_MOTOS 1000


int main()
{
    eMarca listaMarcas[TAM_MARCAS];
    eTipo listaTipos[TAM_TIPOS];
    eColor listaColores[TAM_COLORES];
    eMoto listaMotos[TAM_MOTOS];
    eServicio listaServicios[TAM_SERVICIOS];

    hardcodearMarcas(listaMarcas, TAM_MARCAS);
    hardcodearTipos(listaTipos, TAM_TIPOS);
    hardcodearColores(listaColores, TAM_COLORES);
    hardcodearServicios(listaServicios, TAM_SERVICIOS);

    if(!inicializarMotos(listaMotos, TAM_MOTOS))
    {
        printf("Iniciacion exitosa\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");
    }

    system("pause");
    system("cls");

    int opcion;
    int proximoIdMotos = 30000;
    int proximoIdTrabajos = 40000;
    int cantMotos = 0;
    char salir = 'n';

    do
    {
        printf("    ***** SERVICE DE MOTOS *****\n\n");
        printf("1.  ALTA MOTO\n");
        printf("2.  MODIFICAR MOTO\n");
        printf("3.  BAJA MOTO\n");
        printf("4.  LISTAR MOTOS\n");
        printf("5.  LISTAR TIPOS\n");
        printf("6.  LISTAR COLORES\n");
        printf("7.  LISTAR SERVICIOS\n");
        printf("8.  ALTA TRABAJO\n");
        printf("9.  LISTAR TRABAJOS\n");
        printf("10. SALIR\n\n");
        opcion = getInt(1, 10, "Ingrese una opcion: ");
        system("cls");

        switch(opcion)
        {
            case 1:
                if(altaMoto(listaMotos, TAM_MOTOS, proximoIdMotos, listaTipos, TAM_TIPOS, listaColores, TAM_COLORES, listaMarcas, TAM_MARCAS) == 0)
                {
                    printf("Alta exitosa\n\n");
                    proximoIdMotos++;
                    cantMotos++;
                }
                else
                {
                    printf("No hay lugar\n\n");
                }
                break;

            case 2:

                break;
            case 3:
                break;
            case 4:
                mostrarMotos(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                salir = getChar("Confirma salida (s/n): ");
                break;

        }

        system("pause");
        system("cls");
    }while(salir != 's');

    return 0;
}
