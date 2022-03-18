#pragma once
#ifndef CartePP_hpp
#define CartePP_hpp

#include <iostream>
#include <list>

#include "Cartes.hpp"
#include "CartePP.hpp"

using namespace std;

class CartePP : public Cartes {

protected:
    
    public:

    CartePP(Cartes::Couleur_carte couleur_carte, Cartes::int nb_cases);
    
    virtual void effet() override;
    //avance de 2 cases la couleur concernée

};

#endif 