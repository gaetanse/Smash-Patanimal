#include "fenetre.h"
#include "librairies.h"

fenetre::fenetre()
{

std::cout << "C:fenetre/";
sf::VideoMode bureau;
largeur_b = bureau.getDesktopMode().width;
hauteur_b = bureau.getDesktopMode().height;
window.create(sf::VideoMode(largeur_b,hauteur_b),"Projet Jeu2D - Menu",sf::Style::Fullscreen);

}

fenetre::fenetre(fenetre &fenetreDeTest)
{

GetCopieRenderWindow().setPosition(sf::Vector2i(0,0));
GetCopieRenderWindow().setTitle("Jeu");
GetCopieRenderWindow().setSize(sf::Vector2u(fenetreDeTest.Getlargeur(),fenetreDeTest.Gethauteur()));
Setlargeur(fenetreDeTest.Getlargeur());
Sethauteur(fenetreDeTest.Gethauteur());

std::cout << "fenetre clone créer" << std::endl;

}

void fenetre::Setlargeur(float largeurbb){
    largeur_b=largeurbb;
}

void fenetre::Sethauteur(float hauteurbb){
    hauteur_b=hauteurbb;
}

float fenetre::Getlargeur(){
    return largeur_b;
}

float fenetre::Gethauteur(){
    return hauteur_b;
}

sf::RenderWindow &fenetre::GetCopieRenderWindow(){
    return window;
}

void fenetre::Fermer(){
   window.close();
  /// delete this;
}

fenetre::~fenetre()
{
    std::cout << "D:fenetre/";
  ///  exit(0);
}
