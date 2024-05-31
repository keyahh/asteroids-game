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

class State
{
private:

protected:
	std::vector<sf::Texture*> textures;
	bool canClose = false;
	sf::RenderWindow* window;
	std::stack<State*>* states;
	//std::ofstream* out;
	//std::ifstream* in;
	sf::Font* font;

public:
	State();
	State(sf::RenderWindow* window, std::stack<State*>* states);
	State(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font);

	virtual bool getClose() const;
	bool checkKeyPress() const;
	bool checkKeyPress(const sf::Keyboard::Key& key) const;

	virtual void close();
	virtual void update(float dt);
	virtual void render(sf::RenderTarget* window);
	virtual void keyEvents(const float& dt);

};

