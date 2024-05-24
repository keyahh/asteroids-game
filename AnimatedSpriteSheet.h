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
	//sf::RectangleShape hitbox;

	//void init(const std::string& imgPath, int rows, int cols);
public:
	AnimatedSpriteSheet();
	//AnimatedSpriteSheet(const std::string& imgPath, int rows, int cols);
	AnimatedSpriteSheet(sf::Texture* texture, int rows, int cols);

	//virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

	void addAnimation(const Animation& animation);
	void playAnimation(int index, const float& dt);

	void setIntRectPos(int x, int y);
	void setIntRectPos(const sf::Vector2f& pos);
	void setRowCol(int row, int col);
	void centerHitBox();

	sf::IntRect& getRect();
	//sf::RectangleShape& getHitBox();

};
#endif