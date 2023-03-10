#include "fecha.hpp"
#include <iostream>

using namespace std;

int main (){

    Fecha a(18,7,1999);
    Fecha b(18,7);
    Fecha c(18);
    Fecha hoy;
    Fecha d(c);
    Fecha z(8,5,1996);
    const char* cadena = z;
    
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << hoy << endl;
    cout << d << endl;

    try {Fecha t("20/03/2023"); t++; cout << t <<endl; }
    catch(Fecha::Invalida e) { std::cout<<e.por_que()<<endl; }
      
    try{ Fecha t("22/03/1999"); cout << t << endl; }
    catch (Fecha::Invalida e) { cout<<e.por_que()<<endl; }
}