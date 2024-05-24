#ifndef FRAME
#define FRAME

#include "SFML/Graphics.hpp"

struct Frame
{
	sf::Vector2f rectPos;
	double frameLength;
	Frame();
	Frame(const sf::Vector2f& rectanglePos, double frameLength);
};

#endif