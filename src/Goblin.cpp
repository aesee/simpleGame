#include "Goblin.h"

Goblin::Goblin(std::string File, float X, float Y, float W, float H) : Monster (File, X, Y, W, H)
{
    power = 1;
    health = 4;
}

Goblin::~Goblin()
{
    //dtor
}
