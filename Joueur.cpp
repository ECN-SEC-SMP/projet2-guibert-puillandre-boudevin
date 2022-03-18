#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"
#include <time.h>       /* time */

Joueur::Joueur(string name, Deck &deck)//constructeur
{
  this->id_tortue = current_id_to_give;
  // donner couleur
  srand (time(NULL));
  int coul = rand() % 4;
  
  // 0: rouge 1 :jaune 2: bleu 3:vert 4:violet
  // couleur pas prise
  while(couleur[coul]!=0){
    coul ++;
      coul % 4;
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
  this->main.clear();
  // init main
  this->init_main(deck);
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

Couleur_joueur Joueur::get_tuile() const//renvoi la tuile du joueur
{
  return this->tuile;
}
/*
//retourne le contenu de la main
vector<Carte *> Joueur::get_main() const {
  return this->main;
}

void Joueur::ajouter_carte (Deck &deck)const{

  this->main.push_back(deck.piocher);

}
void Joueur::supprimer_carte (int num_carte)const{


  this->main.erase(this->main.begin() + num_carte-1);

}
void init_main (Deck &deck) const{

  for (i=0; i<this->main.size(); i++){
  this->ajouter_carte (deck);
  }
}

*/