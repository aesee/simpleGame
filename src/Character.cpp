#include "Character.h"

Character::Character(std::string File, float X, float Y, float W, float H)
{
    dx = 0;
    dy = 0;
    speed = 0;
    direction = 0;
    name = File;
    w = W;
    h = H;

    health = 10;

    if(!image.loadFromFile("Assets/" + name))
    {
        image.create(50,50,sf::Color(100,100,100));
    }
    //image.createMaskFromColor(Color(41, 33, 59)); // delete some noise from sprite
    texture.loadFromImage(image);
    image.~Image();
    sprite.setTexture(texture);

    x = X;
    y = Y;
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

Character::~Character()
{
    //dtor
}
