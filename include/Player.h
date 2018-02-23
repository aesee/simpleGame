#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>

class Player
{
    public:
        float w,h,dx,dy,speed;
        int direction;
        std::string file;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        Player(std::string File, float X, float Y, float W, float H);
        virtual ~Player();
        void update(float time);
        float getPlayerPosX();
        float getPlayerPosY();

    private:
        float x,y;
        void interactionWithMap();
};

#endif // PLAYER_H
