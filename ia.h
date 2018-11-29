#ifndef IA_H
#define IA_H


#include "librairies.h"

class ia
{
    public:
        ia();
        virtual ~ia();
        void deplacement(float temps,float tailleEcran);
        void afficher(sf::RenderWindow &window);
        sf::Sprite getSprite();

    private:
        sf::Sprite sprite;
        sf::Texture texture;
};

#endif // IA_H
