//!@file Partie.h
//!@brief Classe Plateau, permet de décrire le plateau de jeu
//!@author Valentin 

#ifndef Plateau_hpp
#define Plateau_hpp

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <vector>       // std::vector

using namespace std;

#include "Case.hpp"
#include "Joueur.hpp"
#include "Deck.hpp"

class Plateau{ 

protected:

    vector<Case *> plateau_de_jeu; /*!< plateau_de_jeu contient les différentes cases du plateau (peuvent être soit Constructible, Achetable, Depart, Prison, Chance, Gares)*/
    vector<Joueur *> liste_de_joueurs;
    Deck* deck_de_la_partie;

public:

    //!@brief Affichage de l'ensemble des cases du plateau de jeu
    void affichage_plateau() const;

    //!@brief Permet de remplir le plateau d'un terrain de jeu classique de monopoly
    void initPlateau(); 

    //!@brief Constructeur de la classe Plateau
    Plateau();

    //!@brief Permet de récupérer le plateau de jeu actuel
    //!@return retourne le contenu de plateau_de_jeu
    vector<Case *> get_plateau_de_jeu() const;

    //!@brief Supprime l'ensemble des propriétés associées à un joueur et enlève les maisons et immeubles qui pouvaient être présents
    //!@param j cible est un pointeur vers un objet de type joueur
    void deplacer_joueurs(Joueur* j,int nb_cases);

    void ajouter_joueur(Joueur* j);
    
    Case* get_case_joueurs(Joueur* j);
    
    int get_index_case_joueur(Joueur* j);

    vector<Joueur*> get_liste_joueurs();

    friend ostream& operator<<(ostream& s,Plateau const& v);

};

ostream& operator<<(ostream& s,Plateau const& v);

#endif