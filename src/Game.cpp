#include "Game.hpp"

Game::Game(TextureHolder& textures) : m_textures{ textures }
{
    SlotInit();
    StartPosition(m_textures);
    dice_1 = dice_2 = dice_3 = dice_4 = 0;
    dubl = 0;
}

int Game::GetSlotIndex(const sf::Event& event, sf::RenderWindow& window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    for (int i = 0; i < constants::numberOfSlots + 2; ++i)
    {
        // std::cout << "slot x, w, y, h: " << slots[i].getXLeft() << ' ' <<
        // constants::SlotWidth + slots[i].getXLeft() << ' ' <<
        // slots[i].getYTop() << ' ' << constants::SlotHeight +
        // slots[i].getYTop() << '\n';
        if (slots[i].getBounds().contains(
                static_cast<sf::Vector2f>(mousePosition)) &&
            event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left)
        {
            return i;
        }
    }
    return -1;
}

MoveCount Game::moveIsValid(int slotMovedFromIndex, int slotMovedToIndex,
                            ChipColor color)
{
    MoveCount ret = MoveCount::no_move;

    if (slotMovedFromIndex == slotMovedToIndex)
        return ret;
    if(chipAtHome(color, slotMovedFromIndex) &&
       !SecondRound(color, abs(slotMovedFromIndex - slotMovedToIndex), slotMovedFromIndex))
        return ret;
    if (dubl && dice_1 == 0)
    {
        dice_1 = dice_3;
        dice_3 = 0;
    }

    if (dubl && dice_2 == 0)
    {
        dice_2 = dice_4;
        dice_4 = 0;
    }

    int slot_dice_1 = (24 + slotMovedToIndex - dice_1) % 24;
    int slot_dice_2 = (24 + slotMovedToIndex - dice_2) % 24;

    int slot_temp_3 = slotMovedToIndex - 2 * dice_1;  // for ebanni dubl
    int slot_temp_4 = slotMovedToIndex - 3 * dice_1;  // for ebanni dubl

    int no_head_problem = 0;

    bool six =
        SexChips(slotMovedToIndex, slotMovedFromIndex, slots[slotMovedFromIndex].getChipColor());

    if (color == ChipColor::black)
        no_head_problem = !was_taken_from_head + abs(12 - slotMovedFromIndex);
    else
        no_head_problem = !was_taken_from_head + slotMovedFromIndex;

    bool home_state = home(color);

    bool are_to_and_from_same =
        SlotsSameColor(slotMovedFromIndex, slotMovedToIndex);
    //не дубль
    if ((slotMovedFromIndex + dice_1) % 24 == slotMovedToIndex &&
        are_to_and_from_same && no_head_problem && six)
    {
        dice_1 = 0;
        ret = MoveCount::true_move;
    }
    else if ((slotMovedFromIndex + dice_2) % 24 == slotMovedToIndex &&
             are_to_and_from_same && no_head_problem && six)
    {
        dice_2 = 0;
        ret = MoveCount::true_move;
    }
    else if ((slotMovedFromIndex + dice_1 + dice_2) % 24 == slotMovedToIndex &&
             are_to_and_from_same &&
             (SlotsSameColor(slotMovedFromIndex, slot_dice_1) ||
              SlotsSameColor(slotMovedFromIndex, slot_dice_2)) &&
             no_head_problem && six)
    {
        dice_1 = dice_2 = 0;
        ret = MoveCount::true_move;
    }
    //дубль
    if (dubl)
    {
        if (slotMovedFromIndex + 3 * dice_1 == slotMovedToIndex &&
            are_to_and_from_same && no_head_problem &&
            SlotsSameColor(slotMovedFromIndex, slot_dice_1) &&
            SlotsSameColor(slotMovedFromIndex, slot_temp_3) && six)
        {
            dice_1 = dice_2 = dice_3 = 0;
            ret = MoveCount::true_move;
        }
        if (slotMovedFromIndex + 4 * dice_1 == slotMovedToIndex &&
            are_to_and_from_same && no_head_problem &&
            SlotsSameColor(slotMovedFromIndex, slot_dice_1) &&
            SlotsSameColor(slotMovedFromIndex, slot_temp_3) &&
            SlotsSameColor(slotMovedFromIndex, slot_temp_4) && six)
        {
            dice_1 = dice_2 = dice_3 = dice_4 = 0;
            ret = MoveCount::true_move;
        }
    }

    if (ret != MoveCount::no_move &&
        ((slotMovedFromIndex == 0 && color == ChipColor::white) ||
         (slotMovedFromIndex == 12 && color == ChipColor::black)))
    {
        was_taken_from_head = true;
    }

    return ret;
}

