#include "jeu.h"
#include "librairies.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

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
                            {0,1,5,5,5,5,5,5,1,5,5,5,5,5,1,5,5,5,1,1,1,5,5,5,1,5,5,5,5,5,1,5,5,5,5,5,5,5,1,0},
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

if(debutDuJeu==false)
    Window.RenderW().clear(sf::Color(255,120,0,255));
else
    Window.RenderW().clear(sf::Color(255,0,0,255));

Window.RenderW().setView(jeuCamera);
affichage_map();

if(debutDuJeu&&demmarage==false&&perdu==false){
    joueur.afficher(Window.RenderW());
}

if(demmarage==false&&perdu==false){
for(int x=0;x<liste_soin.size();x++)
    Window.RenderW().draw(liste_soin.at(x).getSprite());
for(int t=0;t<liste_ia.size();t++)
    Window.RenderW().draw(liste_ia.at(t).getSprite());

if(click)
    Window.RenderW().draw(sprites.at(1));

}

Window.RenderW().setView(Window.RenderW().getDefaultView());

for(unsigned int b=0;b<rectangles.size();b++)
    Window.RenderW().draw(rectangles.at(b));

for(unsigned int a=0;a<texts.size();a++)
    Window.RenderW().draw(texts.at(a));

if(vie>0&&demmarage==false){
for(unsigned int c=0;c<sprites.size();c++)
    if(c!=2&&c!=1)
        Window.RenderW().draw(sprites.at(c));
    else
    for(unsigned int d=0;d<vie;d++){
        sprites.at(2).setPosition(128+64*d,6+16);
        Window.RenderW().draw(sprites.at(2));
    }
}

if(demmarage==false&&perdu==false){
for(int y=0;y<liste_nuages.size();y++)
    Window.RenderW().draw(liste_nuages.at(y).getSprite());
}

Window.RenderW().display();

}

void jeu::souris(){
    if(debutDuJeu){
    if (event.type == sf::Event::MouseMoved){
        float sourispos_x =  event.mouseMove.x;
        float sourispos_y =  event.mouseMove.y;
        sprites.at(0).setPosition(sourispos_x,sourispos_y);
    }
    }
}

void jeu::manette(){

}

