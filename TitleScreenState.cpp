#include "TitleScreenState.h"

TitleScreenState::TitleScreenState()
{
}

TitleScreenState::TitleScreenState(const sf::Vector2f& windowSize, std::stack<State*>* states)
	: State(states, windowSize)
{
	rect.setSize({ windowSize.x, windowSize.y + 100 });
	rect.setTexture(Textures::getTexture(Textures::SPLASH_SCREEN));

	startButton.create("Start Game", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 150,50 }, 24, sf::Color::White, sf::Color::Black);
	startButton.setPosition({ 325, 350 });
}

void TitleScreenState::update(float dt)
{
	startButton.update(dt);
}

void TitleScreenState::update(sf::RenderTarget& target, float dt)
{
	startButton.update(dt);

	if (startButton.getClicked())
	{
		close();
	}
}

void TitleScreenState::render(sf::RenderWindow& window, sf::RenderStates states)
{
	window.draw(rect);
	window.draw(startButton);
}

void TitleScreenState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect);
	target.draw(startButton);
}

void TitleScreenState::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
{
	startButton.eventHandler(window, event, dt);
	if (startButton.getClicked())
	{
		close();
	}
}
