#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "states/StateStack.hpp"
#include "ResourceHolder.hpp"

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
    void draw();
};

#endif
