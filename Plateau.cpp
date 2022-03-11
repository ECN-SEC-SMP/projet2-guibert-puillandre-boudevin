#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <vector>       // std::vector

using namespace std;

#include "Plateau.hpp"
#include "Case.hpp"
#include "Deck.hpp"

//constructeur
Plateau::Plateau(){
  this->plateau_de_jeu.clear();
};

void Plateau::initPlateau(){
  //Initialisation du plateau de jeu
  vector<Case *> vec_cases;
  //On créé dix cases au sein du plateau
  for (int i = 0; i < 10; i++)
  {
    vec_cases.push_back(new Case());
  }
  //On a besoin de resize afin d'ajuster la place mémoire du vector à la taille du plateau de jeu 
  this->plateau_de_jeu.resize(vec_cases.size());
  copy(vec_cases.begin(),vec_cases.end(),this->plateau_de_jeu.begin());

};

void Plateau::affichage_plateau() const{
  cout << "Différentes cases du terrain : " << endl;
  for(Case* c : this->plateau_de_jeu)
  {
    cout << *c << endl;
  }
};


vector<Case *> Plateau::get_plateau_de_jeu() const{
  return this->plateau_de_jeu;
};

Case* 

void Plateau::deplacer_joueurs(vector<Joueur* j>,int nb_cases){
    
}