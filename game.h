#ifndef GAMEH
#define GAMEH

#include "GameState.h"
#include "TitleScreenState.h"
#include "MainMenuState.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	sf::Font font;
	std::ofstream out;
	std::ifstream in;
	float dt = 0;

	std::stack<State*> states; //State is abstract so it cant have actual objects instantiated, only pointers

public:
	Game();
	Game(const Game& game);
	Game(sf::RenderWindow* window);

	void eventHandler();
	void update();
	void render();
	void run();
	void closeGame();

	Game& operator =(const Game& game);
	~Game();
};

#endif
