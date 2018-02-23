#include <SFML/Graphics.hpp>

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cool game");

    // Set timer of events
    sf::Clock clock;

    // Hero image
    sf::Image heroImage;

    if(!heroImage.loadFromFile("Assets/hero.png"))
    {
        heroImage.create(50,50,sf::Color(100,100,100));
    }

    sf::Texture heroTexture;
    heroTexture.loadFromImage(heroImage);
    heroImage.~Image();

    sf::Sprite heroSprite;
    heroSprite.setTexture(heroTexture);
    heroSprite.setTextureRect(sf::IntRect(0,192,96,96));
    heroSprite.setPosition(50,25);

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
            heroSprite.setTextureRect(sf::IntRect(0,96,96,96));
            heroSprite.move(-0.1 * time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            heroSprite.setTextureRect(sf::IntRect(0,192,96,96));
            heroSprite.move(0.1 * time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            heroSprite.setTextureRect(sf::IntRect(0,288,96,96));
            heroSprite.move(0, -0.1 * time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            heroSprite.setTextureRect(sf::IntRect(0,0,96,96));
            heroSprite.move(0, 0.1 * time);
        }

        // Display graphics
        window.clear();
        window.draw(heroSprite);
        window.display();
    }

    return 0;
}
