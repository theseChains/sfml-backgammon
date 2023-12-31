#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"
#include "states/StateStack.hpp"

class Application
{
public:
    Application();

    void run();

private:
    sf::RenderWindow m_window;
    TextureHolder m_textures;
    FontHolder m_fonts;
    StateStack m_stateStack;

    void processInput();
    void update();
    void draw();
};

#endif
