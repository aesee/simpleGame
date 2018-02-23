#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cool game");

    // Set timer of events
    sf::Clock clock;

    // Set frame counter
    float currentFrame = 0;

    // Create a character
    Player player("hero.png", 250,250,96.0,96.0);

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
            player.direction = 0;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),96,96,96));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.direction = 1;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),192,96,96));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.direction = 2;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),288,96,96));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.direction = 3;
            player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            player.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame),0,96,96));
        }

        // Move the character
        player.update(time);

        // Display graphics
        window.clear();
        window.draw(player.sprite);
        window.display();
    }

    return 0;
}

/*enum
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};*/
