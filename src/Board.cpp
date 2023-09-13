#include "Board.hpp"

#include "Aliases.hpp"
#include "ChipColor.hpp"
#include "Constants.hpp"

#include <iostream>

Button initializePlayerButton(sf::Font& font)
{
    ButtonTextInfo textInfo{ 10, "text", { 40.0f, 40.0f }, sf::Color::Magenta };
    ButtonInfo info{ { 30.0f, 30.0f }, { 100.0f, 100.0f }, sf::Color::Cyan, textInfo };
    Button button{ info, font };

    return button;
}

Board::Board(sf::Font& font, const TextureHolder& textures, sf::RenderWindow& window)
    : m_window{ window },
      m_firstPlayerButton{ initializePlayerButton(font) },
      m_firstPlayer{ ChipColor::white, textures },
      m_secondPlayer{ ChipColor::black, textures },
      m_playerTurn{ PlayerTurn::firstPlayerTurn },
      m_moveState{ false }
{
}

void Board::handleButtonClick(const sf::Event& event, Button& button)
{
    if (button.isClicked(event, m_window))
    {
        std::cout << "clicked!";
        // std::pair<int, int> dicePoints{ throwDice() };
        // m_moveState = true;
    }
}

void handleChipMove()
{

}

void Board::handleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::MouseButtonPressed)
        return;

    if (m_playerTurn == PlayerTurn::firstPlayerTurn && !m_moveState)
        handleButtonClick(event, m_firstPlayerButton);
    else if (m_playerTurn == PlayerTurn::secondPlayerTurn && !m_moveState)
        handleButtonClick(event, m_secondPlayerButton);
    else
        handleChipMove();
}

void Board::draw()
{
    // m_boardDrawer.drawBoard(stuff);
    m_firstPlayerButton.draw(m_window);
    // drawPlayerChips(m_firstPlayer, m_window);
    // drawPlayerChips(m_secondPlayer, m_window);
}

void Board::drawPlayerChips(const Player& player, sf::RenderWindow& window)
{
    PlayerChips playerChips{ player.getChips() };
    for (std::size_t i = 0; i < constants::numberOfChips; ++i)
        playerChips[i].draw(window);
}
