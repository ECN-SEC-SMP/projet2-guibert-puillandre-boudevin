#ifndef Ia_hpp 
#define Ia_hpp 

#include "Joueur.hpp"

class Ia : public Joueur { 

public :
Ia(int price,string nom_const); 
    
//! @brief la méthode choisir une carte permet ici de choisir une carte parmis les 5 d la mains du joueur et d'effectuer son effet
//! @return void
virtual void choisir_carte() override ; //Chance hérite de sa propre classe action

};

#endif