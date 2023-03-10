#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <cstring>

class Fecha{

    public:
    
        explicit Fecha(int dia = 0, int mes = 0, int anno = 0);
        Fecha(const char* cadena);
        
        void mostrar() const;

        static const int AnnoMaximo = 2037;
        static const int AnnoMinimo = 1902;

        class Invalida{
            public:
                Invalida(const char* razon) : razon_{razon} {}
                const char* por_que() const noexcept { return razon_; }
            private:
                const char* razon_;


        };

        Fecha operator ++(int); 
        Fecha operator --(int); 
        Fecha operator +(int n) const;
        Fecha operator -(int n) const;
        Fecha& operator +=(int n);
        Fecha& operator -=(int n);
        Fecha& operator ++(); 
        Fecha& operator --(); 

        int dia() const noexcept { return _dia; }
        int mes() const noexcept { return _mes; }
        int anno() const noexcept { return _anno; }

        const char* cadena() const noexcept;

    private:
        int _dia, _mes, _anno;
        void fSistema(int d, int m, int a);
        void fValida();
};

bool operator ==(const Fecha& f1, const Fecha& f2);
bool operator !=(const Fecha& f1, const Fecha& f2);
bool operator >(const Fecha& f1, const Fecha& f2);
bool operator >=(const Fecha& f1, const Fecha& f2);
bool operator <(const Fecha& f1, const Fecha& f2);
bool operator <=(const Fecha& f1, const Fecha& f2);

std::ostream& operator << (std::ostream& os, const Fecha& f);
std::istream& operator >> (std::istream& is, Fecha& f);



#endif