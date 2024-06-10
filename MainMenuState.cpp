#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::MainMenuState(const sf::Vector2f& windowSize, std::stack<State*>* states)
	: State(states, windowSize)
{
	rect.setSize({ 280, 280 });
	rect.setTexture(Textures::getTexture(Textures::MENU_ART));
	rect.setPosition({ 400, 150 });

	continueGame.create("Continue Game", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 250,50 }, 24, sf::Color::Black, sf::Color::White);
	newGame.create("New Game", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 250,50 }, 24, sf::Color::Black, sf::Color::White);

	continueGame.setPosition({ 100, 170 });
	newGame.setPosition({ 100, 270 });
}

const bool MainMenuState::findSaveFile() const
{
	return static_cast<bool>(std::ifstream("game_save.txt"));
}

void MainMenuState::setNewGame()
{
	//states->push(new GameState(window, states, false));
	states->push(new GameState(windowSize, states, false));
}

void MainMenuState::loadGame()
{
	//states->push(new GameState(window, states, true));
	states->push(new GameState(windowSize, states, true));
}

void MainMenuState::update(float dt)
{
	continueGame.update(dt);
	newGame.update(dt);
}

void MainMenuState::render(sf::RenderWindow& window, sf::RenderStates states)
{
	window.draw(rect);
	window.draw(continueGame);
	window.draw(newGame);
}

void MainMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect);
	target.draw(continueGame);
	target.draw(newGame);
}

void MainMenuState::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
{
	continueGame.eventHandler(window, event, dt);
	newGame.eventHandler(window, event, dt);

	if (continueGame.getClicked() && findSaveFile())
	{
		loadGame();
	}
	if (newGame.getClicked())
	{
		setNewGame();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		states->push(new TitleScreenState(windowSize, states));
	}
}