bool Game::SlotsSameColor(int from_, int to_)
{
    return slots[from_].getChipColor() == slots[to_].getChipColor() ||
           slots[to_].getChipColor() == ChipColor::jopa_timura;
}

void Game::chooseChip(const sf::Event& event, sf::RenderWindow& window, ChipColor color)
{
    slot_index_take = GetSlotIndex(event, window);
    // should do a fix here i think 
    if (slot_index_take != -1 && slots[slot_index_take].getChipColor() == color)
    {
        m_chipChooseState = false;
        m_moveState = true;
    }
}

bool Game::SexChips(int slotMovedToIndex, int slotMovedFromIndex, ChipColor col)
{
    int n = 1;
    int count = 0;
    while (true)
    {
        if (slots[(24 + slotMovedToIndex - n) % 24].getChipColor() != col ||
            (col == ChipColor::black && (24 + slotMovedToIndex - n) % 24 == 23) ||
            (col == ChipColor::white && (24 + slotMovedToIndex - n) % 24 == 11))
            break;
        if ((24 + slotMovedToIndex - n) % 24 != slotMovedFromIndex ||
           ((24 + slotMovedToIndex - n) % 24 == slotMovedFromIndex &&
            slots[slotMovedFromIndex].getChipsCount() > 1))
            count++;
        n++;
    }
    n = 1;
    while (true)
    {
        if (slots[(slotMovedToIndex + n) % 24].getChipColor() != col ||
            (col == ChipColor::black && (slotMovedToIndex + n) % 24 == 0) ||
            (col == ChipColor::white && (slotMovedToIndex + n) % 24 == 12))
            break;
        if ((slotMovedToIndex + n) % 24 != slotMovedFromIndex ||
           ((slotMovedToIndex + n) % 24 == slotMovedFromIndex &&
            slots[slotMovedFromIndex].getChipsCount() > 1))
            count++;
        n++;
    }

    bool has_chip_at_home = 0;
    if (col == ChipColor::black)
    {
        for (int i = 18; i <= 23; i++)
        {
            if (slots[i].getChipColor() == ChipColor::white) {
                has_chip_at_home = 1;
                break;
            }
        }
    }
    else
    {
        for (int i = 6; i <= 11; i++)
        {
            if (slots[i].getChipColor() == ChipColor::black) {
                has_chip_at_home = 1;
                break;
            }
        }
    }
    if (count >= 5 && !has_chip_at_home)
        return 0;
    else
        return 1;
}

bool Game::CheckMoves(PlayerTurn & turn){
    if (dice_1 == 0 && dice_2 == 0 && dice_3 == 0 && dice_4 == 0)
        return false;
  ChipColor oppoz_col;
  int count = 0;
  bool res = 0;
  ChipColor col;
  if (turn == PlayerTurn::firstPlayerTurn)
    col = ChipColor::white;
  else
    col = ChipColor::black;

  if(col == ChipColor::black) oppoz_col = ChipColor::white;
  else oppoz_col = ChipColor::black;
  for(int i = 0; i < 24; i++){
    if(slots[i].getChipColor() == col){
      if(was_taken_from_head && (col == ChipColor::black && i == 12 || col == ChipColor::white && i == 0)) continue;
      else if(((dice_1 != 0 && slots[(dice_1 + i) % 24].getChipColor() != oppoz_col) ||
        (dice_2 != 0 && slots[(dice_2 + i) % 24].getChipColor() != oppoz_col) ||
        (dice_3 != 0 && slots[(dice_3 + i) % 24].getChipColor() != oppoz_col) ||
        (dice_4 != 0 && slots[(dice_4 + i) % 24].getChipColor() != oppoz_col)) && !chipAtHome(col, i)) {
        res = 1;
      }
      else if (chipAtHome(col, i) &&
              ((SecondRound(col, dice_1, i) && slots[(dice_1 + i) % 24].getChipColor() != oppoz_col && dice_1 != 0) ||
               (SecondRound(col, dice_2, i) && slots[(dice_2 + i) % 24].getChipColor() != oppoz_col && dice_2 != 0) ||
               (SecondRound(col, dice_3, i) && slots[(dice_3 + i) % 24].getChipColor() != oppoz_col && dice_3 != 0) ||
               (SecondRound(col, dice_4, i) && slots[(dice_4 + i) % 24].getChipColor() != oppoz_col && dice_4 != 0))) {
        res = 1;
      }
      count++;
    }
    if(count == 15) break;
  }

  if(col == ChipColor::white){
      for(int i = 18; i < 24; i++){
          if(home(col) && (dice_1 + i == 24 || checkForEmptySlots(24, dice_1) ||
          dice_2 + i == 24 || checkForEmptySlots(24, dice_2))) res = 1;
      }
  }
  else{
      for(int i = 6; i < 12; i++){
          if(home(col) && (dice_1 + i == 25 || checkForEmptySlots(12, dice_1) ||
          dice_2 + i == 25 || checkForEmptySlots(12, dice_2))) res = 1;
      }
  }
  if(!res){
    change_states();
    turn =
      (turn == PlayerTurn::firstPlayerTurn ? PlayerTurn::secondPlayerTurn
                              : PlayerTurn::firstPlayerTurn);
    dice_1 = dice_2 = dice_3 = dice_4 = 0;
  }
  return res;
}

