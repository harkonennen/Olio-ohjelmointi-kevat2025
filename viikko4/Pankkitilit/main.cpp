#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas asiakas1("Kalle", 1000);
    asiakas1.talletus(500);
    asiakas1.nosto(100);
    asiakas1.luotonNosto(400);
    asiakas1.luotonMaksu(100);
    asiakas1.showSaldo();

    Asiakas asiakas2("Pekka", 500);

    asiakas1.tiliSiirto(300,asiakas2);
    asiakas1.showSaldo();
    asiakas2.showSaldo();

}
