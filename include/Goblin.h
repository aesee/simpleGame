#ifndef GOBLIN_H
#define GOBLIN_H
#include "Monster.h"

class Goblin : public Monster
{
    public:
        Goblin(std::string File, float X, float Y, float W, float H);
        ~Goblin();
};

#endif // GOBLIN_H
