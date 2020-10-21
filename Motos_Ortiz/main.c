/*******************************************************************
* Programa: Service de Motos
* Objetivo: Realizar Altas, Bajas y Modificaciones en un sistema para administrar hasta 1000 motos
            Realizar informes con los distintos datos del sistema
*
* Version: 2.0
* Autor: Federico Agustin Ortiz
* Fecha: 21/10/2020
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "moto.h"
#include "trabajo.h"
#include "Gets.h"
#include "cliente.h"

#define TAM_TIPOS 4
#define TAM_COLORES 5
#define TAM_SERVICIOS 4
#define TAM_MOTOS 1000
#define TAM_TRABAJOS 1000
#define TAM_CLIENTES 5

int main()
{
    eTipo listaTipos[TAM_TIPOS];
    eColor listaColores[TAM_COLORES];
    eMoto listaMotos[TAM_MOTOS];
    eServicio listaServicios[TAM_SERVICIOS];
    eTrabajo listaTrabajos[TAM_TRABAJOS];
    eCliente listaClientes[TAM_CLIENTES];

    hardcodearTipos(listaTipos, TAM_TIPOS);
    hardcodearColores(listaColores, TAM_COLORES);
    hardcodearServicios(listaServicios, TAM_SERVICIOS);
    hardcodearClientes(listaClientes, TAM_CLIENTES);

    if(!inicializarMotos(listaMotos, TAM_MOTOS) && !(inicializarTrabajos(listaTrabajos, TAM_TRABAJOS)))
    {
        printf("Iniciacion exitosa\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");
    }

    hardcodearMotos(listaMotos);
    hardcodearTrabajos(listaTrabajos);

    system("pause");
    system("cls");

    int opcion;
    int proximoIdMotos = 30005;
    int proximoIdTrabajos = 40004;
    int cantMotos = 5;
    int cantTrabajos = 4;
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
        printf("9.  LISTAR TRABAJOS\n\n");
        printf("   ***** INFORMES *****\n\n");
        printf("10. LISTAR MOTOS DE UN COLOR\n");
        printf("11. LISTAR MOTOS DE UN TIPO\n");
        printf("12. LISTAR MOTOS DE MAYOR CILINDRADA\n");
        printf("13. LISTAR MOTOS POR TIPO\n");
        printf("14. CANTIDAD MOTOS DE UN COLOR Y UN TIPO\n");
        printf("15. LISTAR COLORES MAS ELEGIDOS\n");
        printf("16. LISTAR TRABAJOS DE UNA MOTO\n");
        printf("17. INFORMAR SUMA DE LOS IMPORTES DE LOS SERVICIOS DE UNA MOTO\n");
        printf("18. LISTAR MOTOS POR SERVICIO\n");
        printf("19. LISTAR TRABAJOS POR FECHA\n\n");
        printf("20. SALIR\n\n");
        opcion = getInt(1, 20, "Ingrese una opcion: ");
        system("cls");

        switch(opcion)
        {
            case 1:
                if(altaMoto(listaMotos, TAM_MOTOS, proximoIdMotos, listaTipos, TAM_TIPOS, listaColores, TAM_COLORES, listaClientes, TAM_CLIENTES) == 0)
                {
                    printf("\nAlta exitosa\n\n");
                    proximoIdMotos++;
                    cantMotos++;
                }
                else
                {
                    printf("No hay lugar\n\n");
                }
                break;

            case 2:
                if(cantMotos > 0)
                {
                    modificarMoto(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 3:
                if(cantMotos>0)
                {
                    if(!eliminarMoto(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES))
                    {
                        cantMotos--;
                    }
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 4:
                if(cantMotos>0)
                {
                    mostrarMotos(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 5:
                mostrarTipos(listaTipos, TAM_TIPOS);
                break;
            case 6:
                mostrarColores(listaColores, TAM_COLORES);
                break;
            case 7:
                mostrarServicios(listaServicios, TAM_SERVICIOS);
                break;
            case 8:
                if(cantMotos>0)
                {
                    if(!altaTrabajo(listaTrabajos, TAM_TRABAJOS, proximoIdTrabajos, listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaServicios, TAM_SERVICIOS, listaClientes, TAM_CLIENTES))
                    {
                        printf("\nAlta exitosa\n\n");
                        proximoIdTrabajos++;
                        cantTrabajos++;
                    }
                    else
                    {
                        printf("No hay lugar\n\n");
                    }
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 9:
                if(cantTrabajos>0)
                {
                    mostrarTrabajos(listaTrabajos, TAM_TRABAJOS, listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaServicios, TAM_SERVICIOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                   printf("Primero debe realizar la carga de un trabajo\n\n");
                }
                break;
            case 10:
                if(cantMotos>0)
                {
                mostrarMotosDeUnColor(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 11:
                if(cantMotos>0)
                {
                mostrarMotosDeUnTipo(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 12:
                if(cantMotos>0)
                {
                mostrarMotosMayorCilindrada(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 13:
                if(cantMotos>0)
                {
                    mostrarMotosPorTipo(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 14:
                if(cantMotos>0)
                {
                    mostrarCantidadMotosDeUnColorYUnTipo(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 15:
                if(cantMotos>0)
                {
                    mostrarColoresMasElegidos(listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de una moto\n\n");
                }
                break;
            case 16:
                if(cantTrabajos>0)
                {
                    mostrarUnaMotoConSusTrabajos(listaTrabajos, TAM_TRABAJOS, listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaServicios, TAM_SERVICIOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de un trabajo\n\n");
                }
                break;
            case 17:
                if(cantTrabajos>0)
                {
                    mostrarUnaMotoConImporteTotal(listaTrabajos, TAM_TRABAJOS, listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaServicios, TAM_SERVICIOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de un trabajo\n\n");
                }
                break;
            case 18:
                if(cantTrabajos>0)
                {
                    mostrarMotosDeUnServicio(listaTrabajos, TAM_TRABAJOS, listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaServicios, TAM_SERVICIOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de un trabajo\n\n");
                }
                break;
            case 19:
                if(cantTrabajos>0)
                {
                    mostrarTrabajosPorFecha(listaTrabajos, TAM_TRABAJOS, listaMotos, TAM_MOTOS, listaColores, TAM_COLORES, listaTipos, TAM_TIPOS, listaServicios, TAM_SERVICIOS, listaClientes, TAM_CLIENTES);
                }
                else
                {
                    printf("Primero debe realizar la carga de un trabajo\n\n");
                }
                break;
            case 20:
                salir = getChar("Confirma salida (s/n): ");
                break;

        }

        system("pause");
        system("cls");
    }while(salir != 's');

    return 0;
}
