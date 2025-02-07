#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <iostream>
using namespace std;

class Seuraaja
{
public:
    Seuraaja* next = nullptr; // next
    Seuraaja(string);
    string getNimi();
    void paivitys(string);


private:
    string nimi;
};

#endif // SEURAAJA_H
