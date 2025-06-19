#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "ResourceManager.hpp"
#include "Projectile.hpp"
#include <functional>

class Bot : public GameObject {
public:
    Bot(const sf::Texture& texture,
        const sf::Vector2f& position,
        float speed,
        std::function<void(sf::Vector2f)> shootCallback);

    ~Bot() override = default;

    void update(float dt) override;
    void draw(sf::RenderWindow& target) const override;
    sf::FloatRect getPosition() const override;

    bool isAlive() const override { return m_alive; }
    void kill()  override { m_alive = false; }

private:
    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
    float       m_speed;
    bool        m_alive{ true };

    // Shooting
    std::function<void(sf::Vector2f)> m_onShoot;
    float m_shootCooldown{ 1.0f };    // seconds between shots
    float m_shootTimer{ 0.f };

    // Simple AI state
    enum class State { Patrol, Chase, Flee } m_state{ State::Patrol };
    float m_patrolDirection{ 1.f };    // 1 = right, -1 = left
    float m_patrolRange{ 200.f };      // how far from start pos
    sf::Vector2f m_startPos;
};
