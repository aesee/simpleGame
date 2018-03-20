#ifndef MONSTERSCONTROLLER_H
#define MONSTERSCONTROLLER_H
#include "Monster.h"
#include <list>
#include <SFML/Graphics.hpp>

class MonstersController
{
    public:
        MonstersController();
        virtual ~MonstersController();
        void update(float time, Level & level, Player & player);
        void draw(sf::RenderWindow & window);

    private:
        std::list<Monster*> monsters;
        std::list<Monster*>::iterator iter;
};

#endif // MONSTERSCONTROLLER_H
