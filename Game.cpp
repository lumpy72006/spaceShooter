#include "Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>


const sf::Time timePerFrame = sf::seconds(1.f/60.f);


Game::Game()
: mWindow(sf::VideoMode(640, 480), "Space Shooter")
, mWorld(mWindow)
,mFontHolder()
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingLeft(false)
, mIsMovingRight(false)
, playerSpeed(80.0f)
, mStatisticsUpdateTime(sf::Time::Zero)
,mStatisticsNumFrames(0)
{

    mFontHolder.load(Fonts::ID::Arial, "Media/Fonts/arial.TTF");
    mStatisticsText.setFont(mFontHolder.get(Fonts::ID::Arial));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10);
    mStatisticsText.setFillColor(sf::Color::White);

}


void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;



    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        processEvents();
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            processEvents();
            mWorld.update(timePerFrame);
        }

        updateStatistics(elapsedTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= playerSpeed;
    if (mIsMovingDown)
        movement.y += playerSpeed;
    if (mIsMovingLeft)
        movement.x -= playerSpeed;
    if (mIsMovingRight)
        movement.x += playerSpeed;

    // spaceShip.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWorld.draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
        if (key == sf::Keyboard::K)
            mIsMovingUp = isPressed;

        if (key == sf::Keyboard::J)
            mIsMovingDown = isPressed;

        if (key == sf::Keyboard::H)
            mIsMovingLeft = isPressed;

        if (key == sf::Keyboard::L)
            mIsMovingRight = isPressed;
}

void Game::updateStatistics(sf::Time elapsedTime)
{
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames++;

    if (mStatisticsUpdateTime >= sf::seconds(1.f))
    {
        float framesPerSecond = mStatisticsNumFrames / mStatisticsUpdateTime.asSeconds();
        float timePerRenderFrame = mStatisticsUpdateTime.asSeconds() / mStatisticsNumFrames;

        mStatisticsText.setString(
            "Frames / Second = " + std::to_string(framesPerSecond) + "\n"
            "Time / Update = " + std::to_string(timePerRenderFrame) + "s"
        );

        mStatisticsUpdateTime -= sf::seconds(1.f);
        mStatisticsNumFrames = 0;
    }
}
