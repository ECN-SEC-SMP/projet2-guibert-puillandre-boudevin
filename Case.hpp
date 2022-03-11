//!@file Case.h
//!@brief classe mère de chance, Prison, Depart et achetable
//!@author Valentin

#ifndef Case_h 
#define Case_h 

#include <iostream>
#include <stdio.h>

using namespace std;

#include "Joueur.h"

class Case{ 

    protected:
    
        vector<Joueur*> tortues_presentes;

    public:

        vector<Joueur*> get_joueurs() const;

        //virtual ~Vehicule();
        friend ostream& operator<<(ostream& s,Vehicule const& v);

};


// opérateur d'affichage
ostream& operator<<(ostream& s,Vehicule const& v);

#endif