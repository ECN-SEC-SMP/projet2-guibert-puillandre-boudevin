#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"
#include <time.h>       /* time */
#include <vector>

Joueur::Joueur(string name)//constructeur
{
  this->id_tortue = current_id_to_give;
  // donner couleur
  srand (time(NULL));
  int coul = rand() % 4;
  // 0: rouge 1 :jaune 2: bleu 3:vert 4:violet
  // couleur pas prise
  while(couleur[coul]!=0){
    coul ++;
    coul = coul % 5;
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

void Joueur::supprimer_carte (Cartes* c, Deck *deck){
  deck->ajouter_cartes_defausse(c);
  this->main_joueur.erase(std::remove(this->main_joueur.begin(), this->main_joueur.end(), c), this->main_joueur.end()); 
}

Joueur::Couleur_joueur Joueur::get_choix ()const {
  return this->choix_couleur;
}

ostream& operator<<(ostream& os,Joueur const& j){
    os << "Nom : " <<  j.get_nom() << endl;
    switch (j.get_tuile())
    {
    case Joueur::rouge:
      os <<  "Couleur : rouge" << endl;
      break;
    case Joueur::jaune:
      os <<  "Couleur : jaune"  << endl;
      break; 
    case Joueur::bleu:
      os <<  "Couleur : bleu" << endl;
    break;
    case Joueur::violet:
      os <<  "Couleur : violet" << endl;
    break;
    case Joueur::vert:
      os <<  "Couleur : vert" << endl;
    break;
    default:
      os << "Error : Unkown color player" << endl;
      break;
    }
    os << "Main :" << endl;
    int i = 1;
    for(Cartes* c : j.main_joueur){
      os << "Carte n°" + to_string(i) << " " << *c << endl;
      i++;
    };
    return os;
}

void Joueur::afficher_main() const{
  int i = 1;
  for(Cartes* c : this->main_joueur){
    cout << "Carte n°" + to_string(i) << " " << *c << endl;
    i++;
  };
}