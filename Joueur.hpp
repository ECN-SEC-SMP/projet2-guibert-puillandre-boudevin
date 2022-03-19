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
      Joueur(string name);

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

      virtual Joueur::Couleur_joueur choisir_couleur() = 0;

      Couleur_joueur get_choix() const;

      friend ostream& operator<<(ostream& os,Joueur const& v);

      protected:

        int id_tortue;
        string nom;
        Couleur_joueur tuile;
        vector<Cartes *> main_joueur;
        Couleur_joueur choix_couleur;
        
};

#endif /* Joueur_h */