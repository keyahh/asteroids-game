#ifndef ENTITYH
#define ENTITYH

#include "AnimatedSpriteSheet.h"

class Entity : public AnimatedSpriteSheet
{
private:

protected:
	float speed = 1;
	bool canMove = true;
	bool collision = true;

public:
	Entity();
	//Entity(const std::string& texturePath, int rows, int cols);
	Entity(sf::Texture* texture, int rows, int cols);

	void move(const sf::Vector2f& vec, float dt);
	void update(const float& dt, sf::RenderWindow* window, sf::View& view);
};

#endif

