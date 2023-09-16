#ifndef ALIASES_HPP
#define ALIASES_HPP

#include <array>
#include <memory>

#include "Constants.hpp"

class Chip;
class State;

using PlayerChips = std::array<Chip, constants::numberOfChips>;
using StatePtr = std::unique_ptr<State>;

#endif
