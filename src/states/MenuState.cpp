#include "MenuState.hpp"

#include "../Constants.hpp"
#include "../ResourceHolder.hpp"

MenuState::MenuState(StateStack& stack, Context context)
    : State{ stack, context },
      m_playButton{}
{
    ButtonTextInfo textInfo{ 30, "play", { 960.0f, 570.0f }, sf::Color::Black };
    ButtonInfo info{ { 930.0f, 530.0f }, { 200.0f, 100.0f }, sf::Color::White, textInfo };
    m_playButton = Button{ info, getContext().m_fonts->get(Fonts::ID::main) };
}

void MenuState::draw()
{
    sf::RenderWindow& window{ *getContext().m_window };
    m_playButton.draw(window);
}

bool MenuState::handleEvent(const sf::Event& event)
{
    if (m_playButton.isClicked(event, *getContext().m_window))
    {
        requestStackPop();
        requestStackPush(States::ID::game);
    }

    return true;
}
