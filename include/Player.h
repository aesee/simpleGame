#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>

class Player
{
    public:
        float x,y,w,h,dx,dy,speed;
        int direction;
        std::string file;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        Player(std::string File, float X, float Y, float W, float H);
        virtual ~Player();
        void update(float time);

    protected:

    private:
};

#endif // PLAYER_H
