#ifndef SLOT_HPP
#define SLOT_HPP

#include <SFML/Graphics.hpp>

#include "ChipColor.hpp"
#include "Constants.hpp"

class Slot
{
public:
    float getXLeft();
    float getYTop();
    float getHeight();
    sf::FloatRect getBounds();
    void setBounds(float x_left, float y_top);
    void setHeight(float height);
    int getChipsCount();
    void setChipsCount(int count);
    ChipColor getChipColor();
    void setChipColor(ChipColor color);
    void incrementChipCount();
    void decrementChipCount();

private:
    sf::FloatRect m_bounds;
    int m_chipCount;
    ChipColor m_chipColor;
};

#endif  //SLOT_HPP
