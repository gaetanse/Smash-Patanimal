#ifndef JEU_H
#define JEU_H

#include "librairies.h"
#include "fenetre.h"

class jeu
{
    public:
        jeu();
        virtual ~jeu();

        void boucle();

    protected:

    private:

    fenetre Window;
    sf::Event event;
    bool fin=false;

};

#endif // JEU_H
