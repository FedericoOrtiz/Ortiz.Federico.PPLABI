#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "marca.h"


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
int buscarLibre(eMoto listaMotos[], int tam);
int altaMoto(eMoto listaMotos[], int tamMotos, int id, eTipo listaTipos[], int tamTipos, eColor listaColores[], int tamColores, eMarca listaMarcas[], int tamMarcas);
void mostrarMoto(eMoto moto, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);
void mostrarMotos(eMoto listaMotos[], int tamMotos, eColor listaColores[], int tamColores, eTipo listaTipos[], int tamTipos);
int buscarMotoPorId(eMoto listaMotos[], int tam);
int modificarMoto(eMoto listaMotos[], int tam);





#endif // MOTO_H_INCLUDED
