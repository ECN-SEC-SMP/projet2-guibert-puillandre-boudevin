#pragma once
#ifndef Cartes_hpp
#define Cartes_hpp

#include <iostream>
#include <list>


using namespace std;



class Cartes {

    public:

      enum Couleur_carte { rouge, jaune, bleu, vert, violet, neutre };

      Cartes(Couleur_carte couleur_carte, int nb_cases);

      virtual void effet() = 0;

      void set_couleur(Couleur_carte couleur);
      Couleur_carte get_couleur() const;

    friend ostream& operator<<(ostream& s,Cartes const& v);


    protected:

        Couleur_carte couleur_carte;
        int nb_cases

    private:

      conv_couleur_j_cartes()

};

ostream& operator<<(ostream& s,Cartes const& v);

#endif 