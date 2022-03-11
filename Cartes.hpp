#pragma once
#ifndef Cartes_hpp
#define Cartes_hpp

#include <iostream>
#include <list>


using namespace std;

class Cartes {

    protected:

        Couleur_carte couleur_carte;

    public:

    struct Resultat_effet {
      Couleur_joueur couleur_j;
      int nb_cases;
    }

    enum Couleur_carte { rouge, jaune, bleu, vert, violet, neutre };

    virtual Resultat_effet effet() = 0;

    void set_couleur(string couleur);
    string get_couleur() const;



    private : 

    


};

#endif 