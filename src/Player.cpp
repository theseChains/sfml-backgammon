#include "Player.hpp"

#include "Constants.hpp"

Player::Player(ChipColor color, const TextureHolder& textures)
{
    if (color == ChipColor::white)
    {
        for (std::size_t i = 0; i < constants::numberOfChips; ++i)
            m_chips[i] = {
                { 120.0f, 855.0f - static_cast<int>(i) * constants::ChipDiam /
                                       constants::firstChipDistanceConstant },
                color,
                textures
            };
    }
    else if (color == ChipColor::black)
    {
        for (std::size_t i = 0; i < constants::numberOfChips; ++i)
            m_chips[i] = { { 1615.0f,
                             30.0f + static_cast<int>(i) * constants::ChipDiam /
                                         constants::firstChipDistanceConstant },
                           color,
                           textures };
    }
}

std::array<Chip, constants::numberOfChips>& Player::getChips()
{
    return m_chips;
}

const std::array<Chip, constants::numberOfChips>& Player::getChips() const
{
    return m_chips;
}
