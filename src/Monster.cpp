#include "Monster.h"

Monster::Monster(std::string name, float x, float y, float w, float h) : Character(name, x, y, w, h)
{
    aiCounter = 0;
    currentFrame = 0;
}

void Monster::update(float time, Level & level, Player & player)
{
    //if (std::abs(player.getPlayerPosX() - this->x) && std::abs(player.getPlayerPosY() - this->y))

    //speed = 0.005;
    currentFrame += 0.003 * time;
    if (currentFrame > 3)
        currentFrame -= 3;
    sprite.setTextureRect(sf::IntRect(w * int(currentFrame),changeDirection * h,w,h));

    time /= 80;

    if (aiCounter == 0)
    {
        if (rand() % static_cast<int>(2) == 1)
        {
            dx = rand() % static_cast<int>(3) - 1;
            dy = 0;
            if (dx < 0) changeDirection = 3;
                else changeDirection = 2;
        }
        else
        {
            dx = 0;
            dy = rand() % static_cast<int>(3) - 1;
            if (dy < 0) changeDirection = 1;
                else changeDirection = 0;
        }
    }

    x += dx * time;
    y += dy * time;

    sprite.setPosition(x,y);
    aiCounter++;
    if (aiCounter > 2000) aiCounter-=2001;

    if (abs(x - player.x) < w && abs(y - player.y) < h)
    {
        player.setDamage(power);
        switch(player.direction)
        {
            case 0:
                player.x += 2*w;
                break;
            case 1:
                player.x -= 2*w;
                break;
            case 2:
                player.y += 2*h;
                break;
            case 3:
                player.y -= 2*h;
                break;
        }
    }

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
        }
}

void Monster::attack(Player & player)
{
    player.setDamage(power);
}

Monster::~Monster()
{
    //dtor
}
