#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

#include "Player.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class Board
{
public:
    Board(const TextureHolder& textures);

    void draw(sf::RenderWindow& window);

private:
    Player m_firstPlayer;
    Player m_secondPlayer;

    void drawPlayerChips(const Player& player, sf::RenderWindow& window);
};

#endif
