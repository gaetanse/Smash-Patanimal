#include "soin.h"

soin::soin(sf::Texture &texture,sf::Vector2f position)
{
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(position.x-64,position.y-64));
    sprite.setScale(0.9,0.9);
}

int soin::marchedessus(sf::Vector2f personnage){
if(sprite.getPosition().x-personnage.x>-16&&sprite.getPosition().x-personnage.x<16){
    if(sprite.getPosition().y-personnage.y>0&&sprite.getPosition().y-personnage.y<128){
        return 1;
    }
}
//std::cout << "/" << personnage.y << "/" << sprite.getPosition().y << "/" << personnage.x-sprite.getPosition().y << "/" << std::endl;
}

sf::Vector2f soin::getPos(){
    return sprite.getPosition();
}

void soin::colisionMethode(float temps,int block_dessous){
sf::Vector2f mouvements(0,0);
int vitesse=100;
if(block_dessous==1||block_dessous==5){
    mouvements.y += vitesse * temps;
}
sprite.move(mouvements);
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
