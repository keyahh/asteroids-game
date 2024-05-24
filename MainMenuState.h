#ifndef MAINMENUSTATE
#define MAINMENUSTATE

#include "GameState.h"

class MainMenuState : public State
{

private:
	TextBox newGame;
	TextBox continueGame;
	sf::RectangleShape rect;

	const bool findSaveFile() const;
	void setNewGame();
	void loadGame();

public:
	MainMenuState();
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* window = nullptr);
};

#endif