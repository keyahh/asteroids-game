#include "Frame.h"

Frame::Frame()
	: Frame({0,0}, 0)
{

}

Frame::Frame(const sf::Vector2f& rectanglePos, double frameLength)
	: rectPos(rectanglePos), frameLength(frameLength)
{

}