#ifndef GAMESTATEH
#define GAMESTATEH

#include "State.h"
#include "Player.h"
#include "Bullet.h"

class GameState : public State
{
private:
	int score;

	Player* player;
	sf::View playerCamera;
	sf::RectangleShape marker;
	std::vector<Entity*> entities;

	TextBox scoreBox;

	void setNewGame();
	void loadFromFile();

public:

	GameState();
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font, bool readFromFile = false);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* window = nullptr);
	virtual void close();

};

#endif