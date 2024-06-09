#include "state.h"

State::State()
	: windowSize({0.f,0.f}), states(nullptr)
{
}

State::State(std::stack<State*>* states, const sf::Vector2f& windowSize)
	: states(states), windowSize(windowSize)
{
}

void State::close()
{
	canClose = true;
}

void State::update(float dt)
{
}


void State::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
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
