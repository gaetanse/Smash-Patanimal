#include "jeu.h"
#include "librairies.h"

#define TILE_SIZE 32
#define nbDitems 10

unsigned int map_afficher[20][40] = {
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                            };

void jeu::creerTexte(int T_Police,sf::Color couleure,std::string Injec_String,sf::Vector2f posi_Text){
    sf::Text tJeuCreer;
    texts.push_back(tJeuCreer);
    texts.at(texts.size()-1).setPosition(posi_Text);
    texts.at(texts.size()-1).setFont(font);
    texts.at(texts.size()-1).setCharacterSize(T_Police);
    texts.at(texts.size()-1).setColor(couleure);
    texts.at(texts.size()-1).setString(Injec_String);
}

void jeu::affichage_map(){
  for(int u=0;u<20;u++){
        for(int a=0;a<40;a++){
            if(map_afficher[u][a]!=5){
               int x = ((map_afficher[u][a])%nbDitems)*TILE_SIZE;
               int y = (map_afficher[u][a]/nbDitems)*TILE_SIZE;
                tileSet1.setPosition(sf::Vector2f(a*TILE_SIZE, u*TILE_SIZE)); ///position
                tileSet1.setTextureRect(sf::IntRect(x, y, TILE_SIZE, TILE_SIZE)); ///position dans le spriteset et taille
                Window.RenderW().draw(tileSet1);
            }
        }
    }
}

void jeu::affichage(){

Window.RenderW().clear(sf::Color::Red);

Window.RenderW().setView(jeuCamera);
affichage_map();
Window.RenderW().setView(Window.RenderW().getDefaultView());

for(unsigned int a=0;a<texts.size();a++)
    Window.RenderW().draw(texts.at(a));

Window.RenderW().display();

}

void jeu::souris(){

}

void jeu::manette(){

}

void jeu::clavier(){
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Escape)
            fin=true;
    }
}

void jeu::boucle(){
    while(!fin){
        while (Window.RenderW().pollEvent(event)){
            clavier();
            ///souris
            ///manette
        }
        affichage();
    }
}

void jeu::creerRectangle(sf::Color couleur,sf::Vector2f position,sf::Vector2f taille,float tailleContour,sf::Color couleurContour){
        sf::RectangleShape rect;
        rectangles.push_back(rect);
        rectangles.at(rectangles.size()-1).setPosition(position);
        rectangles.at(rectangles.size()-1).setSize(taille);
        rectangles.at(rectangles.size()-1).setFillColor(couleur);
        rectangles.at(rectangles.size()-1).setOutlineThickness(tailleContour);
        if(tailleContour!=0)
            rectangles.at(rectangles.size()-1).setOutlineColor(couleurContour);
}

jeu::jeu()
{
    Window.RenderW().setFramerateLimit(60);
    font.loadFromFile("font/base.ttf");

       if(!tileSet1Texture.loadFromFile("design/tileset.png"))
        std::cout << "Erreur durant le chargement de l'image du tileset." << std::endl;
    else
        tileSet1.setTexture(tileSet1Texture);

    jeuCamera.reset(sf::FloatRect(0, 0, 1280, 640));
//    creerRectangle(sf::)
    creerTexte(30,sf::Color::Black,"Entrer pour jouer !",sf::Vector2f(Window.Getlargeur()/2.4,Window.Gethauteur()/50));
    creerTexte(30,sf::Color::Black,"Echap pour quitter !",sf::Vector2f(Window.Getlargeur()/2.4,Window.Gethauteur()/1.05));
    boucle();
}

jeu::~jeu()
{
    //dtor
}
