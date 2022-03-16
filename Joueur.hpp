#ifndef Joueur_hpp
#define Joueur_hpp

#include <string>
using namespace std;
#include <vector> 

#include "Deck.hpp"

static int current_id_to_give = 0;

class Joueur{

    protected:

        int id_tortue;
        string nom;
        int tuile;
        vector<Carte *> main;
        string status;
        
    public:
        enum couleur int{ rouge, jaune, bleu, vert, violet };

        //constructeur
        Joueur(string name);

        //!@brief Récupère le nom du joueur
        //!@return Retourne le nom du joueur
        string get_nom() const;

        //!@brief Récupère l'id du joueur / tortue
        //!@return Retourne l'id du joueur / tortue
        couleur get_id() const;

        int get_tuile() const;

        //retourne le contenu de la main
        vector<Carte *> get_main() const;

        void ajouter_carte (Deck &deck)const;

        void supprimer_carte (int num_carte)const;

        virtuel void choisir_carte() = 0;

        void init_main (Deck &deck) const;

       // affiche du joueur et de sa main
       std::ostream & do_print(std::ostream & c) const {
            // création du vecteur
            string vs;
            
            // on ajoute le nom
            vs += "Le joueur :"+ this->get_nom();
            vs += " qui a la tortue de couleur :" + this->get_id();
            vs += "\n et la main suivante :";
            for (i=0; i<this->main.size(); i++){
              vs += "\ncarte n°" + to_string(i) +" :\n";
              vs += this->main[i].afficher();
            }
          }
            c <<  vs;
            return c;
        }; 
};

#endif /* Joueur_h */