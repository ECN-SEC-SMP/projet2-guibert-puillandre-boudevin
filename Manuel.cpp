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

Joueur::Couleur_joueur Manuel::choisir_couleur(){
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
  while (true)
  {
    std::cout << "Veuillez choisir une carte" << endl;
    std::cout << "Rentrez votre n° de carte : ";
    int carte_choisie;
    try
    {
      cin >> carte_choisie ;
      if(cin.fail()){
        throw "Error reading value";
      }
      if(carte_choisie < 1 || carte_choisie > 5){
        throw "Error numero de carte non valide";
      }
      // copie
      Cartes* c = this->main_joueur[carte_choisie-1];

      //supprimer
      this->supprimer_carte(c,deck);

      //pioche
      this->ajouter_carte(deck);
      
      // return carte
      return c;
    }
    catch(const std::exception& e)
    {

    }
  }
  

}