#include "ACadena.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

ACadena::ACadena() : tamano(0), cadena(NULL)
{
}

ACadena::~ACadena() {
    __limpiar__();
}

ACadena::ACadena(const char* str) {
    __limpiar__();
    this->tamano = strlen(str);
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, str, this->tamano);
}

ACadena::ACadena(char str) {
    __limpiar__();
    this->tamano = strlen(&str);
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, &str, this->tamano);
}

ACadena::ACadena(ACadena&& obj)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = obj.tamano;
    this->cadena = obj.cadena;
    obj.cadena = NULL;
}

ACadena& ACadena::operator=(const ACadena& obj)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = obj.tamano;
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, obj.cadena, this->tamano);
    return *this;
}

ACadena& ACadena::operator=(ACadena&& obj)
{
    // Limpiar antes de asignar
    __limpiar__();

    this->tamano = obj.tamano;
    this->cadena = obj.cadena;
    obj.cadena = NULL;
    return *this;
}

ACadena ACadena::operator+(const ACadena& obj)
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

inline void ACadena::limpiar()
{
    this->__limpiar__();
}

void ACadena::operator+=(const ACadena& acadena)
{
    const char* valor = this->cadena;
    this->limpiar();
    this->tamano = strlen(valor) + acadena.tamano;
    this->cadena = new char[this->tamano + 1];
    strncpy_s(this->cadena, this->tamano + 1, valor, strlen(valor)); // Reasignar la primera cadena
    strncpy_s(this->cadena + this->tamano, acadena.tamano + 1, acadena.cadena, acadena.tamano); // Concatenar la cadena que quiero sumar*/
}

const ACadena ACadena::operator[](unsigned int posicion) const
{
    if (posicion > this->tamano)
    {
        ACadena str = "\0";
        return str;
    }

    ACadena str = this->cadena[posicion];
    return str;
}

const ACadena ACadena::obtener(unsigned int posicion) const {
    if (posicion > this->tamano)
    {
        ACadena str = "\0";
        return str;
    }

    ACadena str = this->cadena[posicion];
    return str;
}

const unsigned int ACadena::obtenerTamano() {
    return this->tamano;
}