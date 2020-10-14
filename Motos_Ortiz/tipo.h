#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
}eTipo;

void hardcodearTipos(eTipo listadoTipos[], int tam);
void mostrarTipo(eTipo tipo);
void mostrarTipos(eTipo listadoTipos[], int tam);

#endif // TIPO_H_INCLUDED