void jeu::clavier(){
    if(sf::Joystick::isConnected(0)&&sf::Joystick::isButtonPressed(0, 7)&&debutDuJeu==false){
        debutDuJeu=true;
            rectangles.clear();
            texts.clear();
            vie = 5;
            texture_curseur.loadFromFile("design/curseur.png");
            texture_curseur.setSmooth(true);
            creerSprite(texture_curseur,"design/curseur.png",sf::Vector2f(0,0),sf::Vector2f(0.50,0.50));
            creerSprite(texture_epee,"",sf::Vector2f(0,0),sf::Vector2f(0.5,1.5));
            sprites.at(1).setOrigin(8,32);
            textureDuSprite.loadFromFile("design/vie.png");
            creerSprite(textureDuSprite,"design/vie.png",sf::Vector2f(65+16,6+16),sf::Vector2f(1,1));
            numero_partie=0;enemies=0;enemies_kill=0;
            creerRectangle(sf::Color::Transparent,sf::Vector2f(64,5),sf::Vector2f(Window.Getlargeur()-128,64),3,sf::Color::Black);
            creerTexte(20,sf::Color::Black,"Enemies restants : "+std::to_string(enemies),sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/50));
            creerTexte(20,sf::Color::Black,"Partie numéro : "+std::to_string(numero_partie),sf::Vector2f(Window.Getlargeur()/1.5,Window.Gethauteur()/50));
            creerTexte(20,sf::Color::Black,"Enemies tués : "+std::to_string(enemies_kill),sf::Vector2f(Window.Getlargeur()/1.2,Window.Gethauteur()/50));
            //creerRectangle(sf::Color::Transparent,sf::Vector2f(Window.Getlargeur()/2.3,Window.Gethauteur()/2),sf::Vector2f(280,128),3,sf::Color::Black);
            //creerTexte(20,sf::Color::Black,"Partie numéro :  : 1",sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/1.85));
            cloackDem.restart();
    }
    if(sf::Joystick::isConnected(0)&&sf::Joystick::isButtonPressed(0, 6)){
        fin=true;
    }

    if(sf::Joystick::isConnected(0)&&debutDuJeu==false){
    int x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    if(x>0){
            num_choix+=1;
    }
    else if(x==0||x==-1){

    }
    else{
        num_choix-=1;
    }

            if(num_choix>2)
                num_choix=0;
            if(num_choix<0)
                num_choix=2;

            if(num_choix==0)
                texts.at(1).setString("(Ia : Facile) | Ia : Moyen | Ia : Dur");
            else if(num_choix==1)
                texts.at(1).setString("Ia : Facile | (Ia : Moyen) | Ia : Dur");
            else if(num_choix==2)
                texts.at(1).setString("Ia : Facile | Ia : Moyen | (Ia : Dur)");
}

    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Escape)
            fin=true;
        if(event.key.code == sf::Keyboard::E){
            sf::Image test = Window.RenderW().capture();
            test.saveToFile("screenshotGame.png");
        }

        if((event.key.code == sf::Keyboard::Q||event.key.code == sf::Keyboard::D)&&debutDuJeu){
            soundPas.play();
            soundPas.setLoop(true);
        }

        if(event.key.code == sf::Keyboard::Q&&debutDuJeu==false){
            num_choix-=1;
            if(num_choix>2)
                num_choix=0;
            if(num_choix<0)
                num_choix=2;

            if(num_choix==0)
                texts.at(1).setString("(Ia : Facile) | Ia : Moyen | Ia : Dur");
            else if(num_choix==1)
                texts.at(1).setString("Ia : Facile | (Ia : Moyen) | Ia : Dur");
            else if(num_choix==2)
                texts.at(1).setString("Ia : Facile | Ia : Moyen | (Ia : Dur)");
        }
        if(event.key.code == sf::Keyboard::D&&debutDuJeu==false){
            num_choix+=1;
            if(num_choix>2)
                num_choix=0;
            if(num_choix<0)
                num_choix=2;

            if(num_choix==0)
                texts.at(1).setString("(Ia : Facile) | Ia : Moyen | Ia : Dur");
            else if(num_choix==1)
                texts.at(1).setString("Ia : Facile | (Ia : Moyen) | Ia : Dur");
            else if(num_choix==2)
                texts.at(1).setString("Ia : Facile | Ia : Moyen | (Ia : Dur)");
        }
        if(event.key.code == sf::Keyboard::Enter&&debutDuJeu==false){
            debutDuJeu=true;
            rectangles.clear();
            texts.clear();
            vie = 5;
            texture_curseur.loadFromFile("design/curseur.png");
            texture_curseur.setSmooth(true);
            creerSprite(texture_curseur,"design/curseur.png",sf::Vector2f(0,0),sf::Vector2f(0.50,0.50));
            creerSprite(texture_epee,"",sf::Vector2f(0,0),sf::Vector2f(0.5,1.5));
            sprites.at(1).setOrigin(8,32);
            textureDuSprite.loadFromFile("design/vie.png");
            creerSprite(textureDuSprite,"design/vie.png",sf::Vector2f(65+16,6+16),sf::Vector2f(1,1));
            numero_partie=0;enemies=0;enemies_kill=0;
            creerRectangle(sf::Color::Transparent,sf::Vector2f(64,5),sf::Vector2f(Window.Getlargeur()-128,64),3,sf::Color::Black);
            creerTexte(20,sf::Color::Black,"Enemies restants : "+std::to_string(enemies),sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/50));
            creerTexte(20,sf::Color::Black,"Partie numéro : "+std::to_string(numero_partie),sf::Vector2f(Window.Getlargeur()/1.5,Window.Gethauteur()/50));
            creerTexte(20,sf::Color::Black,"Enemies tués : "+std::to_string(enemies_kill),sf::Vector2f(Window.Getlargeur()/1.2,Window.Gethauteur()/50));
            //creerRectangle(sf::Color::Transparent,sf::Vector2f(Window.Getlargeur()/2.3,Window.Gethauteur()/2),sf::Vector2f(280,128),3,sf::Color::Black);
            //creerTexte(20,sf::Color::Black,"Partie numéro :  : 1",sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/1.85));
            cloackDem.restart();
        }
    }
    else{
            soundPas.setLoop(false);
            soundPas.pause();
    }
}

void jeu::demarageF(){
            for(int a=0;a<10;a++){
                nuage nume1(texture_nuage,(a*64)+128+(a*110));
                liste_nuages.push_back(nume1);
            }
       //     texts.erase(texts.end()+0);
       //     rectangles.erase(rectangles.end()+0);
            joueur.spawn_ale();
            enemies=5+enemies_kill;
            texts.at(0).setString("Enemies restants : "+std::to_string(enemies));
            numero_partie+=1;
            texts.at(1).setString("Partie numéro : "+std::to_string(numero_partie));
            demmarage=false;
            ene_creer=false;
}

