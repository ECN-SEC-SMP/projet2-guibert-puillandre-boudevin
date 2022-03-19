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

// Joueur::Couleur_joueur Cartes::conv_couleur_j_cartes(){
//   switch(this->couleur_carte){
//     case rouge:
//       return Joueur::rouge;
//     break;
//     case jaune:
//       return Joueur::jaune;
//     break;
//     case vert:
//       return Joueur::vert;
//     break;
//     case violet:
//       return Joueur::violet;
//     break;
//     case bleu:
//       return Joueur::bleu;
//     break;
//     case neutre:
//       return Joueur::chosir_couleur();
//     break;
//   }
  
// }

int Cartes::get_nb_cases() const{
  return this->nb_cases;
}