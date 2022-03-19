#include "Cartes.hpp"

#include <iostream>

using namespace std;

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

int Cartes::get_nb_cases() const{
  return this->nb_cases;
}

ostream& operator<<(ostream& os,Cartes const& carte){
  switch (carte.get_couleur())
  {
  case Cartes::rouge:
    os<< "Couleur carte : " << "rouge" ;
    break;
  case Cartes::jaune:
    os<< "Couleur carte : " << "jaune" ;
  break;
  case Cartes::bleu:
    os<< "Couleur carte : " << "bleu" ;
  break;
  case Cartes::violet:
    os<< "Couleur carte : " << "violet" ;
  break;
  case Cartes::vert:
    os<< "Couleur carte : " << "vert" ;
  break;
  case Cartes::neutre:
    os<< "Couleur carte : " << "neutre" ;
  break;
  default:
    os << "Error : Unknown color" ;
    break;
  }
  os<< " | Nombre cases effet : " << carte.get_nb_cases();
  return os;
}