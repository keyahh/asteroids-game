#ifndef POSITIONCPP
#define POSITIONCPP

#include "Position.h"

template<typename T, typename S>
void Position::left(const T& constObj, S& obj, float spacing)
{
	sf::FloatRect cb = constObj.getGlobalBounds();
	sf::FloatRect ob = obj.getGlobalBounds();

	sf::Vector2f pos = { cb.left - ob.width - spacing, cb.top };
	obj.setPosition(pos);
}

template<typename T, typename S>
void Position::right(const T& constObj, S& obj, float spacing)
{
	//sf::Vector2f pos = topRightCorner(constObj.getGlobalBounds());
	sf::Vector2f pos = {constObj.getGlobalBounds().left + constObj.getGlobalBounds().width, constObj.getGlobalBounds().top };
	pos.x += spacing;
	obj.setPosition(pos);
}

template<typename T, typename S>
void Position::top(const T& constObj, S& obj, float spacing)
{
	sf::FloatRect cb = constObj.getGlobalBounds();
	sf::FloatRect ob = obj.getGlobalBounds();
	sf::Vector2f pos = { cb.left, cb.top - ob.height - spacing };
	obj.setPosition(pos);
}

template<typename T, typename S>
void Position::bottom(const T& constObj, S& obj, float spacing)
{
	sf::Vector2f pos = { constObj.getGlobalBounds().left, constObj.getGlobalBounds().top - constObj.getGlobalBounds().height};
	pos.y += spacing;
	obj.setPosition(pos);
}

template<typename T, typename S>
void Position::center(const T& constObj, S& obj)
{
	obj.setPosition(constObj.getGlobalBounds().left + (constObj.getGlobalBounds().width / 2) - (obj.getGlobalBounds().width / 2), constObj.getGlobalBounds().top + (constObj.getGlobalBounds().height / 2) - (obj.getGlobalBounds().height / 2));
}

#endif