bool Game::home(ChipColor col){
    bool res = 0;
    int count = 0;
   if (col == ChipColor::white)
    {
        for (int i = 18; i <= 24; i++)
        {
            if (slots[i].getChipColor() == ChipColor::white)
                count += slots[i].getChipsCount();
        }
    }
    else if(col == ChipColor::black){
         for (int i = 6; i <= 11; i++)
        {
            if (slots[i].getChipColor() == ChipColor::black)
                count += slots[i].getChipsCount();
        }
         count += slots[25].getChipsCount();
    }
    if(count == 15) res = 1;
    return res;
}

float getShrinkageConstant(int numberOfChips)
{
    float shrinkageConstant{};
    if (numberOfChips <= 4)
        shrinkageConstant = 1.0f;
    else
    {
        int heightOfChips{ numberOfChips * (constants::ChipDiam + 20) };
        shrinkageConstant = static_cast<float>(heightOfChips) /
                            static_cast<float>(constants::SlotHeight);
    }

    return shrinkageConstant;
}

void Game::updateSlotChips(Slot& slot, int slotIndex)
{
    float xLeft{ slot.getXLeft() };
    slot.clearChips();
    float yStart{};
    if (slotIndex < 12)
        yStart = 920.0f;
    else
        yStart = 30.0f;

    int numberOfChips{ slot.getChipsCount() };
    ChipColor chipColor{ slot.getChipColor() };
    for (int i{ 0 }; i < numberOfChips; ++i)
    {
        if (slotIndex < 12)
            slot.pushChip(
                { { xLeft, yStart - static_cast<float>(i) * constants::ChipDiam /
                                        getShrinkageConstant(numberOfChips) },
                  chipColor,
                  m_textures });
        else
            slot.pushChip(
                { { xLeft, yStart + static_cast<float>(i) * constants::ChipDiam /
                                        getShrinkageConstant(numberOfChips) },
                  chipColor,
                  m_textures });
    }
}

void Game::moveChip()
{
    updateSlotChips(slots[slot_index_take], slot_index_take);
    updateSlotChips(slots[slot_index_drop], slot_index_drop);
}

void Game::handleChipMovement(const sf::Event& event, sf::RenderWindow& window,
                              PlayerTurn& turn)
{
    slot_index_drop = GetSlotIndex(event, window);
    ChipColor color;
    if (turn == PlayerTurn::firstPlayerTurn)
        color = ChipColor::white;
    else
        color = ChipColor::black;

    bool home_state = home(color);

    if (slots[slot_index_take].getChipColor() != color || slot_index_drop == -1)
    {
        m_chipChooseState = true;
        m_moveState = false;
        return;
    }
    MoveCount temp = MoveCount::no_move;
    if(home_state && (slot_index_drop == 24 || slot_index_drop == 25)){
        temp = home_play(color, slot_index_take);
    }
    
    if (temp == MoveCount::no_move && slot_index_drop != 24 && slot_index_drop != 25)
        temp = moveIsValid(slot_index_take, slot_index_drop, color);

    if (temp != MoveCount::no_move)
    {
        slots[slot_index_drop].setChipColor(
            slots[slot_index_take].getChipColor());
        slots[slot_index_drop].incrementChipCount();
        slots[slot_index_take].decrementChipCount();
        if (slots[slot_index_take].getChipsCount() == 0)
        {
            slots[slot_index_take].setChipColor(ChipColor::jopa_timura);
        }
        if (home_state)
            updateSlotChips(slots[slot_index_take], slot_index_take);
        else
            moveChip();
    }

    if (!dice_1 && !dice_2 && !dice_3 && !dice_4)
    {
        change_states();
        turn =
            (turn == PlayerTurn::firstPlayerTurn ? PlayerTurn::secondPlayerTurn
                                                 : PlayerTurn::firstPlayerTurn);
    }
    else
    {
        m_chipChooseState = true;
        m_moveState = false;
    }
}

