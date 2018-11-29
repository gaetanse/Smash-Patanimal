#include "jeu.h"
#include "librairies.h"

#define TILE_SIZE 32
#define nbDitems 10

unsigned int map_afficher[20][40] = {
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,0},
                            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,1,6,1,1,1,1,1,1,0},
                            {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                            {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
                            };

void jeu::creerTexte(int T_Police,sf::Color couleure,std::string Injec_String,sf::Vector2f posi_Text){
    sf::Text tJeuCreer;
    texts.push_back(tJeuCreer);
    texts.at(texts.size()-1).setPosition(posi_Text);
    texts.at(texts.size()-1).setFont(font);
    texts.at(texts.size()-1).setCharacterSize(T_Police);
    texts.at(texts.size()-1).setColor(couleure);
    texts.at(texts.size()-1).setString(Injec_String);
}

void jeu::affichage_map(){
  for(int u=0;u<20;u++){
        for(int a=0;a<40;a++){
            if(map_afficher[u][a]!=1){
               int x = ((map_afficher[u][a])%nbDitems)*TILE_SIZE;
               int y = (map_afficher[u][a]/nbDitems)*TILE_SIZE;
                tileSet1.setPosition(sf::Vector2f(a*TILE_SIZE, u*TILE_SIZE)); ///position
                tileSet1.setTextureRect(sf::IntRect(x, y, TILE_SIZE, TILE_SIZE)); ///position dans le spriteset et taille
                Window.RenderW().draw(tileSet1);
            }
        }
    }
}

void jeu::affichage(){

Window.RenderW().clear(sf::Color(255,120,0,255));

Window.RenderW().setView(jeuCamera);
affichage_map();

if(debutDuJeu){
    joueur.afficher(Window.RenderW());
}

for(int x=0;x<liste_soin.size();x++)
    Window.RenderW().draw(liste_soin.at(x).getSprite());

Window.RenderW().setView(Window.RenderW().getDefaultView());

for(unsigned int b=0;b<rectangles.size();b++)
    Window.RenderW().draw(rectangles.at(b));

for(unsigned int a=0;a<texts.size();a++)
    Window.RenderW().draw(texts.at(a));

for(unsigned int c=0;c<sprites.size();c++)
    if(c!=1)
        Window.RenderW().draw(sprites.at(c));
    else
    for(unsigned int d=0;d<vie;d++){
        sprites.at(1).setPosition(128+64*d,6+16);
        Window.RenderW().draw(sprites.at(1));
    }

for(int y=0;y<liste_nuages.size();y++)
    Window.RenderW().draw(liste_nuages.at(y).getSprite());

Window.RenderW().display();

}

void jeu::souris(){
    if (event.type == sf::Event::MouseMoved&&debutDuJeu){
        float sourispos_x =  event.mouseMove.x;
        float sourispos_y =  event.mouseMove.y;
        sprites.at(0).setPosition(sourispos_x,sourispos_y);
    }
}

void jeu::manette(){

}

void jeu::clavier(){
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Escape)
            fin=true;
        if(event.key.code == sf::Keyboard::O)
            vie-=1;
        if((event.key.code == sf::Keyboard::Q||event.key.code == sf::Keyboard::D)&&debutDuJeu){
            soundPas.play();
            soundPas.setLoop(true);
        }
        if(event.key.code == sf::Keyboard::Enter&&debutDuJeu==false){
            debutDuJeu=true;
            rectangles.clear();
            texts.clear();
            vie = 10;
            creerSprite("design/curseur.png",sf::Vector2f(0,0),sf::Vector2f(0.50,0.50));
            creerSprite("design/vie.png",sf::Vector2f(65+16,6+16),sf::Vector2f(1,1));
            for(int a=0;a<10;a++){
                nuage nume1(texture_nuage,(a*64)+128+(a*110));
                liste_nuages.push_back(nume1);
            }
            creerRectangle(sf::Color::Transparent,sf::Vector2f(64,5),sf::Vector2f(Window.Getlargeur()-128,64),3,sf::Color::Black);
            creerTexte(20,sf::Color::Black,"Enemies restants : 10",sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/50));
            creerTexte(20,sf::Color::Black,"Partie numéro : 0",sf::Vector2f(Window.Getlargeur()/1.5,Window.Gethauteur()/50));
            creerTexte(20,sf::Color::Black,"Enemies tués : 0",sf::Vector2f(Window.Getlargeur()/1.2,Window.Gethauteur()/50));
            buffer.loadFromFile("audio/choc.ogg");
            sound.setBuffer(buffer);
            sound.play();
        }
    }
    else{
            soundPas.setLoop(false);
            soundPas.pause();
    }
}

