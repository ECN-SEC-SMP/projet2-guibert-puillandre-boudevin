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
  //On initialise un nouveau plateau de jeu
  this->Plat = new Plateau();
}; 

//Une fois que la quantité de joueurs inscrite est suffisante on peut démarrer une partie 
void Partie::demarrer_partie(){

  try
  {
    //On vérifie que le nombre de joueurs est valide
    if(this->Plat->get_liste_joueurs().size() < 2){
      throw string("Nombre de joueurs requis insuffisants");
    }
    else if(this->Plat->get_liste_joueurs().size() > 5){
      throw string("Nombre de joueurs trop élevé");
    }
    this->Plat->initPlateau();
    this->joueur_actuel = this->Plat->get_liste_joueurs().front();
    //On joue tant qu'il n'y a pas un joueur gagnant 
    do{
      sleep(1);
    }
    while(!this->tour_de_jeu());
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
};

bool Partie::tour_de_jeu() // joue le tour
{
    nb_tours++;
    //On affiche l'état de la partie 
    this->affiche();
    //On affiche la main du joueur 
    this->joueur_actuel->afficher_main();
    //Le joueur choisit sa carte
    Cartes* carte_a_jouer = this->joueur_actuel->choisir_carte();
    //On réalise l'effet de la carte
    carte_a_jouer->effet(); 
    cout << "--------------Fin du tour-----------------" << endl;
    //On passe au joueur suivant de la liste
    this->joueur_suivant();
    //Est-ce que la partie est terminée ? 
    return this->finDePartie();
}

void Partie::joueur_suivant(){
    //Changer de joueur
    vector<Joueur *>::iterator l_front = find(this->Plat->get_liste_joueurs().begin(),this->Plat->get_liste_joueurs().end(),this->joueur_actuel);
    //On vérifie que l'on est pas sur le dernier élément de la liste, si c'est le cas on revient au début 
    if(distance(l_front,this->Plat->get_liste_joueurs().end()) == 1){
      l_front = this->Plat->get_liste_joueurs().begin();
    }
    else{
      advance(l_front, 1);
    }
    this->joueur_actuel = *l_front;
}

Joueur* Partie::get_joueur_actuel() const //renvoie le joueur actuel
{
  return this->joueur_actuel;
}

Plateau* Partie::get_plateau() const{
  return this->Plat;
}

bool Partie::finDePartie() const{
  for(Joueur* j : this->Plat->get_liste_joueurs()){
    if(this->Plat->get_index_case_joueur(j) == 10){
      return true;
    }
  }
  return false;
}