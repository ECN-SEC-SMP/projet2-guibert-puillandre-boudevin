#ifndef Deck_hpp 
#define Deck_hpp 

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <vector>       // std::vector
using namespace std;

#include "Cartes.hpp"

class Deck  { 

    private : 

        vector<Cartes *> pioche;
        vector<Cartes *> defausse;

    public :

        Deck();
        Cartes* tirer_carte_pioche();
        void melanger_cartes_pioche();
        void ajouter_cartes_defausse(Cartes* c);

};


#endif