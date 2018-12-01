#include "fenetre.h"
#include "librairies.h"

fenetre::fenetre()
{

//std::cout << "C:fenetre/";
sf::VideoMode bureau;
largeur_b = bureau.getDesktopMode().width;
hauteur_b = bureau.getDesktopMode().height;
window.create(sf::VideoMode(largeur_b,hauteur_b),"Projet",sf::Style::Fullscreen);

}

float fenetre::Getlargeur(){return largeur_b;}
float fenetre::Gethauteur(){return hauteur_b;}

sf::RenderWindow &fenetre::RenderW(){
    return window;
}

void fenetre::Fermer(){
   window.close();
}

fenetre::~fenetre()
{
    Fermer();
    //std::cout << "D:fenetre/";
}
