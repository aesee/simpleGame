#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cool game");

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
    heroSprite.setPosition(50,25);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(heroSprite);
        window.display();
    }

    return 0;
}
