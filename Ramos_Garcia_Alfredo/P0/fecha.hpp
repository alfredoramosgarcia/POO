#ifndef FECHA_HPP_
#define FECHA_HPP_

#include "time.h"

class Fecha{

    public:
    
        explicit Fecha(int dia = 0, int mes = 0, int anno = 0);
        Fecha(const char* cadena);
        
        void mostrar() const;

        static const int AnnoMaximo = 2037;
        static const int AnnoMinimo = 1902;

        int dia() const noexcept { return _dia; }
        int mes() const noexcept { return _mes; }
        int anno() const noexcept { return _anno; }

    private:
        int _dia, _mes, _anno;
        void fSistema(int d, int m, int a);
        void fValida():
};



#endif