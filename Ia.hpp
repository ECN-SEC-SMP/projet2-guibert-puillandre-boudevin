#ifndef Ia_hpp 
#define Ia_hpp 

#include "Joueur.hpp"
#include "Cartes.hpp"

class Ia : public Joueur { 

  public :
  Ia(string name);
    
  virtual Joueur::Couleur_joueur choisir_couleur() override;
//! @brief la méthode choisir une carte permet ici de choisir une carte parmis les 5 de la mains du joueur et d'effectuer son effet
//! @return void
// l'Ia pour le choix des cartes privilégie son avancer de 2 puis de 1, sinon elle fait reculer un adversaire aléatoire de -2 (carte neutre), sinon elle fait reculer un adversaire alétoire de -1 ou aléatoirement soit elle se fait reculer ou elle fait avancer un joueur de -1, en dernier recourt elle fait avancer un joueur de 2.
  virtual Cartes* choisir_carte(Deck* deck) override ;

};

#endif