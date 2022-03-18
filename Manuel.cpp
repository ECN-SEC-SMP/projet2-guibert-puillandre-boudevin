#include <iostream>
#include <cstdlib>
using namespace std;
#include <string>



#include "Deck.hpp"
#include "Joueur.hpp"
#include "Manuel.hpp"

Manuel::Manuel(string name, Deck* deck):Joueur(name, deck) //constructeur
{
}


Cartes* Manuel::choisir_carte(Deck* deck){
  // on regarde les cartes
  std::cout << this; 
  int carte_choisie;

  //choisir une carte
  std::cout << "veuillez choisir une carte\n";
  std::cout << "rentrez votre n° de carte :\n";
  cin >> carte_choisie ;

  Cartes::Couleur_carte couleur = this->main_joueur[carte_choisie]->get_couleur();
  if ( couleur == Cartes::neutre){
    //choisir couleur
    string couleur;
    std::cout << "votre carte est neutre, veuillez choissir une couleur (rouge, jaune, bleu, vert, violet )\n";
    cin >> couleur ;
    this->set_choix(couleur);
  }

  
  // valentin except couleur pas correct, couleur hors string rouge, jaune, bleu, vert, violet

  // copie
  Cartes* c = this->main_joueur[carte_choisie];

  //supprimer
  this->supprimer_carte(c,deck);

  //pioche
  this->ajouter_carte(deck);
  
// return carte
return c;
}