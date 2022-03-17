#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"



Joueur::Joueur(string name) //constructeur
{
  this->id_tortue = current_id_to_give;
  this->tuile = current_id_to_give;
  current_id_to_give++;
  this->nom = name;

  // clear la main 
  this->main.clear();
}

void Joueur::afficher_joueur() const{
  cout << "Nom : " << this->get_nom() << endl;
}


string Joueur::get_nom() const{
  return this->nom;
}


int Joueur::get_id() const//renvoi l'id du joueur / tortue
{
  return this->id_tortue;
}

int Joueur::get_tuile() const//renvoi la tuile du joueur
{
  return this->tuile;
}
/*
//retourne le contenu de la main
vector<Carte *> Joueur::get_main() const {
  
}

void Joueur::afficher_main() const{


}


void Joueur::ajouter_carte (Deck &deck)const{

  this->main.push_back(deck.piocher);

}
void Joueur::supprimer_carte (int num_carte)const{


  this->main.erase(this->main.begin() + num_carte-1);

}
void init_main (Deck &deck) const{

  for (i=0; i>=4; i++){
  this->ajouter_carte (deck);
  }
}

*/