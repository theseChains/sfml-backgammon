#include "Application.hpp"

#include "Constants.hpp"

Application::Application()
    : m_window{ sf::VideoMode{ constants::windowWidth, constants::windowHeight }, "backgammon" }
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

    for (int i{ 0 }; i < 15; ++i)
    {
        sf::CircleShape circle{ constants::chipRadius };
        circle.setPosition(0.0f, 50.0f * static_cast<float>(i));
        circle.setFillColor(sf::Color::Cyan);
        m_window.draw(circle);
    }

    m_window.display();
}
