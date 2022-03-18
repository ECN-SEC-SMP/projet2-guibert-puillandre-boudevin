#ifndef Joueur_hpp
#define Joueur_hpp

#include <string>
using namespace std;
#include <vector> 

#include "Cartes.hpp"
#include "Deck.hpp"

static int current_id_to_give = 0;
static int couleur [4];


class Joueur{

    public:

      enum Couleur_joueur{ rouge, jaune, bleu, vert, violet };

      //constructeur
      Joueur(string name, Deck* deck);

      //!@brief Récupère le nom du joueur
      //!@return Retourne le nom du joueur
      string get_nom() const;

      //!@brief Récupère l'id du joueur / tortue
      //!@return Retourne l'id du joueur / tortue
      int get_id() const;

      Couleur_joueur get_tuile() const;

      //retourne le contenu de la main
      vector<Cartes *> get_main() const;

      void afficher_main() const;

      void ajouter_carte (Deck *deck) ;

      void supprimer_carte (Cartes* carte, Deck *deck);

      virtual Cartes* choisir_carte(Deck* deck) = 0;

      Couleur_joueur get_choix() const;
  
      void set_choix (string couleur);
  
      void init_main (Deck *deck);

      

      protected:

        int id_tortue;
        string nom;
        Couleur_joueur tuile;
        vector<Cartes *> main_joueur;
        Couleur_joueur choix_couleur;
        

      friend ostream& operator<<(ostream& os,Joueur* const& v);

};


ostream& operator<<(ostream& os,Joueur* const& j){
    os << "Le joueur :" <<  j->get_nom();
    os <<  " qui a la tortue de couleur :" +  j->get_tuile();
    os << "\n et la main suivante :";
    for (int i=0; i< j->main_joueur.size(); i++){
      os << "\ncarte n°" + to_string(i) +" :\n";
      os <<  j->main_joueur[i];
    }
    return os;
}

#endif /* Joueur_h */