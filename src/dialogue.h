#ifndef _DIALOGUE_H
#define _DIALOGUE_H
#include <string>
#include <vector>
#include "noeud.h"
const int MAXREP= 5;

using namespace std; 

class Dialogue : public Noeud{
 private: 
    string texte; 
    std::vector <string> reponse; 
public:
    Dialogue();
    /**
     * @brief initialise un noeud dialogue avec les paramètres
     * @param ind indice du noeud
     * @param nom nom du noeud
     * @param txt le texte du dialogue
     * @param rep tableau des réponses
     * @param nb nombre de réponses
    */
    Dialogue(int ind, string nom, string txt, string rep[MAXREP],int nb, char d);
    /**
     * @brief texte object
     * 
     * @return string 
     */
    string getTexte();
    /**
     * @brief renvoi une string avec les réponses du dialogue
     * 
     * @return string 
     */
    string getRep();
    /**
     * @brief l'indice relatif du noeud suivant
     * @return int
    */
    int rep(string word);

};
#endif