#ifndef POSITIONH
#define POSITIONH

#include "SFML/Graphics.hpp"

class Position
{
public:
	template <typename T, typename S>
	static void left(const T& constObj, S& obj, float spacing = 0); //moves obj to the left of constObj

	template <typename T, typename S>
	static void right(const T& constObj, S& obj, float spacing = 0);

	template <typename T, typename S>
	static void top(const T& constObj, S& obj, float spacing = 0);

	template <typename T, typename S>
	static void bottom(const T& constObj, S& obj, float spacing = 0);

	template <typename T, typename S>
	static void center(const T& constObj, S& obj);
};

#include "Position.cpp"

#endif
