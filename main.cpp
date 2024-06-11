#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Asteroids");

    Game game(&window);
    sf::Clock clock;
    sf::Event event;
    float dt;

    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            game.eventHandler(window, event, dt);
        }
        window.clear();
        window.draw(game);
        game.update(dt);
        window.display();
    }
    return 0;
}

