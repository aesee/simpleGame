#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Player.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Golem.h"
#include "Character.h"
#include "Level.h"
#include <iostream>
#include <sstream>
#include "MonstersController.h"

sf::Font font;
sf::Text text;

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Cool game");
    //sf::RenderWindow window(sf::VideoMode(1024, 768), "Cool game", sf::Style::Fullscreen); // For release
    //window.setFramerateLimit(60); // need to experiment with this

    // Load font
    font.loadFromFile("Assets/ui_font.ttf");
    text = sf::Text("", font, 20);
    text.setFillColor(sf::Color::White);

    // Set timer for events
    sf::Clock clock;

    // Create a character
    Player player("hero.png", 100,50,32.0,32.0);

    // Create a monsters for a hero
    MonstersController monsters;

    // Set camera on scene
    camera.reset(sf::FloatRect(0,0,640,480));

    // Define map
    Level level("map_bg2.png");

    // Game cycle
    while(window.isOpen())
    {
        // Count time
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 400;    // speed of the game

        // Closing game
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // And then move the character
        player.update(time, level);
        // and the monsters
        monsters.update(time,level,player);

        // Move the camera
        setCameraInPos(player.getPlayerPosX(), player.getPlayerPosY());
        window.setView(camera);

        // Update UI
        std::ostringstream playerHealthString;
        playerHealthString << player.getHealth();
        text.setString("Health: " + playerHealthString.str());
        text.setPosition(camera.getCenter().x - 300, camera.getCenter().y - 225);

        // Display graphics
        window.clear();
        level.draw(window);
        window.draw(player.sprite);
        monsters.draw(window);
        window.draw(text);
        window.display();
    }

    return 0;
}

/*  //Template for convert to string from any type
template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}
*/
