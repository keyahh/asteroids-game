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
	//TextBox scoreBox;
	sf::Text scoreBoard;
	float asteroidSpawnTime = 2.5, asteroidSpawnTimeProgress = 4.5;

	int rngRangeNeg(int min, int max);
	void setNewGame();
	void loadFromFile();

	void setAsteroid(); //creates an asteroid
	void summonAsteroids(); //summons a random amount of asteroids around the player's view
	void asteroidsLoop(float dt);
	void collisionLoop();
	void entityLifeCycleLoop(float dt);
	void killAsteroid(Entity* asteroid, Entity* bullet);

	float getDistance(Entity* entity1, Entity* entity2);

	void die();

public:

	GameState();
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font, bool readFromFile = false);

	virtual void update(float dt);
	virtual void render(sf::RenderTarget* window = nullptr);
	virtual void close();

};

#endif