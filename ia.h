#ifndef IA_H
#define IA_H


#include "librairies.h"

class ia
{
    public:
        ia(sf::Texture &tex_copie,int difficulte);
        virtual ~ia();
        void deplacement(float temps,float tailleEcran);
        void afficher(sf::RenderWindow &window);
        sf::Sprite getSprite();
        int colisionMethode(float temps,int block_dessous,int dro,int gau,sf::Vector2f joueur,bool saut);
        sf::Vector2f getPos();
        bool getSens();

    private:
        int diff=0;
        sf::Sprite sprite;
        sf::Texture texture;
        bool sens=true;
};

#endif // IA_H
