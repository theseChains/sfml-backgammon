#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "../Button.hpp"
#include "State.hpp"

class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);

    void draw() override;
    bool handleEvent(const sf::Event& event) override;

private:
    Button m_playButton;
};

#endif
