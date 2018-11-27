#ifndef FENETRE_H
#define FENETRE_H

#include "librairies.h"
class fenetre
{
    public:
        fenetre();
        fenetre(fenetre &fenetreDeTest);
        ~fenetre();

        void Fermer();
        float Getlargeur();
        float Gethauteur();
        void Setlargeur(float largeur);
        void Sethauteur(float hauteur);
        sf::RenderWindow &GetCopieRenderWindow();

    private:

        sf::RenderWindow window;
        float largeur_b;
        float hauteur_b;
};

#endif // FENETRE_H
