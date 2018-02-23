#include <SFML/Graphics.hpp>

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cool game");

    // Set timer of events
    sf::Clock clock;

    // Set frame counter
    float currentFrame = 0;

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
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame),96,96,96));
            heroSprite.move(-0.1 * time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame),192,96,96));
            heroSprite.move(0.1 * time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame),288,96,96));
            heroSprite.move(0, -0.1 * time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame),0,96,96));
            heroSprite.move(0, 0.1 * time);
        }

        // Display graphics
        window.clear();
        window.draw(heroSprite);
        window.display();
    }

    return 0;
}
