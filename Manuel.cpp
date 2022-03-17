#include <iostream>
#include <cstdlib>
using namespace std;

#include "Joueur.hpp"
#include "Deck.hpp"

Manuel::Manuel(string name):Joueur(name) //constructeur
{
  this->status="Manuel";
}