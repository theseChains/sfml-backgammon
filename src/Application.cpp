#include "Application.hpp"

Application::Application()
    : m_window{ sf::VideoMode{ 500, 500 }, "backgammon" }
{}

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
    m_window.display();
}
