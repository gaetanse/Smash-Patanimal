#ifndef SOIN_H
#define SOIN_H

#include "librairies.h"

class soin
{
    public:
        soin(sf::Texture &texture,sf::Vector2f position);
        virtual ~soin();
        //int deplacement(float temps,float tailleEcran);
        void afficher(sf::RenderWindow &window);
        sf::Sprite getSprite();
        int marchedessus(sf::Vector2f personnage);
        void colisionMethode(float temps,int block_dessous);
        sf::Vector2f getPos();

    private:
        sf::Sprite sprite;
    private:
};

#endif // SOIN_H
