#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char marca[21];
}eMarca;

void hardcodearMarcas(eMarca listaMarcas[], int tam);
void mostrarMarca(eMarca marca);
void mostrarMarcas(eMarca listaMarcas[], int tam);
#endif // MARCA_H_INCLUDED
