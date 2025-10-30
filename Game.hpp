#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.hpp"
#include "World.hpp"

class Game
{
public:
                        Game();
    void                run();

private:
    void                processEvents();
    void                update(sf::Time deltaTime);
    void                render();
    void                handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void                updateStatistics(sf::Time elapsedTime);

private:
    sf::RenderWindow    mWindow;
    World               mWorld;

    sf::Font            mFont;
    FontHolder          mFontHolder;
    sf::Text            mStatisticsText;
    sf::Time            mStatisticsUpdateTime;
    std::size_t         mStatisticsNumFrames;

    bool                mIsMovingUp;
    bool                mIsMovingDown;
    bool                mIsMovingLeft;
    bool                mIsMovingRight;
    float               playerSpeed;
};
