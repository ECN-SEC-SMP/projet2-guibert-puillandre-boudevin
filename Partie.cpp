#include <string>
#include <iostream>
#include <assert.h>
extern "C"{
    #include <unistd.h>
}
using namespace std;

#include "Partie.hpp"

// constructeur
Partie::Partie(){
  this->joueur_actuel = nullptr;
  this->list_joueurs.clear();
  //On initialise un nouveau plateau de jeu
  this->Plat = new Plateau();
  this->Plat->initPlateau();
}; 

//Une fois que la quantité de joueurs inscrite est suffisante on peut démarrer une partie 
void Partie::demarrer_partie(){

  if(this->list_joueurs.size() < 2){
    cout << "Nombre de joueurs requis insuffisants" << endl;
    exit(-1);
  }
  else if(this->list_joueurs.size() > 5){
    cout << "Nombre de joueurs trop élevé" << endl;
    exit(-1);
  }
  this->joueur_actuel = this->list_joueurs.front();
  //On joue tant qu'il n'y a pas un joueur gagnant 
  do{
    //Tous les 10 tours on fait un point sur la situation des joueurs
    if(nb_tours % (10*this->list_joueurs.size()) == 0){this->affiche();}
    sleep(1);
  }
  while(!this->tour_de_jeu());

};

bool Partie::tour_de_jeu() // joue le tour
{

    //Le joueur choisit une carte à jouer
    Carte carte_a_jouer = this->joueur_actuel->choisi_carte();

    int numero_case = this->Plat->get_index_case_joueur(this->joueur_actuel);

    cout << "Au tour de : " << this->joueur_actuel->get_nom() << endl << 
    "Case actuelle :" << numero_case << endl;

    //Avancer le joueur 
    this->Plat->deplacer_joueurs(carte_a_jouer.effet());

    //Affiche la case d'arrivee
    cout << this->Plat << endl;
 
    cout << "--------------Fin du tour-----------------" << endl;
    //On passe au joueur suivant de la liste
    this->joueur_suivant();

    //Est-ce que la partie est terminée ? 
    return this->finDePartie();
}

void Partie::joueur_suivant(){
    //Changer de joueur
    list<Joueur *>::iterator l_front = find(this->list_joueurs.begin(),this->list_joueurs.end(),this->joueur_actuel);
    nb_tours++;
    //On vérifie que l'on est pas sur le dernier élément de la liste, si c'est le cas on revient au début 
    if(distance(l_front,this->list_joueurs.end()) == 1){
      l_front = this->list_joueurs.begin();
    }
    else{
      advance(l_front, 1);
    }
    this->joueur_actuel = *l_front;
}

//Si il y a moins de 5 joueurs
bool Partie::ajouter_joueurs(Joueur *j) //ajout de joueur
{
  if(this->list_joueurs.size() > 5){
    return false;
  }
  else{
    this->list_joueurs.push_back(j);
    return true;
  }
}

Joueur* Partie::get_joueur_actuel() const //renvoie le joueur actuel
{
  return this->joueur_actuel;
}

bool Partie::finDePartie() const{
  return this->list_joueurs.size() == 1;
}