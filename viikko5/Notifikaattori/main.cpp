#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"

using namespace std;

int main()
{
    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");
    Seuraaja d("D");

    Notifikaattori n;

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.lisaa(&d);

    n.tulosta();

    n.postita("Viesti A");

    n.poista(&d);
    n.tulosta();

    n.poista(&b);
    n.tulosta();


    return 0;
}
