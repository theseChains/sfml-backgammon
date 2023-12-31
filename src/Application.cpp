#include "Application.hpp"

#include <iostream>

#include "Constants.hpp"

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
    textures.load(Textures::ID::blackChip, "../res/blackChip.png");
    textures.load(Textures::ID::board, "../res/board.png");
    textures.load(Textures::ID::diceOne, "../res/diceOne.png");
    textures.load(Textures::ID::diceTwo, "../res/diceTwo.png");
    textures.load(Textures::ID::diceThree, "../res/diceThree.png");
    textures.load(Textures::ID::diceFour, "../res/diceFour.png");
    textures.load(Textures::ID::diceFive, "../res/diceFive.png");
    textures.load(Textures::ID::diceSix, "../res/diceSix.png");

    return textures;
}

Application::Application()
    : m_window{ sf::VideoMode{ constants::windowWidth,
                               constants::windowHeight },
                "backgammon", sf::Style::Fullscreen },
      m_textures{ initializeTextures() },
      m_fonts{ initializeFonts() },
      m_stateStack{ State::Context{ m_window, m_textures, m_fonts } }
{
    m_window.setVerticalSyncEnabled(true);

    m_stateStack.createState(States::ID::menu);
    m_stateStack.createState(States::ID::game);

    m_stateStack.pushState(States::ID::menu);
}

void Application::run()
{
    while (m_window.isOpen())
    {
        processInput();
        update();
        draw();
    }
}

void Application::update()
{
    m_stateStack.update();
}

void Application::processInput()
{
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape)
            m_window.close();

        if (event.type == sf::Event::Closed)
            m_window.close();

        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "x, y: " << sf::Mouse::getPosition(m_window).x << ' ' << sf::Mouse::getPosition(m_window).y << '\n';
        }

        m_stateStack.handleEvent(event);
    }
}

void Application::draw()
{
    m_window.clear();
    m_stateStack.draw();
    m_window.display();
}
