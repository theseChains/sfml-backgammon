#include "Board.hpp"

#include "Aliases.hpp"
#include "ChipColor.hpp"
#include "Constants.hpp"

Board::Board(const TextureHolder& textures)
    : m_firstPlayer{ ChipColor::white, textures },
      m_secondPlayer{ ChipColor::black, textures }
{
}

void Board::draw(sf::RenderWindow& window)
{
    // m_boardDrawer.drawBoard(stuff);
    drawPlayerChips(m_firstPlayer, window);
    drawPlayerChips(m_secondPlayer, window);
}

void Board::drawPlayerChips(const Player& player, sf::RenderWindow& window)
{
    PlayerChips playerChips{ player.getChips() };
    for (std::size_t i = 0; i < constants::numberOfChips; ++i)
        playerChips[i].draw(window);
}
