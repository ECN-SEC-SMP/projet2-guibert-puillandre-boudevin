#include "Cartes.hpp"
#include "Plateau.hpp"

#include <iostream>

using namespace std;

// constructeur de Cartes
Cartes::Cartes(Couleur_carte couleur_carte, int nb_cases){
  this->couleur_carte = couleur_carte;
  this->nb_cases = nb_cases;
};


void Cartes::set_couleur(Couleur_carte couleur){
  this->couleur_carte = couleur;
}

Cartes::Couleur_carte Cartes::get_couleur() const {
  return this->couleur_carte;
}

