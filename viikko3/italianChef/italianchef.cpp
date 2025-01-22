#include "italianchef.h"

italianChef::italianChef(string name) : Chef(name) {
    cout<<"italianChef "<<name<<" CONSTRUCTOR"<<endl;
}

italianChef::~italianChef()
{
    cout<<"italianChef DESTRUCTOR"<<endl;
}

bool italianChef::askSecret(string userPassword, int flour, int water)
{
    cout<<"Give password!"<<endl;

    if(password == userPassword){
        cout<<"Correct"<<endl;
        makePizza(flour,water);
        return true;

    } else {
        cout<<"false"<<endl;
        return false;
    }

}

int italianChef::makePizza(int flour, int water)
{
    if(flour >= 5 & water >= 5){
        int portion = (water/5 + flour/5)/2;
        cout<<chefName<<" made "<<portion<<(portion== 1 ? " pizza with " : " pizzas with ")<<water<<" water and "<<flour<<" flour!"<<endl;
    } else {cout<<"Not enough ingredients!"<<endl;}
}
