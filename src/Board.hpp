#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

#include "Button.hpp"
#include "Player.hpp"
#include "PlayerTurn.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class Board
{
public:
    Board(sf::Font& font, const TextureHolder& textures, sf::RenderWindow& window);

    void initializeButtons(const sf::Font& font);
    void handleButtonClick(const sf::Event& event, Button& button);
    void handleEvent(const sf::Event& event);
    void draw();

private:
    sf::RenderWindow& m_window;
    Button m_firstPlayerButton;
    Button m_secondPlayerButton;
    Player m_firstPlayer;
    Player m_secondPlayer;

    PlayerTurn m_playerTurn;
    bool m_moveState;

    void drawPlayerChips(const Player& player, sf::RenderWindow& window);
};

#endif
