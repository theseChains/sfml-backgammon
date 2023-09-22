#include "Game.hpp"

int Game::GetSlotIndex(const sf::Event& event, sf::RenderWindow& window) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  // get slot_index
  for(int i = 0; i < constants::numberOfSlots; ++i){
    if (mousePosition.x >= slots[i].getXLeft() && mousePosition.x <= slots[i].getXLeft() + constants::SlotWidth && 
    mousePosition.y <= slots[i].getYTop() && mousePosition.y >= slots[i].getYTop() - constants::windowHeight && 
    event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
      return i;
    }
  }
  return -1;
}

bool Game::moveIsValid(int slotMovedFromIndex, int slotMovedToIndex) {
  bool ret = 0;
  if (slotMovedFromIndex + dice_1 == slotMovedToIndex && SlotsSameColor(slotMovedFromIndex, slotMovedToIndex)) ret = 1;
  else if(slotMovedFromIndex + dice_2 == slotMovedToIndex && SlotsSameColor(slotMovedFromIndex, slotMovedToIndex)) ret = 1;
  //одного цвета ячейка и промежуточные 2 и итоговая
  return ret;
}

bool Game::SlotsSameColor(int from_, int to_){
  return slots[from_].getChipColor() == slots[to_].getChipColor() 
  || slots[to_].getChipColor() == ChipColor::jopa_timura;
}

void Game::chooseChip(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn) {
  slot_index_take = GetSlotIndex(event, window);
}

void Game::handleChipMovement(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn) {
  slot_index_drop = GetSlotIndex(event, window);
  if (moveIsValid(slot_index_take, slot_index_drop)) {
    // moveChip();
  }
}

void Game::SlotInit() {
  for(int i = 0; i < constants::numberOfSlots; ++i){
    if (i < 6){
      slots[i].setBounds(160 + constants::SlotWidth * i, 1045 - constants::SlotHeight); 
    }
    else if(i >= 6 && i < 12) {
      slots[i].setBounds(1005 + constants::SlotWidth * (i - 6), 1045 - constants::SlotHeight); 
    }
    else if(i >= 12 && i < 18){
      slots[i].setBounds(1755 + constants::SlotWidth * (12 - i), 40);
    }
    else {
       slots[i].setBounds(920 + constants::SlotWidth * (18 - i), 40);
    }
    slots[i].setChipColor(ChipColor::jopa_timura);
    slots[i].setChipsCount(0);
  }
}

void Game::setDolbaeb(bool fl){
  is_timur = fl;
}

void Game::StartPosition(){
  slots[0].setChipColor(ChipColor::white);
  slots[0].setChipsCount(15);
  slots[12].setChipColor(ChipColor::black);
  slots[12].setChipsCount(15);
  ChangeHeight(0);
  ChangeHeight(12);
}

void Game::setDices(){
  if (is_timur){
    rnd.SmeshnoiRandom(dice_1, dice_2);
  }
  else {
    rnd.DefaultRandom(dice_1, dice_2);
  }
}

void Game::ChangeHeight(int slot_id){
  int chip_count = slots[slot_id].getChipsCount();
  slots[slot_id].setHeight(chip_count * constants::ChipDiam);
  if (slots[slot_id].getBounds().intersects(slots[23 - slot_id].getBounds())){
    int raznica = abs(slots[slot_id].getHeight() - slots[23 - slot_id].getHeight());
    slots[slot_id].setHeight(abs(slots[slot_id].getHeight() - raznica / 2));
    slots[23 - slot_id].setHeight(abs(slots[23 - slot_id].getHeight() - raznica / 2));
  }
}