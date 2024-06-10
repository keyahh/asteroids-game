#pragma once

#include <vector>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>
#include <fstream>
#include <assert.h>
#include "TextBox.h"
#include "Entity.h"
#include "Fonts.h"
#include "Textures.h"
#include "Helper/Button.h"

class State : public sf::Drawable
{
private:

protected:
	bool canClose = false;
	std::stack<State*>* states;
	sf::Vector2f windowSize;

public:
	State();
	State(std::stack<State*>* states, const sf::Vector2f& windowSize);

	bool getClose() const;
	bool checkKeyPress() const;
	bool checkKeyPress(const sf::Keyboard::Key& key) const;

	virtual void close();

	virtual void render(sf::RenderWindow& window, sf::RenderStates states) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	virtual void update(float dt);
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event, float dt);

};

