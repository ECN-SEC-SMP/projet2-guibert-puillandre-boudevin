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

        void ajouter_carte (Deck *deck) const;

        void supprimer_carte (int num_carte)const;

        virtual Cartes* choisir_carte() = 0;

        void init_main (Deck *&deck) const;

        protected:

        int id_tortue;
        string nom;
        Couleur_joueur tuile;
        vector<Cartes *> main;

       std::ostream & do_print(std::ostream & c) {
            // création du vecteur
            string vs;
            
            // on ajoute le nom
            vs += "Le joueur :"+ this->get_nom();
            vs += " qui a la tortue de couleur :" + this->get_tuile();
            vs += "\n et la main suivante :";
            for (int i=0; i<this->main.size(); i++){
              vs += "\ncarte n°" + to_string(i) +" :\n";
              vs += this->main[i].afficher();
            }
            c <<  vs;
            return c;
        }; 

};



#endif /* Joueur_h */