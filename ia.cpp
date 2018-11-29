#include "ia.h"
#include <stdlib.h>
#include <time.h>

ia::ia()
{
    srand(time(NULL));
    int x = rand() % 35 + 2;
    int y = rand() % 15 + 2;
    texture.loadFromFile("design/ia.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x*32,y*32));
    sprite.setScale(1,1);
}

void ia::deplacement(float temps,float tailleEcran){
if(sprite.getPosition().x>tailleEcran-128)
    sprite.setPosition(sf::Vector2f(64,128));
sprite.move(100*temps,0);
}

sf::Sprite ia::getSprite(){
return sprite;
}

void ia::afficher(sf::RenderWindow &window){
window.draw(sprite);
}

ia::~ia()
{
    //dtor
}
