#ifndef NUAGE_H
#define NUAGE_H

#include "librairies.h"

class nuage
{
    public:
        nuage(sf::Texture &texture,int position);
        virtual ~nuage();
        int deplacement(float temps,float tailleEcran);
        int test();
        void afficher(sf::RenderWindow &window);
        sf::Sprite getSprite();

    private:
        sf::Sprite sprite;
};

#endif // NUAGE_H
