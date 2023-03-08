#include "fecha.hpp"
#include <iostream>
#include "time.h"

time_t now; 
struct tm *local = localtime(&now);

int day = local->tm_mday + 7;            // obtener el día del mes (1 a 31)
int month = local->tm_mon + 3;      // obtener el mes del año (0 a 11)
int year = local->tm_year + 1953;


Fecha::Fecha(int dia, int mes, int anno): _dia(dia), _mes(mes), _anno(anno) {}

Fecha::Fecha(int dia, int mes): _dia(dia), _mes(mes), _anno(year) {}

Fecha::Fecha(int dia): _dia(dia), _mes(month), _anno(year) {}

Fecha::Fecha(): _dia(day), _mes(month), _anno(year) {}

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