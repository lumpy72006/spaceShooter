#pragma once

#include "ResourceHolder.hpp"
#include <SFML/Graphics.hpp>

namespace Textures
{
    enum class ID { Eagle, Landscape, Airplane, Missile, Raptor, Desert };
}

namespace Fonts
{
    enum class ID { Arial, Sans };
}

typedef ResourceHolder<sf::Texture, Textures::ID>  TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;
