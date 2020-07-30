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
};

#endif // ACADENA_H