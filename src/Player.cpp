#include "Player.h"

Player::Player(std::string File, float X, float Y, float W, float H)
{
    dx = 0;
    dy = 0;
    speed = 0;
    direction = 0;
    file = File;
    w = W;
    h = H;

    if(!image.loadFromFile("Assets/" + file))
    {
        image.create(50,50,sf::Color(100,100,100));
    }
    //image.createMaskFromColor(Color(41, 33, 59)); // delete some noise from sprite
    texture.loadFromImage(image);
    image.~Image();
    sprite.setTexture(texture);

    x = X;
    y =Y;
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Player::update(float time)
{
    switch(direction)
    {
        case 0:
            dx = -speed;
            dy = 0;
            break;
        case 1:
            dx = speed;
            dy = 0;
            break;
        case 2:
            dx = 0;
            dy = -speed;
            break;
        case 3:
            dx = 0;
            dy = speed;
            break;
    }

    x += dx * time;
    y += dy * time;

    speed = 0;
    sprite.setPosition(x,y);
}

Player::~Player()
{

}
