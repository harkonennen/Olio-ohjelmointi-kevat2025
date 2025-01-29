#include "pankkitili.h"

Pankkitili::Pankkitili(string omistaja):omistaja (omistaja)
{
    cout << "Pankkitili " << omistaja << " constructor" << endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double d)
{
    if(d <= 0){
        cout << "Deposit amount cannot be negative" << endl;
        return false;
    }

    saldo += d;
    cout << omistaja << " Account: " << endl;
    cout << "Deposit: " << d << endl;
    return true;
}

bool Pankkitili::withdraw(double w)
{
    if(w < 0){
        cout << "Withdraw amount cannot be negative" << endl;
        return false;
    }

    if(w > saldo){
        cout << "Withdraw amount cannot be greater than account balance." << endl;
        return false;
    }

        saldo -= w;
        cout << omistaja << " Account: " << endl;
        cout << "Withdrew: " << w << endl;
        return true;
}