void jeu::restart(){
liste_nuages.clear();
liste_soin.clear();
liste_ia.clear();
enemies=0;
texts.at(0).setString("Enemies restants : "+std::to_string(enemies));
numero_partie=0;
texts.at(1).setString("Partie numéro : "+std::to_string(numero_partie));
enemies_kill=0;
texts.at(2).setString("Enemies tués : 0");
cloackDem.restart();
demmarage=true;
perdu=false;
//creerRectangle(sf::Color::Transparent,sf::Vector2f(Window.Getlargeur()/2.3,Window.Gethauteur()/2),sf::Vector2f(280,128),3,sf::Color::Black);
//creerTexte(20,sf::Color::Black,"Partie numéro :  : 1",sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/1.85));
}

void jeu::continu(){
liste_nuages.clear();
liste_soin.clear();
liste_ia.clear();
cloackDem.restart();
demmarage=true;
perdu=false;
//creerRectangle(sf::Color::Transparent,sf::Vector2f(Window.Getlargeur()/2.3,Window.Gethauteur()/2),sf::Vector2f(280,128),3,sf::Color::Black);
//creerTexte(20,sf::Color::Black,"Partie numéro : "+std::to_string(numero_partie),sf::Vector2f(Window.Getlargeur()/2.2,Window.Gethauteur()/1.85));
demarageF();
}

void jeu::boucle(){
    while(!fin){
    sf::Joystick::update();
    deltaTime = cloack2.restart().asSeconds();
    deltaTimeSpa = cloackSpa.getElapsedTime().asSeconds();
    deltaTimeVul= cloackVul.getElapsedTime().asSeconds();
        while (Window.RenderW().pollEvent(event)){
            clavier();
            souris();
            ///manette
        }
        if(debutDuJeu){

                if(demmarage){
        deltaTimeDem = cloackDem.getElapsedTime().asSeconds();
        if(deltaTimeDem>2){
            demarageF();
        }
    }
    if(ene_creer==false&&demmarage==false){
            if(liste_ia.size()!=enemies){
                int obtn=0;
                if(num_choix==0)
                    obtn=3.1;
                else if(num_choix==1)
                    obtn=2.1;
                else if(num_choix==2)
                    obtn=1.1;
                if(deltaTimeSpa>obtn){
                   /* int nb = rand() % 2;
                    std::cout << nb;
                    if(nb==0)
                        texture_ia.loadFromFile("design/patagiraf.png");
                    else if(nb==1)
                        texture_ia.loadFromFile("design/corbeau.png");*/
                    ia ia_creer(texture_ia,num_choix);
                    liste_ia.push_back(ia_creer);
                    cloackSpa.restart();
                }
            }
            else{
                ene_creer=true;
            }
    }
    if(enemies<1){
        continu();
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)==false&&sf::Joystick::isButtonPressed(0, 2)==false)
        click=false;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            click=true;
                    sprites.at(1).rotate(20);
                }
                /*else{
                    sprites.at(1).setRotation(0);
                }*/

           if(sf::Joystick::isConnected(0)){
                if(sf::Joystick::isButtonPressed(0, 2)){
                    click=true;
                    sprites.at(1).rotate(20);
                }

               // else
                    //sprites.at(1).setRotation(0);
            }

                    if(vie<1){
                        vie=5;
                        perdu=true;
                        restart();
                    }
            for(int y=0;y<liste_ia.size();y++){
                int pos_x = liste_ia.at(y).getPos().x/32+1;
                int pos_y = liste_ia.at(y).getPos().y/32+2;
                //liste_ia.at(y).deplacement(deltaTime,Window.Getlargeur());
                if(liste_ia.at(y).colisionMethode(deltaTime,map_afficher[pos_y][pos_x-1],
                                                         map_afficher[pos_y-1][pos_x],
                                                         map_afficher[pos_y-1][pos_x-1],
                                                         joueur.getPos(),
                                                         joueur.getSaut()
                                                            )==1){
                    if(deltaTimeVul>1){
                        vie-=1;
                        joueur.sefaisfrappe(liste_ia.at(y).getSens(),map_afficher[pos_y-1][pos_x], map_afficher[pos_y-1][pos_x-1]);
                        cloackVul.restart();
                    }


                                                         }

                                    if((sf::Joystick::isConnected(0)&&sf::Joystick::isButtonPressed(0, 2))||sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                                      //  if(){
                                            if(joueur.attaque(liste_ia.at(y).getPos(),1)==1){
                        liste_ia.erase(liste_ia.begin()+y);
                        enemies-=1;
                        enemies_kill+=1;
                        texts.at(0).setString("Enemies restants : "+std::to_string(enemies));
                        texts.at(2).setString("Enemies tués : "+std::to_string(enemies_kill));
                    }
                                       // }
                                    }

             /*   if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    if(joueur.attaque(liste_ia.at(y).getPos(),1)==1){
                        liste_ia.erase(liste_ia.begin()+y);
                        enemies-=1;
                        enemies_kill+=1;
                        texts.at(0).setString("Enemies restants : "+std::to_string(enemies));
                        texts.at(2).setString("Enemies tués : "+std::to_string(enemies_kill));
                    }*/
            }
            for(int y=0;y<liste_nuages.size();y++){
                liste_nuages.at(y).deplacement(deltaTime,Window.Getlargeur());
                if(liste_nuages.at(y).test()==1){
                    soin soin_objet(texture_soin,liste_nuages.at(y).getSprite().getPosition());
                    liste_soin.push_back(soin_objet);
                }
            }
            for(int g=0;g<liste_soin.size();g++){
                int pos_x = liste_soin.at(g).getPos().x/32+1;
                int pos_y = liste_soin.at(g).getPos().y/32+2;
                liste_soin.at(g).colisionMethode(deltaTime,map_afficher[pos_y-1][pos_x-1]);
                std::cout << g;
                if(liste_soin.at(g).marchedessus(joueur.getPos())==1){
                    liste_soin.erase(liste_soin.begin()+g);
                    if(vie<10)
                        vie++;
                }
            }
            int pos_x = joueur.getPos().x/32+1;
            int pos_y = joueur.getPos().y/32+2;
            if(joueur.getPos().y<0||joueur.getPos().x<0)
                joueur.reset();

            joueur.colisionMethode();
            if(joueur.getSens())
                sprites.at(1).setPosition(joueur.getPos().x+48,joueur.getPos().y+16);
            else
                sprites.at(1).setPosition(joueur.getPos().x-32,joueur.getPos().y+16);

            joueur.setTex();

           // std::cout << joueur.getSens() << std::endl;
            joueur.update(deltaTime,
                          map_afficher[pos_y][pos_x-1],
                          map_afficher[pos_y+1][pos_x],
                          map_afficher[pos_y-1][pos_x],
                          map_afficher[pos_y-1][pos_x-1]);
        }
        affichage();
    }
}

