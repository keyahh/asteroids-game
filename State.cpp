#include "state.h"

State::State()
	: window(nullptr), states(nullptr)
{
}

State::State(sf::RenderWindow* window, std::stack<State*>* states)
	: window(window), states(states)
{
}

State::State(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font)
	: window(window), states(states), font(font)
{
}

void State::close()
{
	canClose = true;
}

void State::update(float dt)
{
}

void State::render(sf::RenderTarget* window)
{
}

void State::keyEvents(const float& dt)
{
}

bool State::getClose() const
{
	return canClose;
}

bool State::checkKeyPress() const
{
	for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
			return true;
	}
	return false;
}

bool State::checkKeyPress(const sf::Keyboard::Key& key) const
{
	if (sf::Keyboard::isKeyPressed(key))
		return true;
	return false;
}
