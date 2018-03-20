#include "MonstersController.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Golem.h"
#include "Character.h"
#include "Level.h"

MonstersController::MonstersController()
{
    static Skeleton skeleton("skeleton.png", 100,220,16.0,32.0);
    static Goblin goblin("goblin.png", 400,320,16.0,32.0);
    static Goblin goblin2("goblin.png", 300,500,16.0,32.0);
    static Golem golem("golem.png", 600,520,32.0,32.0);
    monsters = { &skeleton, &goblin, &goblin2, &golem };
}

void MonstersController::update(float time, Level & level, Player & player)
{
    for(auto monster : monsters)
    {
        monster->update(time, level, player);
    }
}

void MonstersController::draw(sf::RenderWindow & window)
{
    for(auto monster : monsters)
    {
        window.draw(monster->sprite);
    }
}

MonstersController::~MonstersController()
{
    //dtor
}
