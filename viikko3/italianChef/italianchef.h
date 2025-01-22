#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <iostream>
#include "chef.h"
using namespace std;

class italianChef : public Chef
{
public:
    italianChef(string);
    ~italianChef();
    bool askSecret(string, int, int);

private:
    // int flour; Unused?
    // int water; Unused?
    int makePizza(int, int);
    string password = "pizza";


};

#endif // ITALIANCHEF_H
