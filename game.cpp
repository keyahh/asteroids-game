#include "Game.h"

Game::Game()
{
    out.open("game_save.txt", std::ios::app);
}

Game::Game(const Game& game)
{
    *this = game;
}

Game::Game(sf::RenderWindow* window)
{
    Game::window = window;
    out.open("game_save.txt", std::ios::app);

    states.push(new MainMenuState((sf::Vector2f)window->getSize(), &states));
    states.push(new TitleScreenState((sf::Vector2f)window->getSize(), &states));
}


void Game::eventHandler(sf::RenderWindow& window, sf::Event event, float dt)
{
    states.top()->eventHandler(window, event, dt);
}

void Game::update(float dt)
{
    //dt = clock.restart().asSeconds();

    //eventHandler(*window, event, dt);

    if (!states.empty())
    {
        states.top()->update(dt);
        if (states.top()->getClose())
        {
            states.top()->close();
            delete states.top();
            states.pop();
        }
    }
    else
    {
        closeGame();
    }
}

void Game::render()
{
    window->clear();
    
    if (!states.empty())
    {
        //states.top()->render(*window, renderStates);
        window->draw(*states.top());
    }

    window->display();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!this->states.empty())
    {
        //states.top()->render(*window, renderStates);
        target.draw(*(this->states).top());
    }
}

void Game::run()
{
    /*while (window->isOpen()) 
    {
        update();
        render();
    }*/

}

void Game::closeGame()
{
    window->close();
}

Game& Game::operator=(const Game& game)
{
    this->window = game.window;
    this->states = game.states;
    return *this;
}

Game::~Game()
{
    while (!states.empty())
    {
        states.top()->close();
        delete states.top();
        states.pop();
    }
}