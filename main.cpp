#include <iostream>
#include "Partie.hpp"
#include "Plateau.hpp"
#include "Manuel.hpp"
#include "Ia.hpp"
#include "Cartes.hpp"

int main() {

  std::cout << "test" << endl;
  Manuel* m = new Manuel("Jean");
  Manuel* m2 = new Manuel("Bernard");
  Ia* b = new Ia("Bot");
  Ia* b2 = new Ia("E.T");
  Partie* p = new Partie();
  p->ajouter_jouer(m2);
  p->ajouter_jouer(m);
  p->ajouter_jouer(b);
  p->ajouter_jouer(b2);
  p->demarrer_partie();
}