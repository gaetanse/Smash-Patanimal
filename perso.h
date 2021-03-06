#ifndef PERSO_H
#define PERSO_H

#include "librairies.h"

class perso
{
    public:
        perso();
        virtual ~perso();
        void colision();
        void update(float temps,int dessous,int desx,int dro,int gau);
        void colisionMethode();
        void tomber(float vitesse);
        void afficher(sf::RenderWindow &window);
        sf::Vector2f getPos();
        void spawn_ale();
        bool getSaut();
        bool getSens();
        void sefaisfrappe(bool sensfrappe,int num_pos_g,int num_pos_d);
        void setTex();
        int attaque(sf::Vector2f enemie,bool attakoupas);
        void reset();

    protected:

    private:

        sf::Sprite sprite;
        sf::Texture texture;

    int block_droite,block_gauche,block_dessous,block_dessous_des;

        float deltaTime;

    sf::Clock clock_besoin;
    sf::Clock clock_besoin2;
        int x,y;

        sf::IntRect perso_anim;

        float speed;
        float vitesse_saut;
        float velocity;
        float vitesse_air;

        bool peut_sauter;

        char sensDeMarche;
        bool sens=true;
};

#endif // PERSO_H
