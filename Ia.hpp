#ifndef Ia_hpp 
#define Ia_hpp 

#include "Joueur.hpp"
#include "Cartes.hpp"

class Ia : public Joueur { 

  public :
  Ia(string name);
    
  virtual Joueur::Couleur_joueur choisir_couleur() override;
//! @brief la méthode choisir une carte permet ici de choisir une carte parmis les 5 d la mains du joueur et d'effectuer son effet
//! @return void
  virtual Cartes* choisir_carte(Deck* deck) override ;

};

#endif