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
  return this->id_tuile;
}

//retourne le contenu de la main
vector<Case *> Joueur::get_main() const {
  
}
/*
        void afficher_main() const;

        void ajouter_carte ()const;

        void supprimer_carte ()const;

        virtuel void choisir_carte() = 0;

        void init_main () const;

*/