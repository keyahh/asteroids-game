#include "TitleScreenState.h"

TitleScreenState::TitleScreenState()
	: State(nullptr, nullptr)
{
}

TitleScreenState::TitleScreenState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	rect.setSize({ 800, 700 });
	rect.setTexture(Textures::getTexture(Textures::SPLASH_SCREEN));

	startButton.create("Start Game", window, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), {150,50}, 24, sf::Color::White, sf::Color::Black);
	startButton.setPosition({325, 350});
}

void TitleScreenState::update(float dt)
{
	//keyEvents(dt);
	startButton.update(dt, window);

	if (startButton.getClicked())
	{
		close();
		//states->push(new MainMenuState(window, states, font));
	}
}

void TitleScreenState::render(sf::RenderTarget* window)
{
	window->draw(rect);
	window->draw(startButton);
}

void TitleScreenState::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
{
	/*if (checkKeyPress())
	{
		close();
	}*/
}
