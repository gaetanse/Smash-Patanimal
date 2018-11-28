#include "jeu.h"
#include "librairies.h"

#define TILE_SIZE 32
#define nbDitems 10

unsigned int map_afficher[20][40] = {
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                            {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
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
            if(map_afficher[u][a]!=1){
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

Window.RenderW().clear(sf::Color(255,120,0));

Window.RenderW().setView(jeuCamera);
affichage_map();
Window.RenderW().setView(Window.RenderW().getDefaultView());

for(unsigned int b=0;b<rectangles.size();b++)
    Window.RenderW().draw(rectangles.at(b));

for(unsigned int a=0;a<texts.size();a++)
    Window.RenderW().draw(texts.at(a));

for(unsigned int c=0;c<sprites.size();c++)
    Window.RenderW().draw(sprites.at(c));

Window.RenderW().display();

}

void jeu::souris(){
    if (event.type == sf::Event::MouseMoved&&debutDuJeu){
        float sourispos_x =  event.mouseMove.x;
        float sourispos_y =  event.mouseMove.y;
        sprites.at(0).setPosition(sourispos_x,sourispos_y);
    }
}

void jeu::manette(){

}

void jeu::clavier(){
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Escape)
            fin=true;
        if(event.key.code == sf::Keyboard::Enter){
            debutDuJeu=true;
            rectangles.clear();
            texts.clear();
            ///RANDOM POSITION SPAWN
            creerSprite("design/curseur.png",sf::Vector2f(0,0),sf::Vector2f(0.55,0.55));
            //creerSprite("design/mouse.png",sf::Vector2f(5*32,10,*32),sf::Vector2f(1,1));
            ///Lancer la partie
        }
        if(debutDuJeu){
          //  sf::Image test5 = Window.RenderW().capture();
          //  test5.saveToFile("screenshotGame.png");
        }
    }
}

void jeu::boucle(){
    while(!fin){
        while (Window.RenderW().pollEvent(event)){
            clavier();
            souris();
            ///manette
        }
        affichage();
    }
}

void jeu::creerSprite(std::string endroit,sf::Vector2f pos,sf::Vector2f tai){
    sf::Sprite spriteCreer;
    sprites.push_back(spriteCreer);
    textureDuSprite.loadFromFile(endroit);
    sprites.at(sprites.size()-1).setTexture(textureDuSprite);
    sprites.at(sprites.size()-1).setScale(tai);
    sprites.at(sprites.size()-1).setPosition(pos);
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
    Window.RenderW().setMouseCursorVisible(false);
    font.loadFromFile("font/base.ttf");

       if(!tileSet1Texture.loadFromFile("design/tileset.png"))
        std::cout << "Erreur durant le chargement de l'image du tileset." << std::endl;
    else
        tileSet1.setTexture(tileSet1Texture);

    jeuCamera.reset(sf::FloatRect(0, 0, 1280, 640));
    creerRectangle(sf::Color::Red,sf::Vector2f(0,0),sf::Vector2f(Window.Getlargeur(),64),1,sf::Color::Black);
    creerRectangle(sf::Color::Red,sf::Vector2f(0,Window.Gethauteur()-64),sf::Vector2f(Window.Getlargeur(),64),1,sf::Color::Black);
    creerTexte(30,sf::Color::Black,"Entrer pour jouer !",sf::Vector2f(Window.Getlargeur()/2.35,Window.Gethauteur()/70));
    creerTexte(30,sf::Color::Black,"Echap pour quitter !",sf::Vector2f(Window.Getlargeur()/2.35,Window.Gethauteur()/1.05));
    boucle();
}

jeu::~jeu()
{
    //dtor
}