void Game::change_states(){
    m_chipChooseState = false;
    m_moveState = false;
    m_diceThrowState = true;
    was_taken_from_head = false;
    dubl = false;
}

bool Game::checkForEmptySlots(int num, int dice)
{
    bool flag = false;
    int countOfEmpty = 0;
    for (int i{ num - 6 }; i <= num - dice; ++i)
    {
        std::cout << "slot index: " << i << '\n';
        if (slots[i].getChipColor() == ChipColor::jopa_timura)
            ++countOfEmpty;
    }
    std::cout << "count of empty: " << countOfEmpty << '\n';
    if (countOfEmpty >= 7 - dice)
        flag = true;

    std::cout << "check for empty flag: " << flag << '\n';

    return flag;
}

MoveCount Game::home_play(ChipColor color, int slotfrom){
    MoveCount ret = MoveCount::no_move;
    int num = 0;
    if (color == ChipColor::white) num = 24;
    else num = 12;
    if(num - slotfrom == dice_1 || checkForEmptySlots(num, dice_1)){
        dice_1 = 0;
        ret = MoveCount::true_move;
    }
    else if(num - slotfrom == dice_2 || checkForEmptySlots(num, dice_2)) {
        dice_2 = 0;
        ret = MoveCount::true_move;
    }
    else if(num - slotfrom == dice_1 + dice_2){
        dice_1 = dice_2 = 0;
        ret = MoveCount::true_move;
    }
    else if(dubl){
        if(num - slotfrom == dice_1 * 3 || checkForEmptySlots(num, dice_1)){
            dice_1 = dice_2 = dice_3 = 0;
            ret = MoveCount::true_move;
        }
        else if(num - slotfrom == dice_1 * 4 || checkForEmptySlots(num, dice_1)){
             dice_1 = dice_2 = dice_3 = dice_4 = 0;
            ret = MoveCount::true_move;
        }
    }
    std::cout << "ret: " << (ret == MoveCount::no_move ? "no move\n" : "true move\n");
    return ret;
}

void Game::SlotInit()
{
    for (int i{ 0 }; i < constants::numberOfSlots; ++i)
    {
        if (i < 6)
        {
            slots[i].setBounds(170.0f + constants::SlotWidth * static_cast<float>(i),
                               1045.0f - constants::SlotHeight);
        }
        else if (i >= 6 && i < 12)
        {
            slots[i].setBounds(1005.0f + constants::SlotWidth * static_cast<float>(i - 6),
                               1045.0f - constants::SlotHeight);
        }
        else if (i >= 12 && i < 18)
        {
            slots[i].setBounds(1630.0f + constants::SlotWidth * static_cast<float>(12 - i), 40.0f);
        }
        else
        {
            slots[i].setBounds(795.0f + constants::SlotWidth * static_cast<float>(18 - i), 40.0f);
        }
        slots[i].setChipColor(ChipColor::jopa_timura);
        slots[i].setChipsCount(0);
    }

    slots[constants::whiteAssemblySlotIndex].setBounds(40.0f, 40.0f);
    slots[constants::whiteAssemblySlotIndex].setHeight(constants::assemblySlotHeight);
    slots[constants::whiteAssemblySlotIndex].setWidth(constants::assemblySlotWidth);
    slots[constants::whiteAssemblySlotIndex].setChipsCount(0);
    slots[constants::whiteAssemblySlotIndex].setChipColor(ChipColor::jopa_timura);

    slots[constants::blackAssemblySlotIndex].setBounds(1795.0f, 595.0f);
    slots[constants::blackAssemblySlotIndex].setHeight(constants::assemblySlotHeight);
    slots[constants::blackAssemblySlotIndex].setWidth(constants::assemblySlotWidth);
    slots[constants::blackAssemblySlotIndex].setChipsCount(0);
    slots[constants::blackAssemblySlotIndex].setChipColor(ChipColor::jopa_timura);
}

void Game::setDolbaeb(bool fl)
{
    is_timur = fl;
}

