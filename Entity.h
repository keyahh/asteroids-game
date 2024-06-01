#ifndef ENTITYH
#define ENTITYH

#include "AnimatedSpriteSheet.h"
#include "EntityType.h"

class Entity : public AnimatedSpriteSheet
{
private:

protected:
	EntityType type;
	float speed = 1;
	bool canMove = true, collision = true, canKill = false;

	void setAnimation(int row);

public:
	Entity();
	//Entity(const std::string& texturePath, int rows, int cols);
	Entity(sf::Texture* texture, int rows, int cols, EntityType type);

	void move(const sf::Vector2f& vec, float dt);
	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view) = 0;
	virtual const int getValue() const = 0;

	const bool getCanKill() const;
	void kill();
	const EntityType& getType() const;
};

#endif

