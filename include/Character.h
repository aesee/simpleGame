#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <string>

class Character
{
    public:
        float x,y,w,h,dx,dy,speed;
        int direction, health, changeDirection;
        std::string name;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        Character(std::string File, float X, float Y, float W, float H);
        virtual ~Character();
};

#endif // CHARACTER_H
