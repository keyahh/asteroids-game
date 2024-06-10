#ifndef MAINMENUSTATE
#define MAINMENUSTATE

#include "GameState.h"
#include "TitleScreenState.h"

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
	MainMenuState(const sf::Vector2f& windowSize, std::stack<State*>* states);

	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event, float dt);
};

#endif