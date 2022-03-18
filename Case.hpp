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
        void ajouter_joueur(Joueur* j);
        void retirer_joueur(Joueur* j);
        friend ostream& operator<<(ostream& os,Case const& v);

};

ostream& operator<<(ostream& os,Case const& case_jeu){
    for(Joueur *j : case_jeu.get_joueurs()){
        os << j->get_tuile() << endl;
    };
    return os;
}


#endif