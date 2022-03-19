#ifndef Manuel_hpp 
#define Manuel_hpp 

#include "Joueur.hpp"
#include "Cartes.hpp"

class Manuel : public Joueur { 

  public :

    virtual Cartes* choisir_carte(Deck* deck) override ; 
    virtual Joueur::Couleur_joueur choisir_couleur() override;
    Manuel(string name);

};

#endif