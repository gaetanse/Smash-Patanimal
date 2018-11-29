#include "soin.h"

soin::soin(sf::Texture &texture,sf::Vector2f position)
{
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(position.x-64,position.y-64));
    sprite.setScale(1,1);
}

int soin::marchedessus(sf::Vector2f personnage){
#define portee 32
if(sprite.getPosition().y-personnage.y>0&&sprite.getPosition().y-personnage.y<16){
    if(sprite.getPosition().x-personnage.x>0&&sprite.getPosition().x-personnage.x<16){
        return 1;
    }
}
}

int soin::deplacement(float temps,float tailleEcran){
if(sprite.getPosition().y<tailleEcran-24-512)
    sprite.move(0,100*temps);
}

sf::Sprite soin::getSprite(){
return sprite;
}

void soin::afficher(sf::RenderWindow &window){
window.draw(sprite);
}

soin::~soin()
{
    //dtor
}
