#ifndef GOLEM_H
#define GOLEM_H
#include "Monster.h"

class Golem : public Monster
{
    public:
        Golem(std::string File, float X, float Y, float W, float H);
        ~Golem();
};

#endif // GOLEM_H
