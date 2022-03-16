#include <iostream>
#include <cstdlib>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"

Ia::Ia(string name):Joueur(name) //constructeur
{
  this->status="Ia";
}