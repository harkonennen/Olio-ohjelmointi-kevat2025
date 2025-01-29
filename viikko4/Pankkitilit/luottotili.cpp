#include "luottotili.h"


Luottotili::Luottotili(string o, double s) : Pankkitili(o), luottoRaja(-s)
{
    cout << "Luottotili " << omistaja << " constructor" << endl;
}

bool Luottotili::deposit(double d)
{
    if(d <= 0){
        cout << "Deposit amount cannot be negative" << endl;
        return false;
    }

    saldo += d;
    cout << omistaja << " Credit Account: " << endl;
    cout << "Deposit: " << d << endl;
    return true;

}

bool Luottotili::withdraw(double w)
{

    if(w <= 0){
        cout << "Withdraw amount cannot be negative" << endl;
        return false;
    }

    if((saldo-w) <= luottoRaja){
        cout << "Withdraw amount exceeding credit limit" << endl;
        return false;
    }

    saldo -= w;
    cout << omistaja << " Credit Account: " << endl;
    cout << "Withdrew: " << w << endl;
    return true;
}
