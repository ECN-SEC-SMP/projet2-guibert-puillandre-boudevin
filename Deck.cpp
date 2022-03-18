#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <vector>       // std::vector
using namespace std;

#include "Deck.hpp"
#include "Cartes.hpp"
#include "CartePP.hpp"

Deck::Deck(){
    this->pioche.clear();
    this->defausse.clear();
    //Ajout cartes ++
    this->pioche.push_back(new Cartes(Cartes::rouge,2));
    this->pioche.push_back(new Cartes(Cartes::jaune));
    this->pioche.push_back(new CartePP(Cartes::vert));
    this->pioche.push_back(new CartePP(Cartes::violet));
    this->pioche.push_back(new CartePP(Cartes::bleu));
    //Ajout des cartes +
    for(int i = 0; i < 5; i++){
        this->pioche.push_back(new CartePP(Cartes::rouge));
        this->pioche.push_back(new CartePP(Cartes::jaune));
        this->pioche.push_back(new CartePP(Cartes::vert));
        this->pioche.push_back(new CartePP(Cartes::violet));
        this->pioche.push_back(new CartePP(Cartes::bleu));  
        this->pioche.push_back(new CartePP(Cartes::neutre));
    }
    //Ajout des cartes -
    for(int i = 0; i < 2; i++){
        this->pioche.push_back(new CartePP(Cartes::rouge));
        this->pioche.push_back(new CartePP(Cartes::jaune));
        this->pioche.push_back(new CartePP(Cartes::vert));
        this->pioche.push_back(new CartePP(Cartes::violet));
        this->pioche.push_back(new CartePP(Cartes::bleu));  
        this->pioche.push_back(new CartePP(Cartes::neutre));
    }
    //Ajout des cartes neutre => =>
    for(int i = 0; i < 2; i++){
        this->pioche.push_back(new CartePP(Cartes::neutre));
    }
    //Ajout des cartes neutre =>
    for(int i = 0; i < 3; i++){
        this->pioche.push_back(new CartePP(Cartes::neutre));
    }
}

Cartes* Deck::tirer_carte_pioche(){
    if(this->pioche.size() == 0 ){
        for(Cartes* carte : this->defausse){
            this->pioche.push_back(carte);
            this->melanger_cartes_pioche();
        }
        this->defausse.clear();
    }
    return this->pioche.front();
}

void Deck::melanger_cartes_pioche(){
    std::random_shuffle(this->pioche.begin(), this->pioche.end());
}

void Deck::ajouter_cartes_defausse(Cartes* c){
    this->defausse.push_back(c);
}