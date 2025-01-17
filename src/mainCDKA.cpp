#include "jeu.h"
#include <iostream>
using namespace std;

int main()
{
    Jeu Jeu;
    Joueur joueur=Jeu.getJoueur();
    Noeud* noeud;
    noeud=Jeu.getCNoeud();

    string pTexte; //Les futurs réponses du joueur dans le main;
    Dialogue* d;
    Combat* c;

    while(!Jeu.getGraphe().isFeuille(noeud))
    {
        if (noeud->getDelim()=='d')
        {
            int isValid=-1;
            while(isValid==-1)
            {
                d=(Dialogue*) noeud;

                cout<<d->getTexte()<<endl<<d->getRep()<<endl<<endl<<"Choix : ";
                cin>>pTexte;
                isValid =d->rep(pTexte);

                if (isValid!=-1) Jeu.getGraphe().parcoursGraphe(isValid);
                else cout<<"Reponse invalide au dialogue"<<endl;
            }
        }else
        if (noeud->getDelim()=='c')
        {
            c=(Combat*) noeud;
            while(c->isFight(joueur)==-1)
            {   
                c->affStat(joueur);
                int target =0;
                cout<<endl<<endl<<"Action joueur: ";
                cin>>pTexte;
                if (isdigit(pTexte[0]))
                {
                    target=pTexte[0]-'0';
                    pTexte.erase(0,1);
                }
                int iSort = c->castSort(joueur, pTexte);
                
                if (iSort!=-1)
                {
                    c->playTurn(joueur,iSort, target);
                }
                if(c->isFight(joueur)==-1)
                {
                    c->ennTurn(joueur);
                }  
            }
            Jeu.getGraphe().parcoursGraphe(c->isFight(joueur));
        }

        noeud=Jeu.getCNoeud(); //avancer dans le jeu en fonction des résultats
    }
    d=(Dialogue*) noeud;
    cout<<d->getTexte()<<endl;//Dialogue de fin
    return 0;
}










