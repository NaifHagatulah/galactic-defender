#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "ResourceManager.hpp" 

class Projectile : public GameObject
{
public:
    // allow default construction (will be “dead” until properly initialized)
    sf::FloatRect getBounds();

    Projectile(const sf::Texture& texture,
        const sf::Vector2f& position,
        const sf::Vector2f& velocity);

    ~Projectile() override = default;

    void update(float dt) override;
    void draw(sf::RenderWindow& target) const override; // The 'const' is important!

    bool isAlive() const override;
private:
    sf::Sprite      m_sprite;
    sf::Vector2f    m_velocity{ 0.f, 0.f };
    bool            m_alive{ true };
    float           m_speed{ 0.f };
};