#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include <SFML/Graphics.hpp>

sf::View camera;
int width = 32;
int height = 32;

int rightBorder = width * 32 - 320;
int topBorder = height * 32 - 240;

void setCameraInPos(float x, float y)
{
    float tempX = x; float tempY = y;

    if (x < 320) tempX = 320;
    if (x > rightBorder) tempX = rightBorder;
	if (y < 240) tempY = 240;
	if (y > topBorder) tempY = topBorder;

    camera.setCenter(tempX, tempY);
}

#endif // CAMERA_H_INCLUDED
