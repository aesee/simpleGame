#ifndef SKELETON_H
#define SKELETON_H
#include "Monster.h"

class Skeleton : public Monster
{
    public:
        Skeleton(std::string File, float X, float Y, float W, float H);
        ~Skeleton();
};

#endif // SKELETON_H
