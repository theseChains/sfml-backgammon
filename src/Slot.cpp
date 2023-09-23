#include "Slot.hpp"

float Slot::getXLeft(){
  return m_bounds.left;
}

float Slot::getYTop(){
  return m_bounds.top;
}

sf::FloatRect Slot::getBounds(){
  return m_bounds;
}
 
float Slot::getHeight(){
  return m_bounds.height;
}

void Slot::setBounds(float x_left, float y_top){
  m_bounds.left = x_left;
  m_bounds.width = constants::SlotWidth;
  m_bounds.top = y_top;
  m_bounds.height = constants::SlotHeight;
}

void Slot::setHeight(float height){
  m_bounds.height = height;
}

int Slot::getChipsCount(){
  return m_chipCount;
}

void Slot::setChipsCount(int count){
  m_chipCount = count;
}

ChipColor Slot::getChipColor(){
  return m_chipColor;
}

void Slot::setChipColor(ChipColor color){
  m_chipColor = color;
}

void Slot::incrementChipCount() {
  ++m_chipCount;
}

void Slot::decrementChipCount() {
  --m_chipCount;
}
