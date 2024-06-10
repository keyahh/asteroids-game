#ifndef ENTITYH
#define ENTITYH

#include "AnimatedSpriteSheet.h"
#include "EntityType.h"
#include <cstdlib>

class Entity : public AnimatedSpriteSheet
{
private:

protected:
	EntityType type;
	float speed = 1;
	bool canMove = true, collision = true, canKill = false;

	void setAnimation(int row, int cols);

public:
	Entity();
	//Entity(const std::string& texturePath, int rows, int cols);
	Entity(sf::Texture* texture, int rows, int cols, EntityType type);

	virtual void move(const sf::Vector2f& vec, float dt);
	virtual void update(float dt);
	virtual const int getValue() const = 0;
	virtual void hit();
	virtual bool getCanShoot() const;
	virtual void setCanShoot(bool flag);
	const bool getCanKill() const;
	void kill();
	const EntityType& getType() const;
};

#endif

