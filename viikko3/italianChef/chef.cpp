#include "chef.h"

Chef::Chef(string name): chefName (name)
{
    cout<<"chef "<<getName()<<" CONSTRUCTOR"<<endl;
}

Chef::~Chef()
{
    cout<<"chef DESTRUCTOR"<<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int ingredient)
{
    int portion = ingredient /5;
    cout<<chefName<<" made "<<portion<<(portion== 1 ? " salad with " : " salads with ")<<ingredient<<" ingredients!"<<endl;
}

int Chef::makeSoup(int ingredient)
{
    int portion = ingredient /3;
    cout<<chefName<<" made "<<portion<<(portion== 1 ? " soup with " : " soups with ")<<ingredient<<" ingredients!"<<endl;

}
