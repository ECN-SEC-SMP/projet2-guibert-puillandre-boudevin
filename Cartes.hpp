#pragma once
#ifndef Cartes_hpp
#define Cartes_hpp

#include <iostream>
#include <list>


using namespace std;



class Cartes {

    public:

      enum Couleur_carte { rouge, jaune, bleu, vert, violet, neutre };

      Cartes(Couleur_carte couleur_j, int nb_cases);

      struct Resultat_effet {
        Couleur_carte couleur_j;
        int nb_cases;
      };

      virtual Resultat_effet effet() = 0;

      void set_couleur(string couleur);
      string get_couleur() const;

    protected:

        Couleur_carte couleur_carte;

};

#endif 