#ifndef SLOT_HPP
#define SLOT_HPP

#include <SFML/Graphics.hpp>

#include "ChipColor.hpp"

class Slot
{
public:
    Slot(int index);

    void incrementChipCount();
    void decrementChipCount();

private:
    sf::FloatRect m_bounds;
    int m_chipCount;
    ChipColor m_chipColor;
};

#endif
