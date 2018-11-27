#include "jeu.h"

void jeu::creerTexte(int T_Police,sf::Color couleure,std::string Injec_String,sf::Vector2f posi_Text){
    sf::Text tJeuCreer;
    texts.push_back(tJeuCreer);
    texts.at(texts.size()-1).setPosition(posi_Text);
    texts.at(texts.size()-1).setFont(font);
    texts.at(texts.size()-1).setCharacterSize(T_Police);
    texts.at(texts.size()-1).setColor(couleure);
    texts.at(texts.size()-1).setString(Injec_String);
}

void jeu::affichage(){

Window.RenderW().clear(sf::Color::Red);

for(unsigned int a=0;a<texts.size();a++)
    Window.RenderW().draw(texts.at(a));

Window.RenderW().display();

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

jeu::jeu()
{
    Window.RenderW().setFramerateLimit(60);
    font.loadFromFile("font/base.ttf");
    creerTexte(30,sf::Color::Black,"Entrer pour jouer !",sf::Vector2f(Window.Getlargeur()/2.4,Window.Gethauteur()/50));
    creerTexte(30,sf::Color::Black,"Echap pour quitter !",sf::Vector2f(Window.Getlargeur()/2.4,Window.Gethauteur()/1.05));
    boucle();
}

jeu::~jeu()
{
    //dtor
}
