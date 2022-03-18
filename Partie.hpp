#ifndef Partie_hpp
#define Partie_hpp

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <algorithm> 
#include <list>

using namespace std;

#include "Joueur.hpp"
#include "Plateau.hpp"

static int nb_tours = 0;

class Partie{

    protected:

        Joueur *joueur_actuel;
        Plateau *Plat ;

    public:

        //!@brief Fonction permettant de récupérer le joueur qui doit actuellement jouer son tour au monopoly
        //!@return Joueur* le joueur qui est le joueur actuel de la partie
        Joueur* get_joueur_actuel() const; //renvoie le joueur actuel

        //!@brief Fonction permettant de démarrer et de jouer la partie de monopoly en mode automatique
        void demarrer_partie(); 

        //!@brief Constructeur de la classe Partie
        Partie();

        //!@brief Affichage de l'ensemble des joueurs de la partie, leur fortune ainsi que les cases qu'ils possèdent. Utilisé tous les 10 tours complets
        void affiche() const;

        Plateau* get_plateau() const;

    private:

        //!@brief Fonction permettant de passer au tour de jeu du joueur suivant
        void joueur_suivant();

        //!@brief Joue le tour du joueur courant de manière automatique
        //!@return retourne vrai tant que la partie doit continuer
        bool tour_de_jeu();

        //!@brief Détermine si la partie est terminé
        //!@return retourne vrai s'il ne reste plus qu'un joueur dans la liste, sinon faux
        bool finDePartie() const;

    friend ostream& operator<<(ostream& os,Partie const& v);

};

ostream& operator<<(ostream& os,Partie const& partie){
    os << "-----Affichage du plateau----" << endl;
    os << partie.get_plateau() << endl;
    os << "------Joueur actuel------" << endl;
    os << partie.get_joueur_actuel() << endl;
    return os;
}


#endif /* Partie_h */