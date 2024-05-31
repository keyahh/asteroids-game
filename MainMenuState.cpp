#include "MainMenuState.h"

MainMenuState::MainMenuState()
	: State(nullptr, nullptr)
{
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font)
	: State(window, states, font)
{

	textures.push_back(new sf::Texture);
	textures[0]->loadFromFile("images/art.png");

	rect.setSize({ 280, 280 });
	rect.setTexture(textures[0]);
	rect.setPosition({ 400, 150 });

	continueGame.create("Continue Game", window, *font, { 250,50 }, 24, sf::Color::Black, sf::Color::White);
	newGame.create("New Game", window, *font, { 250,50 }, 24, sf::Color::Black, sf::Color::White);

	continueGame.setPosition({ 100, 170 });
	newGame.setPosition({ 100, 270 });
}

const bool MainMenuState::findSaveFile() const
{
	return static_cast<bool>(std::ifstream("game_save.txt"));
}

void MainMenuState::setNewGame()
{
	states->push(new GameState(window, states, font, false));
}

void MainMenuState::loadGame()
{
	states->push(new GameState(window, states, font, true));
}

void MainMenuState::update(float dt)
{
	continueGame.update(dt, window);
	newGame.update(dt, window);

	if (continueGame.getClicked() && findSaveFile())
	{
		loadGame();
	}
	if (newGame.getClicked())
	{
		setNewGame();
	}
}

void MainMenuState::render(sf::RenderTarget* window)
{
	window->draw(rect);
	window->draw(continueGame);
	window->draw(newGame);
}