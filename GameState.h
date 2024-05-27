#ifndef GAMESTATEH
#define GAMESTATEH

#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <cstdlib>
#include <ctime>

class GameState : public State
{
private:
	int score;

	Player* player;
	sf::View playerCamera;
	sf::RectangleShape marker;
	std::vector<Entity*> entities;
	TextBox scoreBox;
	float asteroidSpawnTime = 6, asteroidSpawnTimeProgress = 6;

	void setNewGame();
	void loadFromFile();

	void setAsteroid(); //creates an asteroid
	void summonAsteroids(); //summons a random amount of asteroids around the player's view

	float getDistance(Entity* entity1, Entity* entity2);

public:

	GameState();
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font, bool readFromFile = false);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* window = nullptr);
	virtual void close();

};

#endif