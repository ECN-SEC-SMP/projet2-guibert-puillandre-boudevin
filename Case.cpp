#include "Case.hpp"

#include <iostream>

using namespace std;

Case::Case(){
    this->tortues_presentes.clear();
}

vector<Joueur*> Case::get_joueurs() const{
    return this->tortues_presentes;   
}

void Case::ajouter_joueur(Joueur* j){
    this->tortues_presentes.push_back(j);
}

void Case::retirer_joueur(Joueur* j){
      this->tortues_presentes.erase(std::remove(this->tortues_presentes.begin(), this->tortues_presentes.end(), j), this->tortues_presentes.end()); 
}

ostream& operator<<(ostream& os,Case const& case_jeu){
    for(Joueur *j : case_jeu.get_joueurs()){
        switch (j->get_tuile())
        {
            case Joueur::rouge:
                os <<  "Tortue rouge" << endl;
            break;
            case Joueur::jaune:
                os <<  "Tortue jaune"  << endl;
            break; 
            case Joueur::bleu:
                os <<  "Tortue bleu" << endl;
            break;
            case Joueur::violet:
                os <<  "Tortue violet" << endl;
            break;
            case Joueur::vert:
                os <<  "Tortue vert" << endl;
            break;
            default:
                os << "Error : Unkown color player" << endl;
            break;
        }
    };
    return os;
}