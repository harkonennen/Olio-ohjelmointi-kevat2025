#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    Chef chef1("Pekka");
    italianChef chef2("Reima");
    chef1.makeSalad(10);
    chef1.makeSoup(3);
    chef2.askSecret("pizza",5,5);
}