void jeu::boucle(){
    while(!fin){
    deltaTime = cloack2.restart().asSeconds();
        while (Window.RenderW().pollEvent(event)){
            clavier();
            souris();
            ///manette
        }
        if(debutDuJeu){
            for(int y=0;y<liste_nuages.size();y++){
                liste_nuages.at(y).deplacement(deltaTime,Window.Getlargeur());
                if(liste_nuages.at(y).test()==1){
                    soin soin_objet(texture_soin,liste_nuages.at(y).getSprite().getPosition());
                    liste_soin.push_back(soin_objet);
                }
            }
            for(int g=0;g<liste_soin.size();g++){
                liste_soin.at(g).deplacement(deltaTime,Window.Gethauteur());
                if(liste_soin.at(g).marchedessus(joueur.getPos())==1){
                    liste_soin.erase(liste_soin.begin()+g);
                    if(vie<10)
                        vie++;
                }
            }
            int pos_x = joueur.getPos().x/32+1;
            int pos_y = joueur.getPos().y/32+2;
            joueur.colisionMethode();
            joueur.update(deltaTime,
                          map_afficher[pos_y][pos_x],
                          map_afficher[pos_y+1][pos_x],
                          map_afficher[pos_y-1][pos_x],
                          map_afficher[pos_y-1][pos_x-1]);
        }
        affichage();
        //sf::Image test = Window.RenderW().capture();
        //test.saveToFile("screenshotGame.png");
    }
}

void jeu::creerSprite(std::string endroit,sf::Vector2f pos,sf::Vector2f tai){
    textureDuSprite.loadFromFile(endroit);
    sf::Sprite spriteCreer;
    spriteCreer.setTexture(textureDuSprite);
    textureDuSprite.setSmooth(true);
    spriteCreer.setScale(tai);
    spriteCreer.setPosition(pos);
    sprites.push_back(spriteCreer);
    // sprites.at(sprites.size()-1).setTexture(textureDuSprite);
    //sprites.at(sprites.size()-1).setScale(tai);
    //sprites.at(sprites.size()-1).setPosition(pos);
}

void jeu::creerRectangle(sf::Color couleur,sf::Vector2f position,sf::Vector2f taille,float tailleContour,sf::Color couleurContour){
        sf::RectangleShape rect;
        rectangles.push_back(rect);
        rectangles.at(rectangles.size()-1).setPosition(position);
        rectangles.at(rectangles.size()-1).setSize(taille);
        rectangles.at(rectangles.size()-1).setFillColor(couleur);
        rectangles.at(rectangles.size()-1).setOutlineThickness(tailleContour);
        if(tailleContour!=0)
            rectangles.at(rectangles.size()-1).setOutlineColor(couleurContour);
}

jeu::jeu()
{
    music.openFromFile("audio/jeu.ogg");
    music.setVolume(5);
    music.play();
    Window.RenderW().setFramerateLimit(60);
    Window.RenderW().setMouseCursorVisible(false);
    font.loadFromFile("font/base.ttf");

       if(!tileSet1Texture.loadFromFile("design/tileset.png"))
        std::cout << "Erreur durant le chargement de l'image du tileset." << std::endl;
    else
        tileSet1.setTexture(tileSet1Texture);

    texture_soin.loadFromFile("design/soin.png");
    texture_soin.setSmooth(true);
    texture_nuage.loadFromFile("design/nuage.png");
    texture_nuage.setSmooth(true);
    bufferpas.loadFromFile("audio/objet_tombe.wav");
    soundPas.setBuffer(bufferpas);
    jeuCamera.reset(sf::FloatRect(0, 0, 1280, 640));
    creerRectangle(sf::Color::Red,sf::Vector2f(0,0),sf::Vector2f(Window.Getlargeur(),64),1,sf::Color::Black);
    creerRectangle(sf::Color::Red,sf::Vector2f(0,Window.Gethauteur()-64),sf::Vector2f(Window.Getlargeur(),64),1,sf::Color::Black);
    creerTexte(30,sf::Color::Black,"Entrer pour jouer !",sf::Vector2f(Window.Getlargeur()/2.35,Window.Gethauteur()/70));
    creerTexte(30,sf::Color::Black,"Echap pour quitter !",sf::Vector2f(Window.Getlargeur()/2.35,Window.Gethauteur()/1.05));
    boucle();
}

jeu::~jeu()
{
    //dtor
}
