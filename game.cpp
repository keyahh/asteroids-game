#include "Game.h"

Game::Game()
{
    assert(font.loadFromFile("opensans.ttf"));

    out.open("game_save.txt", std::ios::app);

    window.create(sf::VideoMode(800, 600, 32), "Pokemon");
    window.setFramerateLimit(60);

    //states.push(new GameState(&window, &states));
    states.push(new MainMenuState(&window, &states, &font));
    states.push(new TitleScreenState(&window, &states, &font));
}

Game::Game(const Game& game)
{
    *this = game;
}

Game::Game(sf::RenderWindow* window)
{
}


void Game::eventHandler()
{
    while (window.pollEvent(Game::event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{
    dt = clock.restart().asSeconds();
    eventHandler();
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
    window.clear();
    
    if (!states.empty())
    {
        states.top()->render(&window);//states are pointers
    }

    window.display();
}

void Game::run()
{
    while (window.isOpen()) 
    {
        update();
        render();
    }

}

void Game::closeGame()
{
    window.close();
}

Game& Game::operator=(const Game& game)
{
    //this->window = game.window;
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