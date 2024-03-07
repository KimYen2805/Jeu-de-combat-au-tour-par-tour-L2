#ifndef _SORT_H
#define _SORT_H
#include <string>
using namespace std;

class Sort
{

private:
    string nom;     //Nom du sort
    int coutMana;   //Le coup en mana du sort
    int puissance; //Les dégâts infligés par le sort

public:
    Sort();

    void setNom(string nom);
    void setCoutMana(int nvCout);
    void setPuissance(int nvPuissance);

    string getNom() const;
    int getCoutMana() const;
    int getPuissance() const;
};
#endif