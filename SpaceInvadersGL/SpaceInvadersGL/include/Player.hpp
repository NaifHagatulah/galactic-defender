#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "ResourceManager.hpp"

class Player : public GameObject
{
public:
    // 1) Constructor declaration: takes a texture by const-reference
    Player(const sf::Texture& texture, sf::Vector2f& velocity);

    // 2) Virtual destructor (inherited from GameObject)
    ~Player() override = default;

    // 3) Override the pure-virtual methods from GameObject:
    void update(float dt) override;
    void draw(sf::RenderWindow& target) const override;
    bool isAlive() override;

    // 4) Player-specific methods
    void handleInput(const sf::Event& evt);
    void tryShoot();

    sf::Sprite      m_sprite;        // The visible sprite for this Player
    sf::Vector2f    m_velocity{ 0.f, 0.f };  // Current velocity (initialized to zero)
    bool            m_alive{ true };       // Is the player “alive”?
    float           m_shootCooldown{ 0.f }; // Simple cooldown timer
};
