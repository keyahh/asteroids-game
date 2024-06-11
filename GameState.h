#ifndef GAMESTATEH
#define GAMESTATEH

#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Explosion.h"
#include "BigExplosion.h"
#include "Planet.h"
#include "MainMenuState.h"
#include "Ufo.h"
#include <cstdlib>
#include <ctime>

class GameState : public State
{
private:
	int score, lives;

	Player* player;
	sf::View playerCamera;
	sf::RectangleShape marker;
	std::vector<Entity*> entities;
	std::vector<Particle*> particles;
	std::vector<sf::CircleShape> livesVec;

	sf::Text scoreBoard;
	sf::Text deathText;

	float asteroidSpawnTime = 2.5, asteroidSpawnTimeProgress = 4.5, dt, ufoSpawnTime = 8.f, ufoSpawnTimeProgress = 10.f;
	float rotation; //for player

	int rngRangeNeg(int min, int max);
	void setNewGame();
	void loadFromFile();
	void setLives();
	void moveLives();
	void setPlanet();
	void summonPlanets();
	void setAsteroid(); //creates an asteroid
	void summonAsteroids(); //summons a random amount of asteroids around the player's view
	void asteroidsLoop(float dt);
	void ufoLoop(float dt);
	void collisionLoop();
	void particlesLoop(float dt);
	void entityLifeCycleLoop(float dt);
	void killAsteroid(Entity* asteroid, Entity* bullet);
	void hitPlanet(Entity* planet, Entity* bullet);
	void summonUFO();
	void ufoMain(Entity* ufo);

	float getDistance(Entity* entity1, Entity* entity2);

	void hitPlayer();
	void die();

	void saveGame();
	void clearEntities();

public:

	GameState();
	GameState(const sf::Vector2f& windowSize, std::stack<State*>* states, bool readFromFile = false);

	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event, float dt);
	virtual void close();

};

#endif