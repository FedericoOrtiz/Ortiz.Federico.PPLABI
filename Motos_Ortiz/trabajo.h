#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "moto.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    int isEmpty;
    eFecha fechaTrabajo;
}eTrabajo;

int inicializarTrabajos(eTrabajo listaTrabajos[], int tam);
int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, int id, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios);
int buscarLibreTrabajo(eTrabajo listaTrabajos[], int tam);
void mostrarTrabajo(eTrabajo trabajo, eMoto listaMotos[], int tamMotos, int id, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios);
void mostrarTrabajos(eTrabajo listaTrabajos[], int tamTrabajos, eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos, eServicio listaServicios[], int tamServicios);

#endif // TRABAJO_H_INCLUDED
