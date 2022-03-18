#include "Cartes.hpp"
#include "Plateau.hpp"

#include <iostream>

using namespace std;

// constructeur de Cartes
Cartes::Cartes(Couleur_carte couleur_j, int nb_cases){
  this->couleur_j = couleur_j;
  this->nb_cases = nb_cases;
};


void Cartes::set_couleur(string couleur){
  this->couleur_j = couleur;
}


void deplacer_joueurs_couleur(Joueur::Couleur_joueur couleur,int nb_cases);


