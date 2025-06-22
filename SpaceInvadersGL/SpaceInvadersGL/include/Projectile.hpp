#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "ResourceManager.hpp" 
#include "IUpdateProvider.hpp"


class Projectile : public GameObject
{
public:

    Projectile(const sf::Texture& texture,
        const sf::Vector2f& position,
        const sf::Vector2f& velocity,
        IUpdateProvider& updater);

    ~Projectile() override = default;

    //void update(float dt);

    void draw(sf::RenderWindow& target) const override; // The 'const' is important!
    sf::FloatRect getPosition() const override;

    bool isAlive() const override;
    void kill()  override;
    
    sf::Sprite& getSprite();
    sf::Vector2f    getVelocity() const;
    bool            isOutOfBounds() const;

private:
    sf::Sprite      m_sprite;
    sf::Vector2f    m_velocity{ 0.f, 0.f };
    bool            m_alive{ true };
    float           m_speed{ 0.f };
};