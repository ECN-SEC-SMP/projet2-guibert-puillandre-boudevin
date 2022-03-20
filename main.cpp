#include <iostream>
#include "Partie.hpp"
#include "Plateau.hpp"
#include "Manuel.hpp"
#include "Cartes.hpp"

int main() {

  std::cout << "test" << endl;
  Manuel* m = new Manuel("test");
  Manuel* m2 = new Manuel("bernard");
  Partie* p = new Partie();
  p->ajouter_jouer(m2);
  p->ajouter_jouer(m);
  p->demarrer_partie();
}