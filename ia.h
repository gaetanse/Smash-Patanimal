#ifndef IA_H
#define IA_H


#include "librairies.h"

class ia
{
    public:
        ia(sf::Texture &tex_copie);
        virtual ~ia();
        void deplacement(float temps,float tailleEcran);
        void afficher(sf::RenderWindow &window);
        sf::Sprite getSprite();
        int colisionMethode(float temps,int block_dessous,int dro,int gau,sf::Vector2f joueur);
        sf::Vector2f getPos();

    private:
        sf::Sprite sprite;
        sf::Texture texture;
};

#endif // IA_H
