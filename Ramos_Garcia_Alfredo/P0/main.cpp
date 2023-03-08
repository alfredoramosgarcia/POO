#include "fecha.hpp"
#include <iostream>

using namespace std;

int main (){

    Fecha a(18,7,1999);
    Fecha b(18,7);
    Fecha c(18);
    Fecha hoy;

    a.mostrar();
    b.mostrar();
    c.mostrar();
    hoy.mostrar();

}