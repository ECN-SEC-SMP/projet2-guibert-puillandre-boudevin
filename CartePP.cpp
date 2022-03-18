#include "CartePP.hpp"
#include "Cartes.hpp"
#include "Plateau.hpp"

#include <iostream>

using namespace std;









CartePP::CartePP(Cartes::Couleur_carte couleur_carte, int nb_cases):Cartes(couleur_carte, nb_cases){
  this->couleur_carte = couleur_carte;
  this->nb_cases=nb_cases;
}


void CartePP::effet(){
  
  
}