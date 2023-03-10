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
        fValida();
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
        throw Invalida("Añoo invalido");
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