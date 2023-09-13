#include "Application.hpp"

#include "Constants.hpp"

FontHolder initializeFonts()
{
    FontHolder fonts{};
    fonts.load(Fonts::ID::main, "../res/Hearty.otf");
    return fonts;
}

Application::Application()
    : m_window{ sf::VideoMode{ constants::windowWidth, constants::windowHeight }, "backgammon" },
      m_fonts{ initializeFonts() },
      m_board{ m_fonts, m_textures, m_window }
{
    // m_fonts.load(Fonts::ID::main, "../res/Hearty.otf");
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
    }
}

void Application::draw()
{
    m_window.clear();
    m_board.draw();
    m_window.display();
}
