#ifndef JEU_H
#define JEU_H

#include "librairies.h"
#include "fenetre.h"
//#include "personnage.h"
#include <iostream>
#include <string>
#include "perso.h"

class jeu
{
    public:
        jeu();
        virtual ~jeu();

        void boucle();
        void creerTexte(int T_Police,sf::Color couleure,std::string Injec_String,sf::Vector2f posi_Text);
        void creerRectangle(sf::Color couleur,sf::Vector2f position,sf::Vector2f taille,float tailleContour,sf::Color couleurContour);
        void creerSprite(std::string endroit,sf::Vector2f pos,sf::Vector2f tai);
        void affichage();
        void clavier();
        void souris();
        void manette();
        void affichage_map();

    private:

    fenetre Window;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::vector<sf::RectangleShape>rectangles;
    std::vector<sf::Sprite>sprites;
    std::vector<sf::Text>texts;
    sf::Texture textureDuSprite;
    sf::View jeuCamera;
    sf::Sprite tileSet1;
    sf::Texture tileSet1Texture;
    sf::Font font;
    sf::Event event;
    sf::Music music;
    bool fin=false;
    bool debutDuJeu=false;
    float TempsTotal;
    float f_miseajour;
    float deltaTime;
    sf::Clock cloack2;
    perso joueur;

};

#endif // JEU_H
