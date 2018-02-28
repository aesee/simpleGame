#include "Monster.h"

Monster::Monster(std::string name, float x, float y, float w, float h) : Character(name, x, y, w, h)
{
    //ctor
}

void Monster::update(Player & player)
{
    //if (std::abs(player.getPlayerPosX() - this->x) && std::abs(player.getPlayerPosY() - this->y))

}

void Monster::attack(Player & player)
{
    //player.health -= power;
}

Monster::~Monster()
{
    //dtor
}
