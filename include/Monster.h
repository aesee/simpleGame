#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Player.h"


class Monster : public Character
{
    public:
        Monster(std::string name, float x, float y, float w, float h);
        virtual ~Monster() = 0;
        void update(Player & player);

    private:
        int power;
        void attack(Player & player);
};

#endif // MONSTER_H
