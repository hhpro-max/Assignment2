#include "Game.h"
#include <iostream>

void Game::init()
{
    m_window.create(sf::VideoMode(width, height), "Assignment 2");
    m_window.setFramerateLimit(60);
    spawnPlayer();
}
void Game::run()
{
    while (m_running)
    {
        m_entities.update();

        sEnemySpawner();
        sMovment();
        sCollision();
        sUserInput();
        sRender();
        m_currentFrame++;
    }
}
void setPaused(bool paused)
{
}
void Game::spawnPlayer()
{
    auto entity = m_entities.addEntity("player");
    float mx = m_window.getSize().x / 2.0f;
    float my = m_window.getSize().y / 2.0f;
    entity->cTransform = std::make_shared<CTransform>(Vec2(mx, my), Vec2(0.0f, 0.0f), 0.0f);
    entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
    entity->cInput = std::make_shared<CInput>();

    m_player = entity;
}
void Game::spawnEnemy()
{
    // todo
    // spawn just like player
    m_lastEnemySpawnTime = m_currentFrame;
}
void Game::spawnSmallEnemies(std::shared_ptr<Entity> e)
{
    // todo
}
void Game::spawnSpecialWeapon(std::shared_ptr<Entity> e)
{
    // todo
}
void Game::sMovment()
{
    m_player->cTransform->velocity = {0, 0};
    if (m_player->cInput->up)
    {
        m_player->cTransform->velocity.y = -5;
    }
    // todo
    m_player->cTransform->position.x += m_player->cTransform->velocity.x;
    m_player->cTransform->position.y += m_player->cTransform->velocity.y;
}
void Game::sLifespan()
{
    // todo
}
void Game::sCollision()
{
    // todo
}
void Game::sEnemySpawner()
{
    // todo
    spawnEnemy();
}
void Game::sRender()
{
    m_window.clear();

    m_player->cShape->circle.setPosition(m_player->cTransform->position.x, m_player->cTransform->position.y);
    m_player->cTransform->angle += 1.0f;
    m_player->cShape->circle.setRotation(m_player->cTransform->angle);

    m_window.draw(m_player->cShape->circle);
    m_window.display();
}
void Game::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_running = false;
        }
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                m_player->cInput->up = true;
                break;

            default:
                break;
            }
        }
        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                m_player->cInput->up = false;
                break;

            default:
                break;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                // get the mouse position using
                event.mouseButton.x;
                event.mouseButton.y;
                // spawn bullet
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                // specialweapon
            }
        }
    }
}