#include "Application.hpp"

#include "Constants.hpp"

#include <iostream>

FontHolder initializeFonts()
{
    FontHolder fonts{};
    fonts.load(Fonts::ID::main, "../res/jopa.ttf");
    return fonts;
}

TextureHolder initializeTextures()
{
    TextureHolder textures{};
    textures.load(Textures::ID::whiteChip, "../res/whiteChip.png");
    textures.load(Textures::ID::board, "../res/board.png");
    return textures;
}

Application::Application()
    : m_window{ sf::VideoMode{ constants::windowWidth, constants::windowHeight }, "backgammon", sf::Style::Fullscreen },
      m_textures{ initializeTextures() },
      m_fonts{ initializeFonts() },
      m_board{ m_fonts.get(Fonts::ID::main), m_textures, m_window }
{
    // todo: initialize textures and fonts
    // also todo: states for menu and game states
}

void Application::run()
{
    while (m_window.isOpen())
    {
        processInput();
        draw();
    }
}

void Application::processInput()
{
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            m_window.close();

        if (event.type == sf::Event::Closed)
            m_window.close();

        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "x, y: " << sf::Mouse::getPosition().x << ' ' <<
                sf::Mouse::getPosition().y << '\n';
        }

        m_board.handleEvent(event);
    }
}

void Application::draw()
{
    m_window.clear();
    m_board.draw();
    m_window.display();
}
