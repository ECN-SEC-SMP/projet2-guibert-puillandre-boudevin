#ifndef Manuel_hpp 
#define Manuel_hpp 

#include "Joueur.hpp"
#include "Cartes.hpp"

class Manuel : public Joueur { 

  public :

    //! @brief la méthode choisir une carte permet ici de choisir une carte parmis les 5 de la mains du joueur et d'effectuer son effet
    //! @return void

    virtual Cartes* choisir_carte(Deck* deck) override ; 
    Manuel(string name, Deck *deck);

};

#endif