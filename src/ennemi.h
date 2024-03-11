#ifndef _ENNEMI_H
#define _ENNEMI_H
#include "sort.h"
#include "objet.h"
#include "combat.h"
#include <iostream>
#include <string>

class Ennemi {
    private:
        int point_de_vie;
        int puissance; 
        Sort *tab_Sort;
    public:
     // Constructeur
    Ennemi();

    // Destructeur
    ~Ennemi();
    // Getter pour pointDeVie
    int getPointDeVieEnnemi() const;

    // Setter pour pointDeVie
    void setPointDeVieEnnemi(int points);

    // Getter pour puissance
    int getPuissanceEnnemi() const;

    // Setter pour puissance
    void setPuissanceEnnemi(int power);

    // Fonction pour attaquer le joueur ?
    void attaquerJoueur();
    void testRegression();

};
#endif