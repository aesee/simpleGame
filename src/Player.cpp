#include "Player.h"
#include "Level.h"

enum { LEFT, RIGHT, UP, DOWN };

Player::Player(std::string File, float X, float Y, float W, float H) : Character(File, X, Y, W, H)
{
    // Nothing's here yet
}

void Player::update(float time)
{
    switch(direction)
    {
        case LEFT:
            dx = -speed;
            dy = 0;
            break;
        case RIGHT:
            dx = speed;
            dy = 0;
            break;
        case UP:
            dx = 0;
            dy = -speed;
            break;
        case DOWN:
            dx = 0;
            dy = speed;
            break;
    }

    x += dx * time;
    y += dy * time;

    speed = 0;
    sprite.setPosition(x,y);
    interactionWithMap();
    if (health < 0) speed = 0;
}

void Player::control()
{

}

void Player::interactionWithMap()
{
    for (int i = y / 32; i < (y + h) / 32; i++)
        for (int j = x / 32; j<(x + w) / 32; j++)
        {
            if (Level::TileMap[i][j] == '0')
			{
                if (dy>0)   y = i * 32 - h;
				if (dy<0)	y = i * 32 + 32;
				if (dx>0)	x = j * 32 - w;
				if (dx < 0)	x = j * 32 + 32;
            }

            /*if (Level::TileMap[i][j] == 's')
                Level::TileMap[i][j] = ' ';

            if (Level::TileMap[i][j] == 'f')
            {
                health -= 10;
                Level::TileMap[i][j] = ' ';
            }

            if (Level::TileMap[i][j] == 'h')
            {
                health += 1;
                Level::TileMap[i][j] = ' ';
            }*/
        }
}

float Player::getPlayerPosX()
{
    return x + 65;
}

float Player::getPlayerPosY()
{
    return y + 50;
}

Player::~Player()
{

}
