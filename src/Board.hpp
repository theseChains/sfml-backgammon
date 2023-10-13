#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

#include "Button.hpp"
#include "Game.hpp"
#include "PlayerTurn.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class Board
{
public:
    Board(sf::Font& font, TextureHolder& textures, sf::RenderWindow& window);

    void initializeButtons(const sf::Font& font);
    void handleButtonClick(const sf::Event& event, Button& button);
    void handleEvent(const sf::Event& event);
    void draw();

private:
    sf::RenderWindow& m_window;
    Button m_firstPlayerButton;
    Button m_secondPlayerButton;
    sf::Sprite m_sprite;

    PlayerTurn m_playerTurn;
    Game m_game;
};

#endif
