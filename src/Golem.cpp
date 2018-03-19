#include "Golem.h"

Golem::Golem(std::string File, float X, float Y, float W, float H) : Monster (File, X, Y, W, H)
{
    power = 5;
    health = 10;
}

Golem::~Golem()
{
    //dtor
}
