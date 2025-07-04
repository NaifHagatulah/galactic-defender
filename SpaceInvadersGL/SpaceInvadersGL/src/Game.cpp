﻿#include "../include/Game.hpp"
#include <algorithm>
#include <iostream>
#include "../include/PlayerUpdateProvider.hpp"
#include <SFML/System.hpp>
#include <SFML/System.hpp>  // defines sf::FloatRect

#include <SFML/Graphics.hpp> // also pulls in FloatRect transitively
Game::Game()
    : m_window(sf::VideoMode({ 700, 700 }), "SFML works!")
{
    m_window.setFramerateLimit(60);
    sf::FloatRect playArea(sf::Vector2f(0.f, 0.f), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

    projectileUpdateProvider.setBounds(playArea);

    // Load textures
    ResourceManager::loadTexture("player", "assets\\green.png");
    ResourceManager::loadTexture("bullet", "assets\\bullet2.png");
    auto& playerTexture = ResourceManager::getTexture("player");

    // Spawn player
    spawnPlayer();
    render();
    run();
}

void Game::render() {
    m_window.clear(sf::Color(30, 30, 30));
    for (auto& obj : m_objects)
        obj->draw(m_window);
    m_window.display();
}

void Game::run() {
    sf::Clock clock;
    while (m_window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        CollisionManager::run(m_objects);
        render();
    }
}

void Game::update(float dt) {
    // Update all objects
    for (auto& obj : m_objects)
        obj->update(dt);

    // Remove dead objects
    m_objects.erase(
        std::remove_if(
            m_objects.begin(), m_objects.end(),
            [](const auto& ptr) { return !ptr->isAlive(); }
        ),
        m_objects.end()
    );

    // If no player left, exit (or respawn)
    if (m_objects.empty() || dynamic_cast<Player*>(m_objects.front().get()) == nullptr) {
        std::cout << "Player died. Exiting...\n";
        m_window.close();
    }
}

void Game::processEvents() {
    
    
    while (auto event = m_window.pollEvent()) {
        
        if (event->is<sf::Event::Closed>()) {
            m_window.close();
            continue;
        }

        
        if (event->is<sf::Event::KeyPressed>() || event->is<sf::Event::KeyReleased>()) {
            auto* player = static_cast<Player*>(m_objects.front().get());
            player->handleInput(*event);
        }
    }
}

void Game::spawnBullet(const sf::Vector2f& pos) {
    auto& tex = ResourceManager::getTexture("bullet");
    sf::Vector2f vel{ 0.f, -BULLET_SPEED };
    //PlayerUpdateProvider test;
    auto bullet = std::make_unique<Projectile>(tex, pos, vel, projectileUpdateProvider);
    m_objects.push_back(std::move(bullet));
}

void Game::spawnPlayer() {
    auto& tex = ResourceManager::getTexture("player");
    sf::Vector2f startPos{ WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - 50.f };
    float speed = 300.f;
    //PlayerUpdateProvider test;
    
    auto player = std::make_unique<Player>(tex, startPos, speed, playerUpdateProvider);
    // Shoot callback
    player->setShootCallback(
        [this](sf::Vector2f pos) {
            spawnBullet(pos);
        }
    );
    m_objects.push_back(std::move(player));
}