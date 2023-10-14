#include "Board.hpp"

#include <iostream>
#include <stdbool.h>
#include <string>

#include "Aliases.hpp"
#include "ChipColor.hpp"
#include "Constants.hpp"

Button initializeFirstPlayerButton(sf::Font& font)
{
    sf::Vector2f buttonPosition{ 45.0f, 500.0f };
    sf::Vector2f buttonSize{ 75.0f, 80.0f };
    sf::Vector2f buttonTextPosition{ buttonPosition.x + 10.0f,
                                     buttonPosition.y + 10.0f };
    ButtonTextInfo textInfo{ 20, "throw\ndice", buttonTextPosition,
                             sf::Color::White };
    ButtonInfo info{ buttonPosition, buttonSize, sf::Color::Transparent, textInfo };
    Button button{ info, font };

    return button;
}

Button initializeSecondPlayerButton(sf::Font& font)
{
    sf::Vector2f buttonPosition{ 1800.0f, 500.0f };
    sf::Vector2f buttonSize{ 75.0f, 80.0f };
    sf::Vector2f buttonTextPosition{ buttonPosition.x + 10.0f,
                                     buttonPosition.y + 10.0f };
    ButtonTextInfo textInfo{ 20, "throw\ndice", buttonTextPosition,
                             sf::Color::White };
    ButtonInfo info{ buttonPosition, buttonSize, sf::Color::Transparent, textInfo };
    Button button{ info, font };

    return button;
}

std::pair<sf::Sprite, sf::Sprite>
initializeFirstPlayerDices(TextureHolder& textures)
{
    std::pair<sf::Sprite, sf::Sprite> dices{};

    dices.first.setPosition(15.0f, 510.0f);
    dices.first.setTexture(textures.get(Textures::ID::diceOne));
    dices.second.setPosition(80.0f, 510.0f);
    dices.second.setTexture(textures.get(Textures::ID::diceTwo));

    return dices;
}

std::pair<sf::Sprite, sf::Sprite>
initializeSecondPlayerDices(TextureHolder& textures)
{
    std::pair<sf::Sprite, sf::Sprite> dices{};

    dices.first.setPosition(1770.0f, 510.0f);
    dices.first.setTexture(textures.get(Textures::ID::diceOne));
    dices.second.setPosition(1835.0f, 510.0f);
    dices.second.setTexture(textures.get(Textures::ID::diceTwo));

    return dices;
}

Board::Board(sf::Font& font, TextureHolder& textures, sf::RenderWindow& window)
    : m_window{ window },
      m_firstPlayerButton{ initializeFirstPlayerButton(font) },
      m_secondPlayerButton{ initializeSecondPlayerButton(font) },
      m_sprite{ textures.get(Textures::ID::board) },
      m_textures{ textures },
      m_playerTurn{ PlayerTurn::firstPlayerTurn },
      m_game{ textures },
      m_firstPlayerDices{ initializeFirstPlayerDices(textures) },
      m_secondPlayerDices{ initializeSecondPlayerDices(textures) },
      m_showDices{ false }
{
}

void Board::handleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::MouseButtonPressed)
        return;
    if (m_playerTurn == PlayerTurn::firstPlayerTurn &&
        m_game.isDiceThrowState())
    {
        std::cout << "first player throwing\n";
        m_game.setDolbaeb(false);
        if (m_firstPlayerButton.isClicked(event, m_window))
        {
            m_game.setDices();
            m_showDices = true;
            int firstDice{ m_game.getDice1() };
            int secondDice{ m_game.getDice2() };
            m_firstPlayerDices.first.setTexture(
                    m_textures.get(constants::textureMap[firstDice]));
            m_firstPlayerDices.second.setTexture(
                    m_textures.get(constants::textureMap[secondDice]));
        }
    }
    else if (m_playerTurn == PlayerTurn::secondPlayerTurn &&
             m_game.isDiceThrowState())
    {
        std::cout << "second player throwing\n";
        m_game.setDolbaeb(true);
        if (m_secondPlayerButton.isClicked(event, m_window))
        {
            m_showDices = true;
            m_game.setDices();
            int firstDice{ m_game.getDice1() };
            int secondDice{ m_game.getDice2() };
            m_secondPlayerDices.first.setTexture(
                    m_textures.get(constants::textureMap[firstDice]));
            m_secondPlayerDices.second.setTexture(
                    m_textures.get(constants::textureMap[secondDice]));
        }
    }
    else if (m_playerTurn == PlayerTurn::firstPlayerTurn &&
             m_game.isChipChooseState())
    {
        std::cout << "first player choosing chips\n";
        m_game.chooseChip(event, m_window);
    }
    else if (m_playerTurn == PlayerTurn::secondPlayerTurn &&
             m_game.isChipChooseState())
    {
        std::cout << "second player choosing chips\n";
        m_game.chooseChip(event, m_window);
    }
    else if (m_playerTurn == PlayerTurn::firstPlayerTurn &&
             m_game.isMoveState())
    {
        std::cout << "first player choosing chips\n";
        m_game.handleChipMovement(event, m_window, m_playerTurn);
    }
    else if (m_playerTurn == PlayerTurn::secondPlayerTurn &&
             m_game.isMoveState())
    {
        std::cout << "second player choosing chips\n";
        m_game.handleChipMovement(event, m_window, m_playerTurn);
    }
}

void Board::update()
{
    if (!m_game.CheckMoves(m_playerTurn))
        m_showDices = false;
}

void Board::draw()
{
    m_window.draw(m_sprite);
    m_firstPlayerButton.draw(m_window);
    m_secondPlayerButton.draw(m_window);
    if (m_showDices && m_playerTurn == PlayerTurn::firstPlayerTurn)
    {
        m_window.draw(m_firstPlayerDices.first);
        m_window.draw(m_firstPlayerDices.second);
    }
    else if (m_showDices && m_playerTurn == PlayerTurn::secondPlayerTurn)
    {
        m_window.draw(m_secondPlayerDices.first);
        m_window.draw(m_secondPlayerDices.second);
    }
    m_game.draw(m_window);
}
