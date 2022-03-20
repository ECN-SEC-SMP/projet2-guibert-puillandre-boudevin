#include <iostream>
#include <cstdlib>
using namespace std;
#include <string>

#include "Deck.hpp"
#include "Cartes.hpp"
#include "Joueur.hpp"
#include "Ia.hpp"

Ia::Ia(string name):Joueur(name) //constructeur
{
}
Joueur::Couleur_joueur Ia::choisir_couleur(){
    cout << "Une carte neutre a été utilisé. L'Ia va choisir la couleur la plus appropriée. (rouge,bleu,jaune,vert,violet)" << endl;
  int couleur;
  Joueur::Couleur_joueur c;

  // on prend la couleur du joueur
  c = this->get_tuile();

  // random sans la couleur du joueur
  srand (time(NULL));
  while (c == this->get_tuile()){
    int couleur = rand() %4;
    switch (couleur){
      case 0 :
        c = Joueur::rouge;
      break;
      case 1 :
        c = Joueur::jaune;
      break;
      case 2 :
        c = Joueur::bleu;
      break;
      case 3 :
        c = Joueur::vert;
      break;
      case 4 :
        c = Joueur::violet;
      break;
      others :
        cout << "Couleur non reconnue)" << endl;
        c = this->get_tuile();
      break;
  }
 }
 return c;   
}

// l'Ia choix des cartes privilégie son avancer de 2 puis de 1, sinon elle fait reculer un adversaire aléatoire de -2 (carte neutre), sinon elle fait reculer un adversaire alétoire de -1 ou aléatoirement soit elle se fait reculer ou elle fait avancer un joueur de -1, en dernier recourt elle fait avancer un joueur de 2.
// le poid correspondent à la force de la carte
Cartes* Ia::choisir_carte(Deck* deck){
  int carte_choisie;

  
srand (time(NULL));
carte_choisie = rand() %4;

  
// copie
Cartes* c = this->main_joueur[carte_choisie];
//carte aléatoire point = 0
int poid = 0;

for(Cartes* crt : this->main_joueur){
    //carte random parmis avancer adversaire de 1 ou faire reculer notre couleur de -1
    if ((crt->get_nb_cases() != 2) && poid < 1 ){
      c = crt;
      poid = 1;
  }
  //on regarde si carte - pas de notre couleur
  //problème couleur crt =! couleur joueur pas le même enum
  else if ((crt->get_nb_cases() == -1) && (crt->get_couleur() != this->get_tuile()) && poid < 2 ){
      c = crt;
      poid = 2;
  }
  //on regarde si carte -- neutre (le choix ne sera pas notre couleur)
  else if (crt->get_nb_cases() == -2 && poid < 3){
      c = crt;
      poid = 3;
  }
  //on regarde si carte + et de notre couleur
  else if ((crt->get_nb_cases() == 1) && (crt->get_couleur() == this->get_tuile()) && poid < 4 ){
      c = crt;
      poid = 4;
  }
  //on regarde si une carte de la main est ++ et de notre couleur
  else if ((crt->get_nb_cases() == 2)  && (crt->get_couleur() == this->get_tuile())&& poid < 5){
      c = crt;
      // on joue directement la carte, il n'y a pas mieux
      //supprimer
      this->supprimer_carte(c,deck);
      //piocher
      this->ajouter_carte(deck);     
      // return carte pour faire l'effet
      return c;
  }
}
// dernier recourt la carte random du début, elle fait avancer un adv de 2
  
//supprimer
this->supprimer_carte(c,deck);

//piocher
this->ajouter_carte(deck);
      
// return carte pour faire l'effet
return c;
}