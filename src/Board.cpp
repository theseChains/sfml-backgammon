#include "Board.hpp"

#include <iostream>
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
                             sf::Color::Black };
    ButtonInfo info{ buttonPosition, buttonSize, sf::Color::White, textInfo };
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
                             sf::Color::Black };
    ButtonInfo info{ buttonPosition, buttonSize, sf::Color::White, textInfo };
    Button button{ info, font };

    return button;
}

Board::Board(sf::Font& font, TextureHolder& textures, sf::RenderWindow& window)
    : m_window{ window },
      m_firstPlayerButton{ initializeFirstPlayerButton(font) },
      m_secondPlayerButton{ initializeSecondPlayerButton(font) },
      m_sprite{ textures.get(Textures::ID::board) },
      m_playerTurn{ PlayerTurn::firstPlayerTurn },
      m_game{ textures }
{
}

void Board::handleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::MouseButtonPressed)
        return;

    if (m_playerTurn == PlayerTurn::firstPlayerTurn &&
        m_game.isDiceThrowState())
    {
        m_game.setDolbaeb(false);
        if (m_firstPlayerButton.isClicked(event, m_window))
        {
            // std::cout << "first player threw: ";
            m_game.setDices();
            std::string str = std::to_string(m_game.getDice1()) + ' ' +
                              std::to_string(m_game.getDice2());
            m_firstPlayerButton.setText(str);
        }
    }
    else if (m_playerTurn == PlayerTurn::secondPlayerTurn &&
             m_game.isDiceThrowState())
    {
        m_game.setDolbaeb(true);
        if (m_secondPlayerButton.isClicked(event, m_window))
        {
            m_game.setDices();
            std::string str = std::to_string(m_game.getDice1()) + ' ' +
                              std::to_string(m_game.getDice2());
            m_secondPlayerButton.setText(str);
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
        m_game.chooseChip(event, m_window);
    else if (m_playerTurn == PlayerTurn::firstPlayerTurn &&
             m_game.isMoveState())
    {
        std::cout << "first player move chips\n";
        m_game.handleChipMovement(event, m_window, m_playerTurn);
    }
    else if (m_playerTurn == PlayerTurn::secondPlayerTurn &&
             m_game.isMoveState())
        m_game.handleChipMovement(event, m_window, m_playerTurn);
}

void Board::draw()
{
    m_window.draw(m_sprite);
    m_firstPlayerButton.draw(m_window);
    m_secondPlayerButton.draw(m_window);
    m_game.draw(m_window);
}
