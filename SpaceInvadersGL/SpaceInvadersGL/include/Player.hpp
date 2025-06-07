#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "ResourceManager.hpp" 

class Player : public GameObject
{
public:
    Player(const sf::Texture& texture, const sf::Vector2f& position, float speed);
  
    ~Player() override = default;

    void update(float dt) override;
    void draw(sf::RenderWindow& target) const override; // The 'const' is important!
    
    //bool isAlive() override;

    void handleInput(const sf::Event& evt);
    void tryShoot();

private:
    sf::Sprite      m_sprite;
    sf::Vector2f    m_velocity{ 0.f, 0.f };
    bool            m_alive{ true };
    float           m_shootCooldown{ 0.f };
    float           m_speed{ 0.f };
};