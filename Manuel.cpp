#include <iostream>
#include <cstdlib>
using namespace std;

#include "Deck.hpp"
#include "Joueur.hpp"
#include "Manuel.hpp"

Manuel::Manuel(string name, Deck &deck):Joueur(name, deck) //constructeur
{
  this->status="Manuel";
}
void Manuel::choisir_carte(){

std::cout << Manuel
  
}