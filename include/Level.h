#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include <SFML/Graphics.hpp>

// Class with static fields
class Level
{
public:
    const static int HEIGHT_MAP = 64;
    const static int WIDTH_MAP = 64;

    static sf::String TileMap[HEIGHT_MAP];
};

#endif // MAP_H_INCLUDED


