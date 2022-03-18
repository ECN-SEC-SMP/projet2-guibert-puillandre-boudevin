#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"
#include <time.h>       /* time */
#include <vector>

Joueur::Joueur(string name, Deck *deck)//constructeur
{
  this->id_tortue = current_id_to_give;
  // donner couleur
  srand (time(NULL));
  int coul = rand() % 4;
  
  // 0: rouge 1 :jaune 2: bleu 3:vert 4:violet
  // couleur pas prise
  while(couleur[coul]!=1){
    coul ++;
    coul = coul % 4;
  }
  // on prend la couleur
  couleur[coul] = 1;
  switch(coul){
      case 0:
        this->tuile = Joueur::Couleur_joueur{rouge} ;
      break;

      case 1:
        this->tuile = Joueur::Couleur_joueur{jaune} ;
      break;

      case 2:
        this->tuile = Joueur::Couleur_joueur{bleu} ;
      break;

      case 3:
        this->tuile = Joueur::Couleur_joueur{vert} ;
      break;

      case 4:
        this->tuile = Joueur::Couleur_joueur{violet} ;
      break;
    }
  
  

  current_id_to_give++;
  this->nom = name;
  // clear la main 
  this->main_joueur.clear();
  // init main
  this->init_main(deck);
}

string Joueur::get_nom() const{
  return this->nom;
}
int Joueur::get_id() const//renvoi l'id du joueur / tortue
{
  return this->id_tortue;
}

Joueur::Couleur_joueur Joueur::get_tuile() const//renvoi la tuile du joueur
{
  return this->tuile;
}
//retourne le contenu de la main
vector<Cartes *> Joueur::get_main() const {
  return this->main_joueur;
}

void Joueur::ajouter_carte (Deck *deck){
  Cartes* c = deck->tirer_carte_pioche();
  this->main_joueur.push_back(c);

}
void Joueur::supprimer_carte (int num_carte){
    
  this->main_joueur.erase(this->main_joueur.begin() + num_carte-1);

}
void Joueur::init_main (Deck *deck) {

  for (int i=0; i<this->main_joueur.size(); i++){
  this->ajouter_carte (deck);
  }
}
