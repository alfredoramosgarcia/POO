#ifndef FECHA_HPP_
#define FECHA_HPP_

#include "time.h"

class Fecha{

    public:
        
        
        Fecha(int dia, int mes, int anno);
        Fecha(int dia, int mes);
        Fecha(int dia);
        Fecha();
        void mostrar() const;

    private:
        
        int _dia, _mes, _anno;
};



#endif