void Game::StartPosition(const TextureHolder& textures)
{
    slots[0].setChipColor(ChipColor::white);
    slots[0].setChipsCount(15);
    slots[12].setChipsCount(15);
    slots[12].setChipColor(ChipColor::black);

    for (int i{ 0 }; i < constants::numberOfChips; ++i)
    {
        Chip whiteChip{ { 170.0f,
                          920.0f - static_cast<float>(i) * constants::ChipDiam /
                                       constants::firstChipDistanceConstant },
                        ChipColor::white,
                        textures };
        slots[0].pushChip(whiteChip);
    }
    for (int i{ 0 }; i < constants::numberOfChips; ++i)
    {
        Chip blackChip{ { 1620.0f,
                          30.0f + static_cast<float>(i) * constants::ChipDiam /
                                      constants::firstChipDistanceConstant },
                        ChipColor::black,
                        textures };
        slots[12].pushChip(blackChip);
    }
}

void Game::setDices()
{
  
    if (is_timur)
    {
        rnd.SmeshnoiRandom(dice_1, dice_2);
    }
    else
    {
        rnd.DefaultRandom(dice_1, dice_2);
    }
    if (dice_1 == dice_2)
    {
        dubl = true;
        dice_3 = dice_1;
        dice_4 = dice_1;
    }
    m_diceThrowState = false;
    m_chipChooseState = true;
}

int Game::getDice1()
{
    return dice_1;
}

int Game::getDice2()
{
    return dice_2;
}

void Game::ChangeHeight(int slotID)
{
    int numberOfChips{ slots[slotID].getChipsCount() };
    float currentHeight{ slots[slotID].getHeight() };
    float newHeight{ static_cast<float>(numberOfChips) * constants::ChipDiam /
                     getShrinkageConstant(numberOfChips) };
    if (numberOfChips == 0)
        newHeight = 500.0f;
    float heightDifference{ std::abs(currentHeight - newHeight) };
    if (slotID < 12)
    {
        float oldYTop{ slots[slotID].getYTop() };
        if (currentHeight < newHeight)
        {
            slots[slotID].setYTop(oldYTop - heightDifference);
            slots[slotID].setHeight(currentHeight + heightDifference);
        }
        else if (currentHeight > newHeight)
        {
            slots[slotID].setYTop(oldYTop + heightDifference);
            slots[slotID].setHeight(currentHeight - heightDifference);
        }
    }
    else
    {
        if (currentHeight < newHeight)
            slots[slotID].setHeight(currentHeight + heightDifference);
        else if (currentHeight > newHeight)
            slots[slotID].setHeight(currentHeight - heightDifference);
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

bool Game::SecondRound(ChipColor col, int dice, int index){
    if(col == ChipColor::white && (index + dice) < 24) return true;
    else if(col == ChipColor::black && (index + dice) < 12) return true;
    return false;
}

bool Game::chipAtHome(ChipColor col, int index){
    if (col == ChipColor::white)
    {
        if(index >= 18 && index < 24) return true;
    }
    else if(col == ChipColor::black){
        if(index >= 6 && index < 12) return true;
    }
    return false;
}

void Game::draw(sf::RenderWindow& window)
{
    for (auto& slot : slots)
    {
        slot.drawChips(window);
    }

    int numberOfChipsAtWhiteHome{ slots[constants::whiteAssemblySlotIndex].getChipsCount() };
    int numberOfChipsAtBlackHome{ slots[constants::blackAssemblySlotIndex].getChipsCount() };
    for (int i{ 0 }; i < numberOfChipsAtWhiteHome; ++i)
    {
        sf::RectangleShape whiteRectangle{
            { constants::assemblySlotWidth, 30 } };
        whiteRectangle.setFillColor(sf::Color::White);
        whiteRectangle.setPosition({ 40.0f, 40.0f + i * 30 });
        window.draw(whiteRectangle);
    }

    for (int i{ 0 }; i < numberOfChipsAtBlackHome; ++i)
    {
        sf::RectangleShape blackRectangle{
            { constants::assemblySlotWidth, 30 } };
        blackRectangle.setFillColor(sf::Color::Black);
        blackRectangle.setPosition({ 1795.0f, 595.0f + i * 30 });
        window.draw(blackRectangle);
    }

    drawBounds(window);
}

void Game::drawBounds(sf::RenderWindow& window)
{
    for (int i{ 0 }; i < constants::numberOfSlots + 2; ++i)
    {
        slots[i].drawSlotBounds(window, i);
    }
}
