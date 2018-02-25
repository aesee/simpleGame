#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include <SFML/Graphics.hpp>

sf::View camera;

void setCameraInPos(float x, float y)
{
    float tempX = x; float tempY = y;

    if (x < 320) tempX = 320;
    if (x > 1728) tempX = 1728;
	if (y < 240) tempY = 240;
	if (y > 1808) tempY = 1808;

    camera.setCenter(tempX, tempY);
    //camera.setCenter(x + 65,y + 50);
}

#endif // CAMERA_H_INCLUDED
