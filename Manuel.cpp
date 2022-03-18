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
Cartes* Manuel::choisir_carte(){
// on regarde les cartes
std::cout << this; 

  int carte_choisie;

//choisir une carte
std::cout << "veuillez choisir une carte\n";
std::cout << "rentrez votre n° de carte :\n";
cin >> carte_choisie ;

/*
  
if neutre 
  choisir couleur

*/
return this->main_joueur[carte_choisie];

  
}