#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <vector>       // std::vector
using namespace std;

#include "Deck.hpp"
#include "Cartes.hpp"

Deck::Deck(){
    this->pioche.clear();
    this->defausse.clear();
    //Ajout cartes ++
    this->pioche.push_back(new Cartes(Cartes::rouge,2));
    this->pioche.push_back(new Cartes(Cartes::jaune,2));
    this->pioche.push_back(new Cartes(Cartes::vert,2));
    this->pioche.push_back(new Cartes(Cartes::violet,2));
    this->pioche.push_back(new Cartes(Cartes::bleu,2));
    //Ajout des cartes +
    for(int i = 0; i < 5; i++){
        this->pioche.push_back(new Cartes(Cartes::rouge,1));
        this->pioche.push_back(new Cartes(Cartes::jaune,1));
        this->pioche.push_back(new Cartes(Cartes::vert,1));
        this->pioche.push_back(new Cartes(Cartes::violet,1));
        this->pioche.push_back(new Cartes(Cartes::bleu,1));  
        this->pioche.push_back(new Cartes(Cartes::neutre,1));
    }
    //Ajout des cartes -
    for(int i = 0; i < 2; i++){
        this->pioche.push_back(new Cartes(Cartes::rouge,-1));
        this->pioche.push_back(new Cartes(Cartes::jaune,-1));
        this->pioche.push_back(new Cartes(Cartes::vert,-1));
        this->pioche.push_back(new Cartes(Cartes::violet,-1));
        this->pioche.push_back(new Cartes(Cartes::bleu,-1));  
        this->pioche.push_back(new Cartes(Cartes::neutre,-1));
    }
    //Ajout des cartes neutre => =>
    for(int i = 0; i < 2; i++){
        this->pioche.push_back(new Cartes(Cartes::neutre,-2));
    }
    //Ajout des cartes neutre =>
    for(int i = 0; i < 3; i++){
        this->pioche.push_back(new Cartes(Cartes::neutre,-1));
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
    Cartes* c = this->pioche.front();
    this->pioche.erase(this->pioche.begin());
    return c;
}

void Deck::melanger_cartes_pioche(){
    std::random_shuffle(this->pioche.begin(), this->pioche.end());
    //     for(Cartes* c : this->pioche){
    //     cout << *c << endl;
    // }
    // int num;
    // cin >> num;
}

void Deck::ajouter_cartes_defausse(Cartes* c){
    this->defausse.push_back(c);
}