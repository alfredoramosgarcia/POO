#include "fecha.hpp"
#include <iostream>

using namespace std;

int main (){

    Fecha a(18,7,1999);
    Fecha b(18,7);
    Fecha c(18);
    Fecha hoy;
    Fecha d(c);
    
    a.mostrar();
    b.mostrar();
    c.mostrar();
    hoy.mostrar();
    d.mostrar();

    try {Fecha t("20/03/2023"); t++; cout << t <<endl; }
    catch(Fecha::Invalida e) { std::cout<<e.por_que()<<endl; }
      
    try{ Fecha t("22/03/1999"); cout << t << endl; }
    catch (Fecha::Invalida e) { cout<<e.por_que()<<endl; }
}