#include <iostream>
#include <cstdlib>
using namespace std;
#include <string>

#include "Deck.hpp"
#include "Joueur.hpp"
#include "Manuel.hpp"

Manuel::Manuel(string name):Joueur(name) //constructeur
{
}

Joueur::Couleur_joueur choisir_couleur(){
    cout << "Une carte neutre a été utilisé. Entrer la couleur du joueur cible (rouge,bleu,jaune,vert,violet)" << endl;
    string couleur;
    do
    {
      cin >> couleur;
      if (couleur == "rouge"){
        return Joueur::rouge;
      }
      else if (couleur == "jaune"){
        return Joueur::jaune;
      }
      else if (couleur == "bleu"){
        return Joueur::bleu;
      }
      else if (couleur == "vert"){
        return Joueur::vert;
      }
      else if (couleur == "violet"){
        return Joueur::violet;
      }
      else{
        cout << "Couleur non reconnue, entrez une couleur valdie (rouge,bleu,jaune,vert,violet)" << endl;
      }
    } while (couleur != "violet" && couleur != "rouge" && couleur != "jaune" && couleur != "bleu" && couleur != "vert" );
    
}

Cartes* Manuel::choisir_carte(Deck* deck){
  // on regarde les cartes
  std::cout << this; 
  int carte_choisie;

  //choisir une carte
  std::cout << "veuillez choisir une carte\n";
  std::cout << "rentrez votre n° de carte :\n";
  cin >> carte_choisie ;

  // copie
  Cartes* c = this->main_joueur[carte_choisie];

  //supprimer
  this->supprimer_carte(c,deck);

  //pioche
  this->ajouter_carte(deck);
  
  // return carte
  return c;
}