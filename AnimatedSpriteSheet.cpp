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

//void AnimatedSpriteSheet::init(const std::string& imgPath, int rows, int cols)
//{
//	if (!texture->loadFromFile(imgPath))
//		exit(28);
//	int width = texture.getSize().x;
//	int height = texture.getSize().y;
//
//	intRect.width = width / cols;
//	intRect.height = height / rows;
//	//pos defaults at 0,0
//
//	setTextureRect(intRect);
//	setTexture(texture);
//	//sprite.setScale(2.5, 2.5);
//
//	//hitbox.setFillColor(sf::Color::Blue);
//	//hitbox.setSize({ static_cast<float>(width / cols * 0.7) , static_cast<float>(height/ rows * 0.8) });
//	//centerHitBox();
//}

void AnimatedSpriteSheet::centerHitBox() //centers on sprite
{
	//hitbox.setPosition({ getGlobalBounds().left + (getGlobalBounds().width / 2) - hitbox.getGlobalBounds().width / 2, getGlobalBounds().top + (getGlobalBounds().height / 2) - hitbox.getGlobalBounds().height / 2 });
}

/*
void AnimatedSpriteSheet::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	//window.draw(hitbox);
	window.draw(*this);
}
*/

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

