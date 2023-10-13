#include "StateStack.hpp"

#include <iostream>
#include <memory>

#include "GameState.hpp"
#include "MenuState.hpp"

StateStack::StateStack(State::Context context)
    : m_stack{}, m_pendingChanges{}, m_context{ context }
{
}

StatePtr StateStack::createState(States::ID stateID)
{
    switch (stateID)
    {
        case States::ID::menu:
            return std::make_unique<MenuState>(*this, m_context);
        case States::ID::game:
            return std::make_unique<GameState>(*this, m_context);
        case States::ID::none:
            throw std::runtime_error{ "StateStack::createState() - State::ID::none passed to creation" };
        default:
            throw std::runtime_error{ "StateStack::createState() - unknown stateID" };
    }
}

void StateStack::draw()
{
    for (auto& state : m_stack)
    {
        state->draw();
    }
}

void StateStack::pushState(States::ID stateID)
{
    m_pendingChanges.push_back(PendingChange(Action::push, stateID));
}

void StateStack::popState()
{
    m_pendingChanges.push_back(PendingChange(Action::pop));
}

void StateStack::clearStates()
{
    m_pendingChanges.push_back(PendingChange(Action::clear));
}

bool StateStack::isEmpty() const
{
    return m_stack.empty();
}

void StateStack::handleEvent(const sf::Event& event)
{
    for (auto iterator{ m_stack.rbegin() }; iterator != m_stack.rend(); ++iterator)
    {
        if (!(*iterator)->handleEvent(event))
            return;
    }

    applyPendingChanges();
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
    : m_action{ action }, m_stateID{ stateID }
{
}

void StateStack::applyPendingChanges()
{
    for (const auto& change : m_pendingChanges)
    {
        switch (change.m_action)
        {
            case Action::push:
                std::cout << "creating state\n";
                m_stack.push_back(createState(change.m_stateID));
                break;
            case Action::pop:
                m_stack.pop_back();
                break;
            case Action::clear:
                m_stack.clear();
                break;
        }
    }

    m_pendingChanges.clear();
}
