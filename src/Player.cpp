#include "Player.h"
#include "Level.h"
#include "GameOver.h"

enum { LEFT, RIGHT, UP, DOWN };

Player::Player(std::string name, float x, float y, float w, float h) : Character(name, x, y, w, h)
{
    // Nothing's here yet
    attack = false;
    // Set frame counter
    currentFrame = 0;

    health = 10;
}

void Player::update(float time, Level & level)
{
    if (health > 0)
    {
        control(time);

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
        interactionWithMap(level);
    }
    else gameOver();
}

void Player::control(float & time)
{
        if (attack)
        {
            currentFrame += 0.005 * time;
            if (currentFrame > 10)
            {
                attack = false;
                currentFrame -= 10;
            }
            sprite.setTextureRect(sf::IntRect(w * int(currentFrame),changeDirection * h + 64,w,h));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            attack = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction = LEFT;
            changeDirection = 1;
            movementControl(time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction = RIGHT;
            changeDirection = 0;
            movementControl(time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction = UP;
            movementControl(time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction = DOWN;
            movementControl(time);
        }
}

void Player::interactionWithMap(Level & level)
{
    for (int i = y / 32; i < (y + h) / 32; i++)
        for (int j = x / 32; j<(x + w) / 32; j++)
        {
            if (level.TileMap[i][j] == '0')
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

void Player::movementControl(float & time)
{
    speed = 0.05;
    currentFrame += 0.005 * time;
    if (currentFrame > 10)
        currentFrame -= 10;
    //if ((int)currentFrame % 5 == 0) speed = 0.06;
    sprite.setTextureRect(sf::IntRect(w * int(currentFrame),changeDirection * h,w,h));
}

// The following used only for camera offset
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
