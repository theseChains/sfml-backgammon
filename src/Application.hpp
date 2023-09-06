#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

class Application
{
public:
    Application();

    void run();

private:
    sf::RenderWindow m_window{};

    void processInput();
    void draw();
};

#endif
