#ifndef JEU_H
#define JEU_H

#include "librairies.h"
#include "fenetre.h"
#include <iostream>
#include <string>

class jeu
{
    public:
        jeu();
        virtual ~jeu();

        void boucle();
        void creerTexte(int T_Police,sf::Color couleure,std::string Injec_String,sf::Vector2f posi_Text);
        void creerRectangle(sf::Color couleur,sf::Vector2f position,sf::Vector2f taille,float tailleContour,sf::Color couleurContour);
        void affichage();
        void clavier();
        void souris();
        void manette();
        void affichage_map();

    private:

    std::vector<sf::RectangleShape> rectangles;
    sf::View jeuCamera;

    sf::Texture tileSet1Texture;
    sf::Sprite tileSet1;

    sf::Font font;
    std::vector<sf::Text>texts;
    fenetre Window;
    sf::Event event;
    bool fin=false;

};

#endif // JEU_H
