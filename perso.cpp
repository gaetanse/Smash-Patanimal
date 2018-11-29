#include "perso.h"
#include "librairies.h"
#include <stdlib.h>
#include <time.h>

void perso::tomber(float vitesse){
sf::Vector2f mouvements(0,0);
mouvements.y += vitesse * deltaTime;
sprite.move(mouvements);
}

void perso::colisionMethode(){
if(block_dessous==1){
    if(block_dessous_des==1){
        vitesse_air+=0.5;
    }
    else{
        vitesse_air=speed;
    }
    sf::Time elapsed2 = clock_besoin2.getElapsedTime();
    perso_anim.left = 128;
if(elapsed2.asSeconds()>0.2){
    if (perso_anim.left == 256)
        perso_anim.left = 128;
    else
        perso_anim.left += 64;
sprite.setTextureRect(perso_anim);
clock_besoin2.restart();
}
    tomber(vitesse_air);
}
else{
    perso_anim.left=0;
    peut_sauter=true;
}
}

void perso::afficher(sf::RenderWindow &window){
    window.draw(sprite);
}

sf::Vector2f perso::getPos(){
    return sprite.getPosition();
}

void perso::update(float temps,int dessous,int desx,int dro,int gau){
sf::Vector2f mouvements(0,0);
deltaTime=temps;
block_dessous=dessous;
block_dessous_des=desx;
block_droite=dro;
block_gauche=gau;
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    sf::Time elapsed1 = clock_besoin.getElapsedTime();
if(elapsed1.asSeconds()>0.2){
    if (perso_anim.left == 128)
        perso_anim.left = 0;
    else
        perso_anim.left += 64;
sprite.setTextureRect(perso_anim);
clock_besoin.restart();
}
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
    sprite.setScale(-0.0625*2*2,0.0625*4*2);
    if(block_droite==1)
        mouvements.x -= speed * deltaTime;
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    sprite.setScale(0.0625*2*2,0.0625*4*2);
    if(block_gauche==1)
        mouvements.x += speed * deltaTime;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    if(peut_sauter){
        peut_sauter=false;
        velocity=-15;
        mouvements.y = velocity + deltaTime;
    }
}

if(peut_sauter==false){
    if(velocity<0){
        velocity++;
        mouvements.y = velocity + deltaTime;
    }
    else{
        mouvements.y = 0;
    }
}
sprite.move(mouvements);
}

perso::perso()
{
    perso_anim.left=0;
    perso_anim.width=64;
    perso_anim.height=128;

    srand(time(NULL));
    int x = rand() % 35 + 2;
    int y = rand() % 15 + 2;
    texture.loadFromFile("design/joueur.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x*32,y*32));
    sprite.setScale(sf::Vector2f(0.0625*2*2,0.0625*4*2));
    speed=100;
    sprite.setTextureRect(perso_anim);
}

perso::~perso()
{
    //dtor
}
