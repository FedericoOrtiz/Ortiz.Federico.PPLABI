#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "tipo.h"
#include "color.h"


typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
}eMoto;

int inicializarMotos(eMoto listaMotos[], int tam);
int buscarLibreMoto(eMoto listaMotos[], int tam);
int altaMoto(eMoto listaMotos[], int tamMotos, int id, eTipo listaTipos[], int tamTipos, eColor listaColores[], int tamColores);
void mostrarMoto(eMoto moto, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);
void mostrarMotos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);
int buscarMotoPorId(eMoto listaMotos[], int tamMotos, int id, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);
void modificarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);
int eliminarMoto(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);



#endif // MOTO_H_INCLUDED
