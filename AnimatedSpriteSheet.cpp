#include "AnimatedSpriteSheet.h"

AnimatedSpriteSheet::AnimatedSpriteSheet()
	: rows(0), cols(0)
{
}

//AnimatedSpriteSheet::AnimatedSpriteSheet(const std::string& imgPath, int rows, int cols) ///textures should always be passed in as actual pointer not texture path
//	: rows(rows), cols(cols)
//{
//	init(imgPath, rows, cols);
//}

AnimatedSpriteSheet::AnimatedSpriteSheet(sf::Texture* texture, int rows, int cols)
	: rows(rows), cols(cols), texture(texture)
{
	int width = AnimatedSpriteSheet::texture->getSize().x;
	int height = AnimatedSpriteSheet::texture->getSize().y;
	intRect.width = width / cols;
	intRect.height = height / rows;
	setTextureRect(intRect);
	setTexture(*AnimatedSpriteSheet::texture);
}


void AnimatedSpriteSheet::addAnimation(const Animation& animation)
{
	animations.push_back(animation);
}

void AnimatedSpriteSheet::playAnimation(int index, const float& dt)
{
	if (index > rows)
		return;
	animations[index].playAnimation(dt);
}

void AnimatedSpriteSheet::setIntRectPos(int x, int y)
{
	intRect.left = x;
	intRect.top = y;
	setTextureRect(intRect);
}

void AnimatedSpriteSheet::setIntRectPos(const sf::Vector2f& pos)
{
	intRect.left = pos.x;
	intRect.top = pos.y;
	setTextureRect(intRect);
}

void AnimatedSpriteSheet::setRowCol(int row, int col)
{
	intRect.left = col * intRect.width;
	intRect.top = row * intRect.height;
	setTextureRect(intRect);
}
/*
sf::Sprite& AnimatedSpriteSheet::getSprite()
{
	return sprite;
}
*/

sf::IntRect& AnimatedSpriteSheet::getRect()
{
	return intRect;
}

