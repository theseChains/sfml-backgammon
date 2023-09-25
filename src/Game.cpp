#include "Game.hpp"

Game::Game(const TextureHolder& textures)
{
  SlotInit();
  StartPosition(textures);
  dice_1 = dice_2 = dice_3 = dice_4 = 0;
  dubl = 0;
}

int Game::GetSlotIndex(const sf::Event& event, sf::RenderWindow& window) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  for(int i = 0; i < constants::numberOfSlots; ++i){
   std::cout << "slot x, w, y, h: " << slots[i].getXLeft() << ' ' << constants::SlotWidth + slots[i].getXLeft() <<
                ' ' << slots[i].getYTop() << ' ' << constants::SlotHeight + slots[i].getYTop() << '\n';
    if (slots[i].getBounds().contains(static_cast<sf::Vector2f>(mousePosition)) &&
    event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
      return i;
    }
  }
  return -1;
}

MoveCount Game::moveIsValid(int slotMovedFromIndex, int slotMovedToIndex, ChipColor color) {
  MoveCount ret = MoveCount::no_move;
  if(slotMovedFromIndex == slotMovedToIndex) return MoveCount::no_move;
  if(dubl && dice_1 == 0){
    dice_1 = dice_3;
    dice_3 = 0;
  }

  if(dubl && dice_2 == 0){
    dice_2 = dice_4;
    dice_4 = 0;
  }

  int slot_dice_1 = slotMovedToIndex - dice_1;
  int slot_dice_2 = slotMovedToIndex - dice_2;

  int slot_temp_3 = slotMovedToIndex - 2 * dice_1;// for ebanni dubl
  int slot_temp_4 = slotMovedToIndex - 3 * dice_1;// for ebanni dubl

  bool no_head_problem = 0;
  if (color == ChipColor::black) no_head_problem = !was_taken_from_head + 12 - slotMovedFromIndex;
  else no_head_problem = !was_taken_from_head + slotMovedFromIndex;

  bool are_to_and_from_same = SlotsSameColor(slotMovedFromIndex, slotMovedToIndex);
  //не дубль
  if ((slotMovedFromIndex + dice_1) % 24== slotMovedToIndex && are_to_and_from_same && no_head_problem){
    dice_1 = 0;
    ret = MoveCount::true_move;
  } 
  else if((slotMovedFromIndex + dice_2) % 24 == slotMovedToIndex && are_to_and_from_same && no_head_problem){
    dice_2 = 0;
    ret = MoveCount::true_move;
  }
  else if((slotMovedFromIndex + dice_1 + dice_2) % 24 == slotMovedToIndex &&
          are_to_and_from_same && (SlotsSameColor(slotMovedFromIndex, slot_dice_1)
          || SlotsSameColor(slotMovedFromIndex, slot_dice_2)) && no_head_problem){
    dice_1 = dice_2 = 0;
    ret = MoveCount::true_move;
  } 
  //дубль
  if(dubl) {
    if(slotMovedFromIndex + 3 * dice_1 == slotMovedToIndex && are_to_and_from_same && no_head_problem 
      && SlotsSameColor(slotMovedFromIndex, slot_dice_1) && SlotsSameColor(slotMovedFromIndex, slot_temp_3)){
      dice_1 = dice_2 = dice_3 = 0;
      ret = MoveCount::true_move;
    }
    if(slotMovedFromIndex + 4 * dice_1 == slotMovedToIndex && are_to_and_from_same && no_head_problem 
      && SlotsSameColor(slotMovedFromIndex, slot_dice_1) && SlotsSameColor(slotMovedFromIndex, slot_temp_3) 
      && SlotsSameColor(slotMovedFromIndex, slot_temp_4)){
      dice_1 = dice_2 = dice_3 = dice_4 = 0;
      ret = MoveCount::true_move;
    }
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

void Game::moveChip()
{
  std::cout << "moving a chip\n";
  Slot& slotToMoveFrom{ slots[slot_index_take] };
  Slot& slotToMoveTo{ slots[slot_index_drop] };
  Chip chipToMove{ slotToMoveFrom.popChip() };

  float slotHeight{ slotToMoveTo.getHeight() };
  // todo: update for slots that have chips already
  float slotToMoveToY{
      slots[slot_index_drop].getYTop() + slotHeight - constants::ChipDiam };
  float slotToMoveToX{ slots[slot_index_drop].getXLeft() };
  std::cout << "new coords: x y " << slotToMoveToX << ' ' << slotToMoveToY << '\n';
  chipToMove.setPosition({ slotToMoveToX, slotToMoveToY });
  slotToMoveTo.pushChip(chipToMove);
}

void Game::handleChipMovement(const sf::Event& event, sf::RenderWindow& window, PlayerTurn& turn) {
  slot_index_drop = GetSlotIndex(event, window);
  ChipColor color;
  if(turn == PlayerTurn::firstPlayerTurn) color = ChipColor::white;
  else color = ChipColor::black;
  if (slots[slot_index_take].getChipColor() != color){
    m_chipChooseState = true;
    m_moveState = false;
    return;
  } 
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

  if(!dice_1 && !dice_2 && !dice_3 && !dice_3){
    m_chipChooseState = false;
    m_moveState = false;
    m_diceThrowState = true;
    was_taken_from_head = false;
    dubl = false;
    turn = (turn == PlayerTurn::firstPlayerTurn ? PlayerTurn::secondPlayerTurn : PlayerTurn::firstPlayerTurn);
  }
  else {
    m_chipChooseState = true;
    m_moveState = false;
  }
}

void Game::SlotInit() {
  for(int i = 0; i < constants::numberOfSlots; ++i){
    if (i < 6){
      slots[i].setBounds(170 + constants::SlotWidth * i, 1045 - constants::SlotHeight); 
    }
    else if(i >= 6 && i < 12) {
      slots[i].setBounds(1005 + constants::SlotWidth * (i - 6), 1045 - constants::SlotHeight); 
    }
    else if(i >= 12 && i < 18){
      slots[i].setBounds(1630 + constants::SlotWidth * (12 - i), 40);
    }
    else {
       slots[i].setBounds(795 + constants::SlotWidth * (18 - i), 40);
    }
    slots[i].setChipColor(ChipColor::jopa_timura);
    slots[i].setChipsCount(0);
  }
}

void Game::setDolbaeb(bool fl){
  is_timur = fl;
}

void Game::StartPosition(const TextureHolder& textures){
  slots[0].setChipColor(ChipColor::white);
  slots[0].setChipsCount(15);
  slots[12].setChipColor(ChipColor::black);
  slots[12].setChipsCount(15);
  for (int i{ 0 }; i < constants::numberOfChips; ++i)
  {
    Chip whiteChip{ { 120.0f, 855.0f - static_cast<int>(i) *
                constants::ChipDiam /
                constants::firstChipDistanceConstant }, ChipColor::white, textures };
    slots[0].pushChip(whiteChip);
  }
  for (int i{ 0 }; i < constants::numberOfChips; ++i)
  {
    Chip blackChip{ { 1615.0f, 30.0f +
        static_cast<int>(i) * constants::ChipDiam /
          constants::firstChipDistanceConstant }, ChipColor::black, textures };
    slots[12].pushChip(blackChip);
  }
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
  if(dice_1 == dice_2){
    dubl = true;
    dice_3 = dice_1;
    dice_4 = dice_1;
  }
  m_diceThrowState = false;
  m_chipChooseState = true;
}

int Game::getDice1(){
  return dice_1;
}

int Game::getDice2(){
  return dice_2;
}

void Game::ChangeHeight(int slot_id){
  int chip_count = slots[slot_id].getChipsCount();
  if (slot_id < 12)
  {
    float heightDifference{
        static_cast<float>(std::abs(slots[slot_id].getHeight() -
            chip_count * 65.0)) };
    slots[slot_id].setYTop(slots[slot_id].getYTop() - heightDifference);
    slots[slot_id].setHeight(chip_count * 65.0);
  }
  else
  {
    slots[slot_id].setHeight(chip_count * 65.0);
  }

  std::cout << "slot id: " << slot_id << " height: " << slots[slot_id].getHeight() << '\n';
  if (slots[slot_id].getBounds().intersects(slots[23 - slot_id].getBounds())){
    int raznica = std::abs(slots[slot_id].getHeight() - slots[23 - slot_id].getHeight());
    std::cout << "slot id: " << slot_id << " difference: " << raznica << '\n';
    if (slot_id < 12)
    {
      slots[slot_id].setYTop(slots[slot_id].getYTop() + raznica / 2);
      slots[slot_id].setHeight(slots[slot_id].getHeight() - raznica / 2);
      slots[23 - slot_id].setHeight(slots[23 - slot_id].getHeight() - raznica / 2);
    }
    else
    {
      slots[slot_id].setHeight(slots[slot_id].getHeight() - raznica / 2);
      slots[23 - slot_id].setYTop(slots[23 - slot_id].getYTop() + raznica / 2);
      slots[23 - slot_id].setHeight(slots[23 - slot_id].getHeight() - raznica / 2);
    }
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

void Game::draw(sf::RenderWindow& window)
{
  for (auto& slot : slots)
  {
    slot.drawChips(window);
  }

  drawBounds(window);
}

void Game::drawBounds(sf::RenderWindow& window)
{
  for (int i{ 0 }; i < constants::numberOfSlots; ++i)
  {
    slots[i].drawSlotBounds(window, i);
  }
}
