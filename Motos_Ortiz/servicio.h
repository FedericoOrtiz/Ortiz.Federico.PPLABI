#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    int precio;
}eServicio;

void hardcodearServicios(eServicio listaServicios[], int tam);
void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio listaServicios[], int tam);

#endif // SERVICIO_H_INCLUDED
