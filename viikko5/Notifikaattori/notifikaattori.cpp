#include "notifikaattori.h"

Notifikaattori::Notifikaattori()
{
    cout << "Notifikaattori luotu " << endl;
}

void Notifikaattori::lisaa(Seuraaja* uusi)
{
    cout << "Uusi seuraaja luotu: " << uusi->getNimi() << endl; // Kutsuu funktiota
    uusi->next = seuraajat; // Next pointteriin asetetaan vanha headin osoite
    seuraajat = uusi;       //Headiin asetetaan uuden noden osoite

}

void Notifikaattori::poista(Seuraaja* poisto)
{
    if(seuraajat == poisto){    //Jos poistettava on headi
        seuraajat = poisto->next;   //Asennetaan poistettavan next headiin
        cout << "Head " << poisto->getNimi() << " deleted" << endl;
        return;
    }

    Seuraaja * temp = seuraajat;

    //Käydään läpi nodeja niin kauan kunnes next on poistettava
    while (temp->next != poisto){
        temp = temp->next;
    }

    temp->next = poisto->next; // Asetetaan headin nextiin poistettavan next
    cout << "Deleted " << poisto->getNimi() << endl;
}

void Notifikaattori::tulosta()
{
    Seuraaja* temp = seuraajat;     // Tallennetaan head temppiin

    while(temp != nullptr){     // Niin kauan kun head ei ole null
    cout << "Seuraaja " << temp->getNimi() << endl;     //Tulostetaan seuraaja
       temp = temp->next;   //Siirrytään seuraavaan
    }
}

void Notifikaattori::postita(string p)
{
    Seuraaja* temp = seuraajat;

    while(temp != nullptr){
        temp->paivitys(p);
        temp = temp->next;
    }
}
