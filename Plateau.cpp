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
  //1---CREATION DU PLATEAU DE JEU

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

  //2---ON REMPLIT LE DECK POUR LA PARTIE
  this->deck_de_la_partie = new Deck();
  this->deck_de_la_partie->melanger_cartes_pioche();

  //4---POSITIONNEMENT DES JOUEURS SUR LE PLATEAU
  for(Joueur* j : this->liste_de_joueurs)
  {
    this->plateau_de_jeu.front()->ajouter_joueur(j);
    //5--ON DISTRIBUE UNE MAIN POUR CHAQUE JOUEUR
    for(int i = 0; i < 5; i++){
      j->ajouter_carte(this->deck_de_la_partie);
    }
  }

};

void Plateau::affichage_plateau() const{
  cout << "Différentes cases du terrain : " << endl;
  for(Case* c : this->plateau_de_jeu)
  {
    cout << *c << endl;
  }
};

void Plateau::deplacer_joueurs(Joueur* j,int nb_cases){
  int numero_case = this->get_index_case_joueur(j);
  for(Case* c : this->plateau_de_jeu){
    //On cherche la case actuelle du joueur
    if (std::find(c->get_joueurs().begin(), c->get_joueurs().end(), j) != c->get_joueurs().end()) {
      //On détermine la case sur laquelle le nouveau joueur doit se situer
      int index_nouvelle_case;
      if(numero_case+nb_cases >= 10){
        index_nouvelle_case = 10;
      }
      else if(numero_case+nb_cases <= 0){
        index_nouvelle_case = 0;
      }
      else{
        index_nouvelle_case = numero_case+nb_cases;
      }
      Case* nouvelle_case = this->plateau_de_jeu[index_nouvelle_case];
      //On déplace tous les joueurs au dessus du joueur, avec celui-ci
      if(nouvelle_case != this->get_case_joueurs(j)){
        for(Joueur* joueur_case : c->get_joueurs()){
          //On le place sur la nouvelle carte
          nouvelle_case->ajouter_joueur(joueur_case);
          //On le retire de la case actuelle
          c->retirer_joueur(joueur_case);
          if(j == joueur_case){
            break;
          }
        }
      }
      break;
    }
    numero_case++;
  }
}

void Plateau::deplacer_joueurs_couleur(Joueur::Couleur_joueur couleur,int nb_cases){
  for(Joueur* j : this->liste_de_joueurs){
    if(j->get_tuile() == couleur){
      this->deplacer_joueurs(j,nb_cases-1);
    }
  }
}
void Plateau::ajouter_joueur(Joueur* j){
  try
  {
    if(this->liste_de_joueurs.size() > 5){
      throw string("Nombre de joueurs trop élevé");
    }
  this->liste_de_joueurs.push_back(j);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

int Plateau::get_index_case_joueur(Joueur* j) const{
  try
  {
    int numero_case = 0;
    for(Case* c : this->plateau_de_jeu){
      //On cherche la case actuelle du joueur
      if (std::find(c->get_joueurs().begin(), c->get_joueurs().end(), j) != c->get_joueurs().end()) {
        return numero_case;
      }
      numero_case++;
    }
    throw string("Exception : Player not found on a Case");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

Case* Plateau::get_case_joueurs(Joueur* j) const{
  try
  {
    for(Case* c : this->plateau_de_jeu){
      //On cherche la case actuelle du joueur
      if (std::find(c->get_joueurs().begin(), c->get_joueurs().end(), j) != c->get_joueurs().end()) {
        return c;
      }
    }
    throw string("Exception : Player not found on a Case");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

vector<Joueur*> Plateau::get_liste_joueurs() const{
  return this->liste_de_joueurs;
}

vector<Case *> Plateau::get_plateau_de_jeu() const{
  return this->plateau_de_jeu;
};

Deck* Plateau::get_deck() const{
  return this->deck_de_la_partie;
}

ostream& operator<<(ostream& os,Plateau const& plateau){
    int i = 0;
    os << "----------" << i << "-----------" << endl;
    for(Case *c : plateau.get_plateau_de_jeu()){
        i++;
        os << *c;
        os << "----------" << i << "-----------" << endl;
    };
    return os;
}