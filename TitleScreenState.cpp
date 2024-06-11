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
	startButton.setPosition({ windowSize.x / 2 - startButton.getGlobalBounds().width / 2, windowSize.y / 2 - startButton.getGlobalBounds().height / 2 + 50 });
}

void TitleScreenState::update(float dt)
{
	startButton.update(dt);
}

void TitleScreenState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect);
	target.draw(startButton);
}

void TitleScreenState::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
{
	window.setMouseCursorVisible(true);
	startButton.eventHandler(window, event, dt);
	if (startButton.getClicked())
	{
		close();
	}
}
