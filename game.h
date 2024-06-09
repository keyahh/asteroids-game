#ifndef GAMEH
#define GAMEH

#include "GameState.h"
#include "TitleScreenState.h"
#include "MainMenuState.h"

class Game
{
private:
	sf::Event event;
	sf::Clock clock;
	sf::RenderWindow* window;
	std::ofstream out;
	std::ifstream in;
	sf::RenderStates renderStates;
	float dt = 0;

	std::stack<State*> states;

public:
	Game();
	Game(const Game& game);
	Game(sf::RenderWindow* window);

	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt);
	void update();
	void render();
	void run();
	void closeGame();

	Game& operator =(const Game& game);
	~Game();
};

#endif
