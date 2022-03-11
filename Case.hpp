#ifndef Case_hpp
#define Case_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

#include "Joueur.hpp"

class Case{ 

    protected:
    
        vector<Joueur*> tortues_presentes;

    public:

        vector<Joueur*> get_joueurs() const;

        //virtual ~Vehicule();
        friend ostream& operator<<(ostream& s,Case const& v);

};


// opérateur d'affichage
ostream& operator<<(ostream& s,Case const& v);

#endif