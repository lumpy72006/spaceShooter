#include "Aircraft.hpp"
#include "Resources.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <stdexcept>


const float xScale = 0.03f;
const float yScale = 0.03f;


Textures::ID toTextureID(Aircraft::Type type)
{
    switch (type) {
        case Aircraft::Eagle:
            return Textures::ID::Eagle;

        case Aircraft::Raptor:
            return Textures::ID::Raptor;
        }
    throw std::runtime_error("Aircraft::toTextureID - Unknown Aircraft::Type passed.");
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
: mType(type)
,mSprite(textures.get(toTextureID(type)))
{
    switch (type) {

    case Eagle:
        mSprite.setScale(xScale, yScale);
        break;
    case Raptor:
        mSprite.setScale(0.04f, 0.04f);
        break;
    }

    // mSprite.setScale(xScale, yScale);
    
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

