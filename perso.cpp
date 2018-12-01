#include "perso.h"
#include "librairies.h"
#include <stdlib.h>
#include <time.h>

void perso::tomber(float vitesse){
sf::Vector2f mouvements(0,0);
mouvements.y += vitesse * deltaTime;
sprite.move(mouvements);
}

int perso::attaque(sf::Vector2f enemie,bool attakoupas){
if(sprite.getPosition().y-enemie.y>0&&sprite.getPosition().y-enemie.y<64){
    if(getSens()){
        if(sprite.getPosition().x-enemie.x>-80&&sprite.getPosition().x-enemie.x<0){
            return 1;
        }
    }
    else{
        if(sprite.getPosition().x-enemie.x>0&&sprite.getPosition().x-enemie.x<80){
            return 1;
        }
    }
}
//std::cout << "/" << enemie.y << "/" << sprite.getPosition().y << "/" << enemie.x-sprite.getPosition().y << "/" << std::endl;
}

void perso::colisionMethode(){
perso_anim.left = 64;
sf::Time elapsed2 = clock_besoin2.getElapsedTime();
if(elapsed2.asSeconds()>0.2){
    if (perso_anim.left > 128)
        perso_anim.left = 64;
    else
        perso_anim.left += 32;
clock_besoin2.restart();
}
if(block_dessous==1){
    peut_sauter=false;
    if(block_dessous_des==1){
        vitesse_air+=0.5;
    }
    else{
        vitesse_air=speed;
    }
    sprite.setTextureRect(perso_anim);
    tomber(vitesse_air);
}
else{
   /* perso_anim.left=0;
    sprite.setTextureRect(perso_anim);*/
    peut_sauter=true;
}
}

void perso::afficher(sf::RenderWindow &window){
    window.draw(sprite);
}

sf::Vector2f perso::getPos(){
    return sprite.getPosition();
}

void perso::sefaisfrappe(bool sensfrappe,int num_pos_g,int num_pos_d){

if(sensfrappe){
   if(num_pos_g==1)
        sprite.move(32,0);
}
else
   if(num_pos_d==1)
        sprite.move(-32,0);
}

bool perso::getSens(){return sens;}

void perso::setTex(){
if(sens)
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
else
    sprite.setTextureRect(sf::IntRect(32, 0, -32, 64));
}

void perso::update(float temps,int dessous,int desx,int dro,int gau){
//std::cout << sprite.getPosition().x << std::endl;
/*perso_anim.left = 0;
sf::Time elapsed1 = clock_besoin.getElapsedTime();
if(elapsed1.asSeconds()>0.2){
    if (perso_anim.left > 64)
        perso_anim.left = 0;
    else
        perso_anim.left += 32;
clock_besoin.restart();
}*/
sf::Vector2f mouvements(0,0);
deltaTime=temps;
block_dessous=dessous;
block_dessous_des=desx;
block_droite=dro;
block_gauche=gau;
if(sf::Joystick::isConnected(0)){
    int x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    //std::cout << "/" << x << std::endl;
    if(x>0){
        sens=true;
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
    if(block_droite==1)
        mouvements.x += speed * deltaTime;
    }
    else if(x==0||x==-1){
        mouvements.x =0;
    }
    else{
        sens=false;
    sprite.setTextureRect(sf::IntRect(32, 0, -32, 64));
    if(block_gauche==1)
        mouvements.x -= speed * deltaTime;
    }
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    sprite.setTextureRect(perso_anim);
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
    sens=false;
    sprite.setTextureRect(sf::IntRect(32, 0, -32, 64));
    if(block_gauche==1)
        mouvements.x -= speed * deltaTime;
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    sens=true;
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
    if(block_droite==1)
        mouvements.x += speed * deltaTime;
}
if((sf::Joystick::isConnected(0)&&sf::Joystick::isButtonPressed(0, 0))||sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
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

bool perso::getSaut(){return peut_sauter;}

void perso::spawn_ale(){
    int x = 0;
    x = rand() % 30 + 5;
    int y = 12;
    sprite.setPosition(sf::Vector2f(x*32,y*32));
}

void perso::reset(){
sprite.setPosition(sf::Vector2f(20*32,12*32));
}

perso::perso()
{
    peut_sauter=false;
    perso_anim.left=0;
    perso_anim.width=32;
    perso_anim.height=64;
    srand(time(NULL));
    texture.loadFromFile("design/joueur.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    spawn_ale();
    sprite.setScale(sf::Vector2f(0.0625*2*2*2,0.0625*4*2*2));
    speed=200;
    sprite.setTextureRect(perso_anim);
}

perso::~perso()
{
    //dtor
}
