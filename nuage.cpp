#include "nuage.h"
#include <stdlib.h>
#include <time.h>

nuage::nuage(sf::Texture &texture,int position)
{
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(position,128));
    sprite.setScale(1,1);
}

int nuage::deplacement(float temps,float tailleEcran){

if(sprite.getPosition().x>tailleEcran-128)
    sprite.setPosition(sf::Vector2f(64,128));
sprite.move(100*temps,0);

}

int nuage::test(){
int pourcent = rand() % 100000;
if(pourcent>32750){
    return 1;
}
else
    return 99;
}

sf::Sprite nuage::getSprite(){
return sprite;
}

void nuage::afficher(sf::RenderWindow &window){
window.draw(sprite);
}

nuage::~nuage()
{
    //dtor
}
