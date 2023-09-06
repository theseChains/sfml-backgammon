#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

#include "Chip.hpp"

class Board
{
public:
    Board() = default;

private:
    std::array<Chip, 15> m_firstPlayerChips{};
    std::array<Chip, 15> m_secondPlayerChips{};
};

#endif
