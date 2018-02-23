#include <SFML/Graphics.hpp>
#include "Player.h"
#include "map.h"

enum { LEFT, RIGHT, UP, DOWN };

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cool game");
    //window.setFramerateLimit(60); // please check this

    // Set timer of events
    sf::Clock clock;

    // Set frame counter
    float currentFrame = 0;

    // Create a character
    Player player("hero.png", 250,250,96.0,96.0);

    // Define map
    sf::Image map_image;
    map_image.loadFromFile("Assets/map.png");
    sf::Texture map_texture;
    map_texture.loadFromImage(map_image);
    sf::Sprite map;
    map.setTexture(map_texture);

    // Game cycle
    while(window.isOpen())
    {
        // Count time
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 400;    // speed of game

        // Closing game
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.direction = LEFT;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),96,96,96));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.direction = RIGHT;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),192,96,96));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.direction = UP;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),288,96,96));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.direction = DOWN;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),0,96,96));
        }

        // Move the character
        player.update(time);

        // Display graphics
        window.clear();

        for(int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ') map.setTextureRect(sf::IntRect(0,0,32,32));
                if (TileMap[i][j] == 's') map.setTextureRect(sf::IntRect(32,0,32,32));
                if (TileMap[i][j] == '0') map.setTextureRect(sf::IntRect(64,0,32,32));

                map.setPosition(j*32,i*32);
                window.draw(map);
            }

        window.draw(player.sprite);
        window.display();
    }

    return 0;
}

