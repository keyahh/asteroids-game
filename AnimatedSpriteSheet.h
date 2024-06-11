#ifndef ANIMATEDSPRITESHEET
#define ANIMATEDSPRITESHEET
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include <string>
#include <iostream>

class AnimatedSpriteSheet : public sf::Sprite
{
private:
	sf::IntRect intRect; //gets moved around sprite sheet to display the section bounded
	sf::Texture* texture;
	std::vector<Animation> animations;
	int rows, cols;

public:
	AnimatedSpriteSheet();
	AnimatedSpriteSheet(sf::Texture* texture, int rows, int cols);

	void addAnimation(const Animation& animation);
	void playAnimation(int index, const float& dt);

	void setIntRectPos(int x, int y);
	void setIntRectPos(const sf::Vector2f& pos);
	void setRowCol(int row, int col);

	sf::IntRect& getRect();
};
#endif