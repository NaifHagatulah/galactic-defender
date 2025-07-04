#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "ResourceManager.hpp" 
#include "Projectile.hpp"
#include "IUpdateProvider.hpp"
#include <functional>

class Player : public GameObject
{
public:
    Player(const sf::Texture& texture, const sf::Vector2f& position, float speed, IUpdateProvider& updater);
  
    ~Player() override = default;

    //void update(float dt) override;
    void draw(sf::RenderWindow& target) const override; 
   
    void setShootCallback(std::function<void(sf::Vector2f /*pos*/)> cb);
    
    bool isAlive() const override;

    void handleInput(const sf::Event& evt);
    void tryShoot();

    sf::FloatRect getPosition() const override;
    void kill()  override;

    sf::Sprite& getSprite();
    sf::Vector2f& getVelocity();
    void reduceCooldown(float dt);
        

private:
    std::function<void(sf::Vector2f)> m_onShoot;
    sf::Sprite      m_sprite;
    sf::Vector2f    m_velocity{ 0.f, 0.f };
    bool            m_alive{ true };
    float           m_shootCooldown{ 0.f };
    float           m_speed{ 0.f };
    int             m_health{3};

    
};