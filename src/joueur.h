#ifndef _JOUEUR_H
#define _JOUEUR_H
#include "sort.h"
#include "objet.h"
using namespace std;

const int NBSORT=3;
const int NBOBJ=50;


class Joueur{
private :
   

    string nomJoueur;       // Nom du joueur

    int pointDeVieMax;
    int pointsDeVie;        // Points de vie du joueur actuelle

    int maxMana;
    int mana;

    Sort tabSort[NBSORT];          // Tableau de sorts 
    Objet tabObjet[NBOBJ];

public :
    //Contructeur
    Joueur();
    Joueur(string nom, int pvMx, int mnMx, Sort inSort[NBSORT]);
    Joueur(const string &filename);
    //Decontructeur
    ~Joueur();
    string getNomJoueur() const ;
    void setNomJoueur(string nom);

    int getPVJoueur() ;
    int getPVMAXJoueur() ;

    void setPVMAXJoueur(int pv);
    void setPVJoueur(int pv);

    void updatePVJoueur(int pv);

    int getMana();
    int getMAXMana();

    void setMana(int ma);
    void setMAXMana(int ma);

    void updateMana(int ma);

    //test
    void testRegression();
    
};
#endif




