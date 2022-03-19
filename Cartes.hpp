#ifndef Cartes_hpp
#define Cartes_hpp

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <vector>       // std::vector

using namespace std;

class Cartes {

    public:

      enum Couleur_carte { rouge, jaune, bleu, vert, violet, neutre };

      Cartes(Couleur_carte couleur_carte, int nb_cases);

      void set_couleur(Couleur_carte couleur);
      Couleur_carte get_couleur() const;
      int get_nb_cases() const;

      friend ostream& operator<<(ostream& os,Cartes const& carte);

    protected:

        Couleur_carte couleur_carte;
        int nb_cases;

};

ostream& operator<<(ostream& os,Cartes const& carte){
  os<< "Cartes : " << std::endl;
  os<< "Couleur carte : " << carte.get_couleur() << std::endl;
  os<< "Nombre cases effet : " << carte.get_nb_cases() << std::endl;
  return os;
}

#endif 