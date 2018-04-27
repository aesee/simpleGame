#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Character.h"
#include "Command.h"

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
        void movementControl(float & time);

    private:
        //float x,y;
        void interactionWithMap(Level & level);
        float currentFrame;
        InputHandler* input;
};

#endif // PLAYER_H
