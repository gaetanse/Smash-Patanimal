#include "ia.h"
#include <stdlib.h>
#include <time.h>

ia::ia(sf::Texture &tex_copie)
{
    srand(time(NULL));
    int x = rand() % 30 + 5;
    int y = 5;
    sprite.setTexture(tex_copie);
    sprite.setPosition(sf::Vector2f(x*32,y*32));
    sprite.setScale(0.0625*2,0.0625*4);
}

bool ia::getSens(){return sens;}

sf::Vector2f ia::getPos(){
    return sprite.getPosition();
}

int ia::colisionMethode(float temps,int block_dessous,int dro,int gau,sf::Vector2f joueur,bool saut){
sf::Vector2f mouvements(0,0);
int vitesse=100;
if(block_dessous==1){
    mouvements.y += vitesse * temps;
}
if(block_dessous!=1&&saut){
if(joueur.x-sprite.getPosition().x<0){
    sens=false;
    if(gau==1)
        mouvements.x -= vitesse * temps;
}
else{
    sens=true;
    if(dro==1)
        mouvements.x += vitesse * temps;
}
}
sprite.move(mouvements);

if(sprite.getPosition().y-joueur.y>-64&&sprite.getPosition().y-joueur.y<64){
    if(getSens()){
        if(sprite.getPosition().x-joueur.x>-80&&sprite.getPosition().x-joueur.x<0){
            return 1;
        }
    }
    else{
        if(sprite.getPosition().x-joueur.x>0&&sprite.getPosition().x-joueur.x<80){
            return 1;
        }
    }
}
std::cout << "/" << joueur.x << "/" << sprite.getPosition().x << "/" << sprite.getPosition().y-joueur.x << "/" << std::endl;
}

void ia::deplacement(float temps,float tailleEcran){

///gauche
///droite

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
