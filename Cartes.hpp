#pragma once
#ifndef Cartes_hpp
#define Cartes_hpp

#include <iostream>
#include <list>
#include "Joueur.hpp"


using namespace std;

class Cartes {

    public:

      enum Couleur_carte { rouge, jaune, bleu, vert, violet, neutre };

      Cartes(Couleur_carte couleur_carte, int nb_cases);

      void set_couleur(Couleur_carte couleur);
      Couleur_carte get_couleur() const;
      int get_nb_cases() const;

      friend ostream& operator<<(ostream& s,Cartes const& v);

    protected:

        Couleur_carte couleur_carte;
        int nb_cases;
        Joueur::Couleur_joueur conv_couleur_j_cartes();

};

ostream& operator<<(ostream& s,Cartes const& p);

#endif 