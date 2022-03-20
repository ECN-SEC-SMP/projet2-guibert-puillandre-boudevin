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
  }
  string tbcouleur[]={"rouge","jaune","bleu","vert", "violet"};
    cout << "L'Ia a choisit la couleur: " << tbcouleur[couleur] << endl;
 }
 return c;   
}

// l'Ia pour le choix des cartes privilégie son avancer de 2 puis de 1, sinon elle fait reculer un adversaire aléatoire de -2 (carte neutre), sinon elle fait reculer un adversaire alétoire de -1 ou aléatoirement soit elle se fait reculer ou elle fait avancer un joueur de -1, en dernier recourt elle fait avancer un joueur de 2.
// le poid correspondent à la force de la carte
Cartes* Ia::choisir_carte(Deck* deck){

  int carte_choisie;
  
srand (time(NULL));
carte_choisie = rand() %4;

// on transforme la couleur du joueur en couleur de carte
  Cartes::Couleur_carte cj;
  
  switch(this->get_tuile()){
      case Joueur::rouge:
        cj=Cartes::rouge; 
      break;
      case Joueur::jaune:
        cj=Cartes::jaune;
      break;
      case Joueur::bleu:
        cj=Cartes::bleu;
      break;
      case Joueur::vert:
        cj=Cartes::vert;
      break;
      case Joueur::violet:
        cj=Cartes::violet;
      break;
    }
  
// copie
Cartes* c = this->main_joueur[carte_choisie];
//carte aléatoire point = 0
int poid = 0;
cout << "L'Ia a choisit une carte aléatoire" << endl;

for(Cartes* crt : this->main_joueur){
    //carte random parmis avancer adversaire de 1 ou faire reculer notre couleur de -1
    if ((crt->get_nb_cases() != 2) && poid < 1 ){
      c = crt;
      poid = 1;
      cout << " mieux, l'Ia a trouvé une carte entre avancer un adversaire de 1 ou faire reculer sa couleur de -1" << endl;
  }
  //on regarde si carte - pas de notre couleur
  else if ((crt->get_nb_cases() == -1) && (crt->get_couleur() != cj) && poid < 2 ){
      c = crt;
      poid = 2;
    cout << "encore mieux, l'Ia a trouvé une carte -1 pas de sa couleur" << endl;
  }
  //on regarde si carte -- neutre (le choix ne sera pas notre couleur)
  else if (crt->get_nb_cases() == -2 && poid < 3){
      c = crt;
      poid = 3;
    cout << "toujours mieux, l'Ia a trouvé une carte -2 neutre et donc  pas de sa couleur" << endl;
  }
  //on regarde si carte + et de notre couleur
  else if ((crt->get_nb_cases() == 1) && (crt->get_couleur() == cj) && poid < 4 ){
      c = crt;
      poid = 4;
    cout << "beacoup mieux ! l'Ia a trouvé une carte +1 de sa couleur" << endl;
  }
  //on regarde si une carte de la main est ++ et de notre couleur
  else if ((crt->get_nb_cases() == 2)  && (crt->get_couleur() == cj)&& poid < 5){
      c = crt;
      cout << "Incroyable !L'Ia a trouvé une carte la fait qui la fait avancer de 2 cases" << endl;
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