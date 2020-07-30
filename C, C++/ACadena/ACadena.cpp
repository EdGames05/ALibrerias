#include "ACadena.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

ACadena::ACadena() : tamano(0), cadena(NULL)
{
}

ACadena::~ACadena()
{
    __limpiar__();
}

ACadena::ACadena(const char* str)
{
    this->tamano = sizeof(str);
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, str, this->tamano);
}

ACadena::ACadena(const ACadena & obj)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = obj.tamano;
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, obj.cadena, this->tamano);
}

ACadena::ACadena(ACadena && objStr)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = objStr.tamano;
    this->cadena = objStr.cadena;
    objStr.cadena = NULL;
}

ACadena& ACadena::operator=(const ACadena & obj)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = obj.tamano;
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, obj.cadena, this->tamano);
    return *this;
}

ACadena& ACadena::operator=(ACadena && objStr)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = objStr.tamano;
    this->cadena = objStr.cadena;
    objStr.cadena = NULL;
    return *this;
}

ACadena ACadena::operator+(const ACadena & obj)
{
    ACadena str;
    str.tamano = this->tamano + obj.tamano;
    str.cadena = new char[str.tamano + 1];
    strncpy_s(str.cadena, this->tamano + 1, this->cadena, this->tamano); // Copiar cadena 1
    strncpy_s(str.cadena + this->tamano, obj.tamano + 1, obj.cadena, obj.tamano); // Copiar cadena 2

    return str;
}

void ACadena::__limpiar__()
{
    if (this->cadena != NULL)
    {
        delete[] this->cadena;
    }
    this->tamano = 0;
}

const char* ACadena::c_str() const
{
    return this->cadena;
}

void ACadena::limpiar()
{
    this->__limpiar__();
}