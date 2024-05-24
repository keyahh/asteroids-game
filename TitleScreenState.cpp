#include "TitleScreenState.h"

TitleScreenState::TitleScreenState()
	: State(nullptr, nullptr)
{
}

TitleScreenState::TitleScreenState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font)
	: State(window, states, font)
{
	//sf::Texture splashScreen;
	//assert(splashScreen.loadFromFile("images/splashscreen.png"));
	//textures.push_back(splashScreen);
	textures.push_back(new sf::Texture);
	textures[0]->loadFromFile("images/splashscreen.png");
	rect.setSize({ 800, 700 });
	rect.setTexture(textures[0]);

	startButton.create("Start Game", window, *font, {150,50}, 24, sf::Color::White, sf::Color::Black);
	startButton.setPosition({325, 350});
}

void TitleScreenState::update(const float& dt)
{
	keyEvents(dt);
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

void TitleScreenState::keyEvents(const float& dt)
{
	if (checkKeyPress())
	{
		close();
	}
}
