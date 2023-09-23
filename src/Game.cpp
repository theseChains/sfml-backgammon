#include "Game.hpp"

Game::Game()
{
  SlotInit();
}

int Game::GetSlotIndex(const sf::Event& event, sf::RenderWindow& window) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  // get slot_index
  //std::cout << "xx, yy: " << sf::Mouse::getPosition(window).x << ' ' <<
               // sf::Mouse::getPosition(window).y << '\n';
  for(int i = 0; i < constants::numberOfSlots; ++i){
   // std::cout << "slot x, w, y, h: " << slots[i].getXLeft() << ' ' << constants::SlotWidth + slots[i].getXLeft() <<
                // ' ' << slots[i].getYTop() << ' ' << constants::SlotHeight + slots[i].getYTop() << '\n';
    if (slots[i].getBounds().contains(static_cast<sf::Vector2f>(mousePosition)) &&
    event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
      return i;
    }
  }
  return -1;
}

MoveCount Game::moveIsValid(int slotMovedFromIndex, int slotMovedToIndex, ChipColor color) {
  MoveCount ret = MoveCount::no_move;
  
  int slot_dice_1 = slotMovedToIndex - dice_1;
  int slot_temp_1_1 = slot_dice_1 - dice_2;

  int slot_dice_2 = slotMovedToIndex - dice_2;
  int slot_temp_1_2 = slot_dice_2 - dice_1;

  int slot_temp_2 = slot_temp_1_1 - dice_1;
  int slot_temp_3 = slot_temp_2 - dice_1;

  bool no_head_problem = 0;
  if (color == ChipColor::black) no_head_problem = !was_taken_from_head + 12 - slotMovedFromIndex;
  else no_head_problem = !was_taken_from_head + slotMovedFromIndex;

  bool are_to_and_from_same = SlotsSameColor(slotMovedFromIndex, slotMovedToIndex);
  //не дубль
    if (slotMovedFromIndex + dice_1 == slotMovedToIndex && are_to_and_from_same && no_head_problem) ret = MoveCount::first_move;
    else if(slotMovedFromIndex + dice_2 == slotMovedToIndex && are_to_and_from_same && no_head_problem) ret = MoveCount::first_move;
    else if(slotMovedFromIndex + dice_1 + dice_2 == slotMovedFromIndex &&
            are_to_and_from_same && (SlotsSameColor(slotMovedFromIndex, slot_dice_1) && SlotsSameColor(slotMovedFromIndex, slot_temp_1_1) ||
            SlotsSameColor(slotMovedFromIndex, slot_dice_2) && SlotsSameColor(slotMovedFromIndex, slot_temp_1_2)) &&
            (stop_move == 0 || dice_1 == dice_2 && (stop_move == 1 || stop_move == 2))) ret = MoveCount::second_move;
  //дубль
  if(dice_1 == dice_2) {
    if(slotMovedFromIndex + 3 * dice_1 == slotMovedToIndex && are_to_and_from_same && no_head_problem 
    && SlotsSameColor(slotMovedFromIndex, slot_dice_1) && SlotsSameColor(slotMovedFromIndex, slot_temp_1_1) 
    && SlotsSameColor(slotMovedFromIndex, slot_temp_2) && (stop_move == 0 || stop_move == 1)) ret = MoveCount::third_move;
    else if(slotMovedFromIndex + 4 * dice_1 == slotMovedToIndex && are_to_and_from_same && no_head_problem 
    && SlotsSameColor(slotMovedFromIndex, slot_dice_1) && SlotsSameColor(slotMovedFromIndex, slot_temp_1_1) 
    && SlotsSameColor(slotMovedFromIndex, slot_temp_2) && SlotsSameColor(slotMovedFromIndex, slot_temp_3) && stop_move == 0) ret = MoveCount::last_move;
  }

  if(ret != MoveCount::no_move && (slotMovedFromIndex == 0 && color == ChipColor::white ||
      slotMovedFromIndex == 12 && color == ChipColor::black)) was_taken_from_head = true;
  return ret;
}

bool Game::SlotsSameColor(int from_, int to_){
  return slots[from_].getChipColor() == slots[to_].getChipColor() 
  || slots[to_].getChipColor() == ChipColor::jopa_timura;
}

void Game::chooseChip(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn) {
  slot_index_take = GetSlotIndex(event, window);
  std::cout << "chosen slot index: " << slot_index_take << '\n';
  if(slot_index_take != -1) {
    m_chipChooseState = false;
    m_moveState = true;
  }
}

void Game::handleChipMovement(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn) {
  slot_index_drop = GetSlotIndex(event, window);
  ChipColor color;
  if(turn == PlayerTurn::firstPlayerTurn) color = ChipColor::white;
  else color = ChipColor::black;
  if (slots[slot_index_take].getChipColor() != color) return;
  MoveCount temp = moveIsValid(slot_index_take, slot_index_drop, color); 
  if (temp != MoveCount::no_move) {
    // moveChip();
    slots[slot_index_drop].setChipColor(slots[slot_index_take].getChipColor());
    slots[slot_index_drop].incrementChipCount();
    slots[slot_index_take].decrementChipCount();
    if (slots[slot_index_take].getChipsCount() == 0) {
      slots[slot_index_take].setChipColor(ChipColor::jopa_timura);
    }
    ChangeHeight(slot_index_drop);
    ChangeHeight(slot_index_take);
  }
  if(temp == MoveCount::first_move) stop_move += 1;
  else if(temp == MoveCount::second_move) stop_move += 2;
  else if(temp == MoveCount::third_move) stop_move += 3;
  else if(temp == MoveCount::last_move) stop_move += 4;

  if(stop_move == 1 || dice_1 == dice_2 && (stop_move == 2 || stop_move == 3)){
    m_chipChooseState = true;
    m_moveState = false;
  }
  else if(stop_move == 2 && dice_1 != dice_2 || stop_move == 4){
    m_chipChooseState = false;
    m_moveState = false;
    m_diceThrowState = true;
    stop_move = 0;
    was_taken_from_head = false;
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
  m_diceThrowState = false;
  m_chipChooseState = true;
  std::cout << "dice 1: " << dice_1 << " dice_2: " << dice_2 << '\n';
}

int Game::getDice1(){
  return dice_1;
}

int Game::getDice2(){
  return dice_2;
}

void Game::ChangeHeight(int slot_id){
  int chip_count = slots[slot_id].getChipsCount();
  slots[slot_id].setHeight(chip_count * 65.0);
  if (slots[slot_id].getBounds().intersects(slots[23 - slot_id].getBounds())){
    int raznica = abs(slots[slot_id].getHeight() - slots[23 - slot_id].getHeight());
    slots[slot_id].setHeight(abs(slots[slot_id].getHeight() - raznica / 2));
    slots[23 - slot_id].setHeight(abs(slots[23 - slot_id].getHeight() - raznica / 2));
  }
}

bool Game::isMoveState() const
{
  return m_moveState;
}

bool Game::isDiceThrowState() const
{
  return m_diceThrowState;
}

bool Game::isChipChooseState() const
{
  return m_chipChooseState;
}

void Game::setMoveState(bool moveState)
{
  m_moveState = moveState;
}

void Game::setDiceThrowState(bool diceThrowState)
{
  m_diceThrowState = diceThrowState;
}

void Game::setChipChooseState(bool chipChooseState)
{
  m_chipChooseState = chipChooseState;
}
