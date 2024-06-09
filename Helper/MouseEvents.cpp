#ifndef MOUSEEVENTSCPP
#define MOUSEEVENTSCPP

#include "MouseEvents.h"


template <typename T>
bool MouseEvents::isHovered(const T& obj, sf::RenderWindow& window, int padding)
{
	return obj.sf::Shape::getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window) - sf::Vector2f(padding, padding));
}

template<typename T>
bool MouseEvents::isClicked(const T& obj, sf::RenderWindow& window, int padding)
{
	return isHovered(obj, window, padding) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif