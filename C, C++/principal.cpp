#include "ACadena/ACadena.h"
#include "AList/AList.h"
#include <stdio.h>
#include <stdlib.h>
// Este archivo solo es para pruebas y testeo de los archivos generados
// para las librerias, se podrán generar archivos auxiliares para no
// tener mucho código en este mismo archivo

int main()
{
    ACadena cadena = "Algo sobre lo que estoy haciendo";
    cadena += " se añadio esto";
    printf("Valor de cadena: %s \n", cadena.c_str());
    system("pause");
    return 0;
}