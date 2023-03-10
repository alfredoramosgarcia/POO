#include "fecha.hpp"
#include <iostream>
#include <ctime>

Fecha::Fecha(int dia, int mes, int anno): _dia(dia), _mes(mes), _anno(anno) {
    fSistema(dia, mes, anno);
    fValida();
}


Fecha::Fecha(const char* cadena)
{
    int dia, mes, anno;
     
    if(sscanf(cadena, "%d/%d/%d", &dia, &mes, &anno) != 3)
        throw Invalida("fecha incorrecta");
    else{
        
        _dia = dia;
        _mes = mes;
        _anno = anno;

        fSistema(dia, mes, anno);
    }
}

void Fecha::fSistema(int d, int m, int a){

    std::time_t tc = std::time(nullptr);
    std::tm* td = std::localtime(&tc);

    if (d == 0)
        _dia = td->tm_mday;
    
    if (m == 0)
        _mes = td->tm_mon + 1;

    if (a == 0)
        _anno = td->tm_year + 1900;
}

void Fecha::fValida()
{
    static const int dias [] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int esBisiesto = static_cast<int>(_anno % 4 == 0 && (_anno % 400 == 0 || _anno % 100 != 0));

    if(_anno > Fecha::AnnoMaximo || _anno < Fecha::AnnoMinimo)
    {
        throw Invalida("Año invalido.");
    }

    if(_mes > 12 || _mes < 1)
    {
        throw Invalida("Mes invalido");
    }

    if(_mes == 2){
        if(_dia > dias[_mes] + esBisiesto || _dia < 1)
        {
            throw Invalida("Dia invalido");
        }
    }
    else{
        if(_dia > dias[_mes] || _dia < 1)
        {
            throw Invalida("Dia invalido");
        }
    }

}

const char* Fecha::cadena() const noexcept
{
    const char* dias[] = {"domingo","lunes","martes","miércoles","jueves","viernes","sábado"};

    const char* meses[] = {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};

    static char fecha[40];

    tm f = {0};

    f.tm_mday = dia();
    f.tm_mon = mes() - 1;
    f.tm_year = anno() - 1900;

    mktime(&f);
    sprintf(fecha,"%s %d de %s de %d", dias[f.tm_wday], f.tm_mday, meses[f.tm_mon], f.tm_year + 1900);

    return fecha;

}

void Fecha::mostrar() const{

    using namespace std;

    switch(_mes){
        case 1: cout<<_dia<<" de enero de "<<_anno<<endl; break;
        case 2: cout<<_dia<<" de febrero de "<<_anno<<endl; break;
        case 3: cout<<_dia<<" de marzo de "<<_anno<<endl; break;
        case 4: cout<<_dia<<" de abril de "<<_anno<<endl; break;
        case 5: cout<<_dia<<" de mayo de "<<_anno<<endl; break;
        case 6: cout<<_dia<<" de junio de "<<_anno<<endl; break;
        case 7: cout<<_dia<<" de julio de "<<_anno<<endl; break;
        case 8: cout<<_dia<<" de agosto de "<<_anno<<endl; break;
        case 9: cout<<_dia<<" de septiembre de "<<_anno<<endl; break;
        case 10: cout<<_dia<<" de octubre de "<<_anno<<endl; break;
        case 11: cout<<_dia<<" de noviembre de "<<_anno<<endl; break;
        case 12: cout<<_dia<<" de diciembre de "<<_anno<<endl; break;
    } 
}

//SOBRECARGA DE OPERADORES ARITMETICOS


Fecha& Fecha::operator +=(int n)
{
    if(n!=0){
        tm faux = {};
        faux.tm_mday = _dia + n;
        faux.tm_mon = _mes - 1;
        faux.tm_year = _anno - 1900;

        mktime(&faux);

        _anno = faux.tm_year + 1900;
        _mes = faux.tm_mon + 1;
        _dia = faux.tm_mday;
        fValida();
    }

    return *this;
}

Fecha& Fecha::operator -=(int n)
{
    return *this += -n;
}

Fecha Fecha::operator +(int n) const
{
    Fecha f = *this;
    f += n;
    return f;
}

Fecha Fecha::operator -(int n) const
{
    Fecha f = *this;
    f += -n;
    return f;
}

Fecha& Fecha::operator --()
{
    return *this += -1;
}

Fecha& Fecha::operator ++()
{
    return *this += 1;
}

Fecha Fecha::operator --(int)
{
    Fecha f = *this;
    *this += -1;
    return f;
}

Fecha Fecha::operator ++(int)
{
    Fecha f = *this;
    *this += 1;
    return f;
}

//SOBRECARGA DE OPERACIORES DE COMPARACION


bool operator ==(const Fecha& f1, const Fecha& f2)
{
    return (f1.anno() == f2.anno()) && (f1.mes() == f2.mes()) && (f1.dia() == f2.dia());
    
}

bool operator >(const Fecha& f1, const Fecha& f2)
{
    if(f1.anno() > f2.anno())
    {return true;}
    else if(f1.anno() == f2.anno() && f1.mes() > f2.mes()) {return true;}
    else if(f1.anno() == f2.anno() && f1.mes() == f2.mes() && f1.dia() > f2.dia()) {return true;}
    else return false;

}

bool operator <(const Fecha& f1, const Fecha& f2)
{
    return (f2 > f1);
}

bool operator >=(const Fecha& f1, const Fecha& f2)
{
    return (f1 > f2 || f1 == f2);
}

bool operator <=(const Fecha& f1, const Fecha& f2)
{
    return (f1 < f2 || f1 == f2);
}

bool operator !=(const Fecha& f1, const Fecha& f2)
{
    return !(f1 == f2);
}



//OPERADORES DE ENTRADA Y SALIDA

std::istream& operator >> (std::istream& is, Fecha& f)
{
    char* cadena = new char[11];
    is.getline(cadena,11);

    try
    {
        f = Fecha(cadena);
    } catch(Fecha::Invalida e)
    {
        is.setstate(std::ios_base::failbit);
        throw e;
    }

    return is;

}

std::ostream& operator << (std::ostream& output, const Fecha& f)
{
    output << f.cadena();
    return output;
}