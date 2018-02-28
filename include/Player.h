#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Character.h"

class Player : public Character
{
    public:
        Player(std::string name, float x, float y, float w, float h);
        ~Player();
        void update(float time, Level & level);
        float getPlayerPosX();
        float getPlayerPosY();
        void control(float & time);
        bool attack;

    private:
        //float x,y;
        void interactionWithMap(Level & level);
        float currentFrame;
        void movementControl(float & time);
};

#endif // PLAYER_H
