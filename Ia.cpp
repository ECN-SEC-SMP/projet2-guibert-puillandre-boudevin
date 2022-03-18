#include <iostream>
#include <cstdlib>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"

Ia::Ia(string name, Deck &deck):Joueur(name, deck) //constructeur
{
  this->status="Ia";
}