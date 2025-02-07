#include "seuraaja.h"

Seuraaja::Seuraaja(string name) {
    nimi = name;
    cout << "Seuraaja " << nimi << "luotu " << endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string message)
{
    cout << getNimi() << " received " << message << endl;
}
