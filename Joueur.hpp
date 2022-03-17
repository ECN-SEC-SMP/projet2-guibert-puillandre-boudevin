#ifndef Joueur_hpp
#define Joueur_hpp

#include <string>
using namespace std;
#include <vector> 

#include "Cartes.hpp"
#include "Deck.hpp"

static int current_id_to_give = 0;

class Joueur{

    protected:

        int id_tortue; 
        string nom;
        int tuile;
        vector<Cartes *> main;
        
        
    public:
        enum couleur { rouge, jaune, bleu, vert, violet };

        //constructeur
        Joueur(string name);

        //!@brief Récupère le nom du joueur
        //!@return Retourne le nom du joueur
        string get_nom() const;

        //!@brief Récupère l'id du joueur / tortue
        //!@return Retourne l'id du joueur / tortue
        int get_id() const;

        int get_id() const;

        int get_tuile() const;

        //retourne le contenu de la main
        vector<Cartes *> get_main() const;

        void afficher_main() const;

        void ajouter_carte (Deck* deck);

        void supprimer_carte (int num_carte)const;

        virtual Cartes* choisir_carte() = 0;

        void init_main (Deck &deck) const;
};

#endif /* Joueur_h */