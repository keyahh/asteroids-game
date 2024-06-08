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

class State : public sf::Drawable
{
private:

protected:
	std::vector<sf::Texture*> textures;
	bool canClose = false;
	sf::RenderWindow* window;
	std::stack<State*>* states;

public:
	State();
	State(sf::RenderWindow* window, std::stack<State*>* states);

	virtual bool getClose() const;
	bool checkKeyPress() const;
	bool checkKeyPress(const sf::Keyboard::Key& key) const;

	virtual void close();
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void render(sf::RenderTarget* window);
	virtual void eventHandler(sf::RenderWindow& window, sf::Event& event, float dt);

};

