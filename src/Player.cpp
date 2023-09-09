#include "Player.hpp"

#include "Constants.hpp"

Player::Player(ChipColor color, const TextureHolder& textures)
{
    // todo: implement position based on chip color
    for (std::size_t i = 0; i < constants::numberOfChips; ++i)
        m_chips[i] = { { 0.0f, constants::chipDiameter * static_cast<float>(i) }, color, textures };
}

std::array<Chip, constants::numberOfChips>& Player::getChips()
{
    return m_chips;
}

const std::array<Chip, constants::numberOfChips>& Player::getChips() const
{
    return m_chips;
}
