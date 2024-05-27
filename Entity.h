#ifndef ENTITYH
#define ENTITYH

#include "AnimatedSpriteSheet.h"

class Entity : public AnimatedSpriteSheet
{
private:

protected:
	float speed = 1;
	bool canMove = true, collision = true, canKill = false;

	void setAnimation(int row);

public:
	Entity();
	//Entity(const std::string& texturePath, int rows, int cols);
	Entity(sf::Texture* texture, int rows, int cols);

	void move(const sf::Vector2f& vec, float dt);
	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view) = 0;
	const bool getCanKill() const;
	void kill();
};

#endif

