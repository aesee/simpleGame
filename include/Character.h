#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Level.h"

class Character
{
    public:
        float x,y,w,h,dx,dy,speed;
        int direction, health, changeDirection;
        std::string name;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        Character(std::string name, float x, float y, float w, float h);
        virtual ~Character() = 0;
        void update();
};

#endif // CHARACTER_H
