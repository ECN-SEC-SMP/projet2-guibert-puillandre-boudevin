#ifndef Joueur_hpp
#define Joueur_hpp

#include <string>
using namespace std;

static int current_id_to_give = 0;

class Joueur{

    protected:

        int id_tortue; 
        string nom;
        string tuile;
        
        
    public:
        enum couleur { rouge, jaune, bleu, vert, violet };

        //constructeur
        Joueur(string name,int id_tortue);

        //!@brief Récupère le nom du joueur
        //!@return Retourne le nom du joueur
        string get_nom() const;

        //!@brief Récupère l'id du joueur / tortue
        //!@return Retourne l'id du joueur / tortue
        int get_id() const;
      
};

#endif /* Joueur_h */