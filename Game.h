#pragma once

#include "Entity.h"
#include "EntityManager.h" 

#include<SFML/Graphics.hpp>
#include<memory>

struct PlayerConfig {int SR,CR,FR,FG,FB,OR,OG,OB,OT,V;float S;};
class Game
{
    sf::RenderWindow m_window;
    int width = 1280;
    int height = 720;
    EntityManager m_entities;
    sf::Font m_font;
    sf::Text m_tex;
    PlayerConfig m_playerconfig;
    int m_score = 0;
    int m_currentFrame = 0;
    int m_lastEnemySpawnTime = 0;
    bool m_paused = false;
    bool m_running = true;

    std::shared_ptr<Entity> m_player;

    void init();
    void setPaused(bool paused);

    void sMovment();
    void sUserInput();
    void sLifespan();
    void sRender();
    void sEnemySpawner();
    void sCollision();

    void spawnPlayer();
    void spawnEnemy();
    void spawnSmallEnemies(std::shared_ptr<Entity> entity);
    void spawnBullet(std::shared_ptr<Entity> entity , const Vec2& mousePos);
    void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:
    Game();
    void run();
};