#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Player.h"
#include "Level.h"
#include <iostream>
#include <sstream>

enum { LEFT, RIGHT, UP, DOWN };

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Cool game");
    //sf::RenderWindow window(sf::VideoMode(1024, 768), "Cool game", sf::Style::Fullscreen); // For release
    //window.setFramerateLimit(60); // need to experiment with this

    // Load font
    sf::Font font;
    font.loadFromFile("Assets/ui_font.ttf");
    sf::Text text("", font, 20);
    text.setFillColor(sf::Color::White);
    //text.setStyle(sf::Text::Bold);

    // Set timer of events
    sf::Clock clock;

    // Set frame counter
    float currentFrame = 0;

    // Create a character
    Player player("hero.png", 250,250,32.0,32.0);

    // Set camera on scene
    //camera.setSize(window.getSize().x, window.getSize().y);
    camera.reset(sf::FloatRect(0,0,640,480));

    // Define map
    sf::Image map_image;
    map_image.loadFromFile("Assets/map.png");
    sf::Texture map_texture;
    map_texture.loadFromImage(map_image);
    sf::Sprite map;
    map.setTexture(map_texture);

    // Test background
    sf::Image bg_image;
    bg_image.loadFromFile("Assets/map_bg.png");
    sf::Texture bg_texture;
    bg_texture.loadFromImage(bg_image);
    sf::Sprite bg;
    bg.setTexture(bg_texture);
    bg.setPosition(0,0);

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
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // Controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.direction = LEFT;
            //player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 10) currentFrame -= 10;
            player.changeDirection = 1;
            player.sprite.setTextureRect(sf::IntRect(32 * int(currentFrame),player.changeDirection * 32,32,32));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.direction = RIGHT;
            //player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 10) currentFrame -= 10;
            player.changeDirection = 0;
            player.sprite.setTextureRect(sf::IntRect(32 * int(currentFrame),player.changeDirection * 32,32,32));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.direction = UP;
            //player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 10) currentFrame -= 10;
            player.sprite.setTextureRect(sf::IntRect(32 * int(currentFrame),player.changeDirection * 32,32,32));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.direction = DOWN;
            //player.speed = 0.1;
            currentFrame += 0.005 * time;
            if (currentFrame > 10) currentFrame -= 10;
            player.sprite.setTextureRect(sf::IntRect(32 * int(currentFrame),player.changeDirection * 32,32,32));
        }

        // Move the character
        player.update(time);

        // Move the camera
        setCameraInPos(player.getPlayerPosX(), player.getPlayerPosY());
        window.setView(camera);

        // Display graphics
        window.clear();

        /*for(int i = 0; i < Level::HEIGHT_MAP; i++)
            for (int j = 0; j < Level::WIDTH_MAP; j++)
            {
                if (Level::TileMap[i][j] == ' ') map.setTextureRect(sf::IntRect(0,0,32,32));
                if (Level::TileMap[i][j] == 's') map.setTextureRect(sf::IntRect(32,0,32,32));
                if (Level::TileMap[i][j] == '0') map.setTextureRect(sf::IntRect(64,0,32,32));
                if ((Level::TileMap[i][j] == 'f')) map.setTextureRect(sf::IntRect(96, 0, 32, 32));
                if ((Level::TileMap[i][j] == 'h')) map.setTextureRect(sf::IntRect(128, 0, 32, 32));

                map.setPosition(j*32,i*32);
                window.draw(map);
            }*/

        window.draw(bg);

        std::ostringstream playerHealthString;
        playerHealthString << player.health;
        text.setString("Health: " + playerHealthString.str());
        text.setPosition(camera.getCenter().x - 300, camera.getCenter().y - 225);

        window.draw(player.sprite);
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
