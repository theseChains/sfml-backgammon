#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Chip.hpp"
#include "Constants.hpp"

#include <array>

class Player
{
public:
    Player(ChipColor color, const TextureHolder& textures);

    std::array<Chip, constants::numberOfChips>& getChips();
    const std::array<Chip, constants::numberOfChips>& getChips() const;

private:
    std::array<Chip, constants::numberOfChips> m_chips;
};

#endif
