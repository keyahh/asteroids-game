#ifndef TITLESCREENH
#define TITLESCREENH

#include "MainMenuState.h"

class TitleScreenState : public State
{
private:
	sf::RectangleShape rect;

	TextBox startButton;

public:
	TitleScreenState();
	TitleScreenState(sf::RenderWindow* window, std::stack<State*>* states);

	virtual void update(float dt);
	virtual void render(sf::RenderTarget* window = nullptr);
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event, float dt);

};

#endif