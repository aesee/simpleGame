#include "Character.h"

Character::Character(std::string name, float x, float y, float w, float h)
{
    dx = 0;
    dy = 0;
    speed = 0;
    direction = 0;
    this->name = name;
    this->w = w;
    this->h = h;
    changeDirection = 0;

    if(!image.loadFromFile("Assets/" + name))
    {
        image.create(50,50,sf::Color(100,100,100));
    }
    image.createMaskFromColor(sf::Color(255, 255, 255)); // delete some noise from sprite
    texture.loadFromImage(image);
    image.~Image();
    sprite.setTexture(texture);

    this->x = x;
    this->y = y;
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

int Character::getHealth()
{
    return health;
}

void Character::setDamage(int power)
{
    if (health > 0)
        health -= power;
}

/*void Character::describeLevel(Level data)
{
    level = data;
}*/

Character::~Character()
{
    //dtor
}
