#include "MainMenuState.h"

MainMenuState::MainMenuState()
	: State(nullptr, nullptr)
{
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	rect.setSize({ 280, 280 });
	rect.setTexture(Textures::getTexture(Textures::MENU_ART));
	rect.setPosition({ 400, 150 });

	continueGame.create("Continue Game", window, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 250,50 }, 24, sf::Color::Black, sf::Color::White);
	newGame.create("New Game", window, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 250,50 }, 24, sf::Color::Black, sf::Color::White);

	continueGame.setPosition({ 100, 170 });
	newGame.setPosition({ 100, 270 });
}

const bool MainMenuState::findSaveFile() const
{
	return static_cast<bool>(std::ifstream("game_save.txt"));
}

void MainMenuState::setNewGame()
{
	states->push(new GameState(window, states, false));
}

void MainMenuState::loadGame()
{
	states->push(new GameState(window, states, true));
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

void MainMenuState::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
{
	if (continueGame.getClicked() && findSaveFile())
	{
		loadGame();
	}
	if (newGame.getClicked())
	{
		setNewGame();
	}
}