void jeu::creerSprite(sf::Texture &texture,std::string endroit,sf::Vector2f pos,sf::Vector2f tai){
    sf::Sprite spriteCreer;
    spriteCreer.setTexture(texture);
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
    srand(time(NULL));
    texture_soin.loadFromFile("design/soin.png");
    texture_soin.setSmooth(true);
    texture_nuage.loadFromFile("design/nuage.png");
    texture_nuage.setSmooth(true);
    bufferpas.loadFromFile("audio/objet_tombe.wav");
    soundPas.setBuffer(bufferpas);
    texture_ia.loadFromFile("design/patagiraf.png");
    texture_ia.setSmooth(true);
    texture_epee.loadFromFile("design/epee.png");
    texture_epee.setSmooth(true);
    jeuCamera.reset(sf::FloatRect(0, 0, 1280, 640));
    creerRectangle(sf::Color::Red,sf::Vector2f(0,0),sf::Vector2f(Window.Getlargeur(),64),1,sf::Color::Black);
    creerRectangle(sf::Color::Red,sf::Vector2f(0,Window.Gethauteur()-64),sf::Vector2f(Window.Getlargeur(),64),1,sf::Color::Black);
    creerTexte(30,sf::Color::Black,"Echap pour quitter ! Entrer pour jouer !",sf::Vector2f(Window.Getlargeur()/3,Window.Gethauteur()/70));
    creerTexte(30,sf::Color::Black,"(Ia : Facile) | Ia : Moyen | Ia : Dur",sf::Vector2f(Window.Getlargeur()/2.8,Window.Gethauteur()/1.05));
    boucle();
}

jeu::~jeu()
{
    //dtor
}
