#include "jeu.h"

void jeu::boucle(){

    while(!fin){

        while (Window.RenderW().pollEvent(event)){
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape)
                    fin=true;
            }
        }

        Window.RenderW().clear(sf::Color::Red);
        Window.RenderW().display();
    }

}

jeu::jeu()
{
    Window.RenderW().setFramerateLimit(60);
    boucle();
}

jeu::~jeu()
{
    //dtor
}
