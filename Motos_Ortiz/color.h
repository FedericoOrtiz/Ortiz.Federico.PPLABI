#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
}eColor;

void hardcodearColores(eColor listadoColores[], int tam);
void mostrarColor(eColor color);
void mostrarColores(eColor listadoColores[], int tam);

#endif // COLOR_H_INCLUDED
