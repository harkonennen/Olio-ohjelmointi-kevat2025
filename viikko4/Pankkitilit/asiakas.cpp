#include "asiakas.h"

Asiakas::Asiakas(string o, double luottoRaja) : nimi(o), kayttotili (o),luottotili (o, luottoRaja)
{
    cout << "Asiakas " << nimi << " constructor" << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Account Balance: " << endl;
    cout<<kayttotili.getBalance()<<endl;
    cout << "Credit Balance " << endl;
    cout<<luottotili.getBalance()<<endl;
}

bool Asiakas::talletus(double t)
{
    kayttotili.deposit(t);
}

bool Asiakas::nosto(double n)
{
    kayttotili.withdraw(n);
}

bool Asiakas::luotonMaksu(double lm)
{
    luottotili.deposit(lm);
}

bool Asiakas::luotonNosto(double ln)
{
    luottotili.withdraw(ln);
}

bool Asiakas::tiliSiirto(double ts, Asiakas &vastaanottaja)
{
    if(ts <= 0){
        cout << "Deposit amount cannot be negative" << endl;
        return false;
    }

    if(kayttotili.withdraw(ts)){
        vastaanottaja.talletus(ts);
    } return false;

}
