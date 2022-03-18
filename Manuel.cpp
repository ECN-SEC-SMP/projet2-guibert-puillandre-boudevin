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
void Manuel::choisir_carte(){
// on regarde les cartes
std::cout << this; 

//choisir une carte
std::cout << "veuillez choisir une carte\n";
std::cout << "rentrez votre n° de carte :\n";
  


  
}