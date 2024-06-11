#ifndef GAMEH
#define GAMEH

#include "GameState.h"
#include "TitleScreenState.h"
#include "MainMenuState.h"

class Game : public sf::Drawable
{
private:
	sf::RenderWindow* window;
	//std::ofstream out;
	//std::ifstream in;
	std::stack<State*> states;

public:
	Game();
	Game(const Game& game);
	Game(sf::RenderWindow* window);

	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt);
	void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void closeGame();

	Game& operator =(const Game& game);
	~Game();
};

#endif
