#ifndef FENETRE_H
#define FENETRE_H

#include "librairies.h"

class fenetre
{
    public:
        fenetre();
        ~fenetre();

        void Fermer();
        sf::RenderWindow &RenderW();
        float Getlargeur();
        float Gethauteur();

    private:

        sf::RenderWindow window;
        float largeur_b;
        float hauteur_b;
};

#endif // FENETRE_H
