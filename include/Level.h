#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include <SFML/Graphics.hpp>

class Level
{
public:
    Level(std::string nameBackground);
    virtual ~Level();
    void draw(sf::RenderWindow & window);
    void drawObjects();

    static const int HEIGHT_MAP = 64;
    static const int WIDTH_MAP = 64;
    //static void display(sf::RenderWindow window);

    sf::Texture bg_texture;
    sf::Sprite background;

    sf::String TileMap[HEIGHT_MAP] = {
	"00000000000000000000000000000000",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"0                              0",
	"00000000000000000000000000000000",
    };
};

#endif // MAP_H_INCLUDED


