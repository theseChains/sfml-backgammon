#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "Board.hpp"
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
    Board m_board;

    void processInput();
    void draw();
};

#endif
