#ifndef ACADENA_H
#define ACADENA_H

#include <cstddef>

typedef unsigned int TAMANO;

class ACadena
{
private:
    char* cadena = NULL;
    TAMANO tamano;

    // Limpiar
    void __limpiar__();
protected:
    
public:
    ~ACadena();
    ACadena();
    ACadena(const char* str);
    // Soporte para C++ 11
    ACadena(const ACadena & obj);
    ACadena& operator=(const ACadena & obj);
    ACadena operator+(const ACadena & obj);
    // Soporte para C++ > 11
    ACadena(ACadena && objStr);
    ACadena& operator=(ACadena && objStr);

    // Funciones publicas ACadena
    const char* c_str() const;
    void limpiar();

    //Funciones comunes con operator
    const char operator[](unsigned int posicion) const;
    void operator+=(const ACadena & cadena);
    const char obtener(unsigned int posicion) const;

    //Utilidades
    // Está función reemplaza en el objeto original
    // y devuelve el mismo objeto con la cadena ya reemplaza
    // Reemplaza todas las coincidencias
    //const ACadena reemplazar(ACadena buscar, ACadena reemplazo);
    // Obtener el tamaño de la cadena
    const unsigned int obtenerTamano();
};

#endif // ACADENA_H