#ifndef TITLESCREENH
#define TITLESCREENH

#include "MainMenuState.h"
#include "Helper/Button.h"

class TitleScreenState : public State
{
private:
	sf::RectangleShape rect;

	TextBox startButton;
	//Button start;

public:
	TitleScreenState();
	TitleScreenState(const sf::Vector2f& windowSize, std::stack<State*>* states);

	virtual void update(float dt);
	virtual void update(sf::RenderTarget& target, float dt);
	virtual void render(sf::RenderWindow& window, sf::RenderStates states);
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event, float dt);

};

#endif