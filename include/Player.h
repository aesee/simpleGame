#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Character.h"

class Player : public Character
{
    public:
        Player(std::string File, float X, float Y, float W, float H);
        ~Player();
        void update(float time);
        float getPlayerPosX();
        float getPlayerPosY();
        void control();

    private:
        //float x,y;
        void interactionWithMap();
};

#endif // PLAYER_H
