#include "Level.h"

/*void Level::display(sf::RenderWindow window)
{
    window.draw(background);
}*/
Level::Level(std::string nameBackground)
{
    sf::Image bg_image;
    //bg_image.loadFromFile("Assets/" + nameBackground);
    bg_image.loadFromFile("Assets/" + nameBackground);
    //bg_image.createMaskFromColor(sf::Color(255,255,255));
    bg_texture.loadFromImage(bg_image);
    background.setTexture(bg_texture);
    background.setPosition(0,0);
}

void Level::draw(sf::RenderWindow & window)
{
    window.draw(background);
}

void Level::drawObjects()
{
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

            //also need to load tiles before
                /*sf::Image map_image;
    map_image.loadFromFile("Assets/map.png");
    sf::Texture map_texture;
    map_texture.loadFromImage(map_image);
    sf::Sprite map;
    map.setTexture(map_texture);*/
}

Level::~Level()
{

}
