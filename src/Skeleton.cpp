#include "Skeleton.h"

Skeleton::Skeleton(std::string File, float X, float Y, float W, float H) : Monster (File, X, Y, W, H)
{
    power = 2;
    health = 8;
}

Skeleton::~Skeleton()
{
    //dtor
}
