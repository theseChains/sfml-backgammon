#ifndef RESOURCE_IDENTIFIERS_HPP
#define RESOURCE_IDENTIFIERS_HPP

#include <SFML/Graphics.hpp>

namespace Textures
{
    enum class ID
    {
        whiteChip,
        blackChip
    };
}

namespace Fonts
{
    enum class ID
    {
        main
    };
}

template <typename Resource, typename Identifier>
class ResourceHolder;

using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;
using FontHolder = ResourceHolder<sf::Font, Fonts::ID>;

#endif
