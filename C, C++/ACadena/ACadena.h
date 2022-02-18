#pragma once
#ifndef ACADENA_H
#define ACADENA_H

#include <cstddef>

typedef unsigned int TAMANO;

class ACadena {
private:
    char* cadena = NULL;
    TAMANO tamano;

    /* Limpiar cadena */
    void __limpiar__();
public:
    /* Constructores */
    ~ACadena();
    ACadena();
    ACadena(const char* str);
    ACadena(char str);
    /* Añadir soporte para C++ 11 */
    ACadena(const ACadena& obj);
    ACadena& operator=(const ACadena& obj);
    ACadena operator+(const ACadena& obj);
    /* Soporte para C++ > 11 */
    ACadena(ACadena&& obj);
    ACadena& operator=(ACadena&& obj);

    /* Funciones publicas */
    const char* c_str() const;
    inline void limpiar();

    /* Funciones comunes con operator */
    const ACadena operator[](unsigned int posicion) const;
    void operator+=(const ACadena& acadena);
    const ACadena obtener(unsigned int posicion) const;

    /*
      Utilidades
    */
    const unsigned int obtenerTamano();
};

#endif /* ACADENA_H */