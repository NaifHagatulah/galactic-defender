﻿#include "../include/Player.hpp"



Player::Player(const sf::Texture& texture, const sf::Vector2f& position, float speed, IUpdateProvider& provider)
    : GameObject(provider)
    , m_sprite(texture)
    , m_speed(speed)
{

    m_sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& target) const {
    target.draw(m_sprite);
}

/*void Player::update(float dt) {
   
    m_sprite.move(m_velocity * dt);

    if (m_shootCooldown > 0.f)
    {
        m_shootCooldown -= dt;
    }
}*/

void Player::handleInput(const sf::Event& evt) {

    if (const auto* keyEvt = evt.getIf<sf::Event::KeyPressed>())
    {
        switch (keyEvt->code)
        {
        case sf::Keyboard::Key::Left:
            m_velocity.x = -m_speed;
            break;
        case sf::Keyboard::Key::Right:
            m_velocity.x = m_speed;
            break;
        case sf::Keyboard::Key::Up:
            m_velocity.y = -m_speed;
            break;
        case sf::Keyboard::Key::Down:
            m_velocity.y = m_speed;
            break;
        case sf::Keyboard::Key::Space:
            tryShoot();
            break;
        default:
            break;
        }
    }
    else if (const auto* keyEvt = evt.getIf<sf::Event::KeyReleased>())
    {
        switch (keyEvt->code)
        {
            
        case sf::Keyboard::Key::Left:
            if (m_velocity.x < 0) m_velocity.x = 0;
            break;
        case sf::Keyboard::Key::Right:
            if (m_velocity.x > 0) m_velocity.x = 0;
            break;
        case sf::Keyboard::Key::Up:
            if (m_velocity.y < 0) m_velocity.y = 0;
            break;
        case sf::Keyboard::Key::Down:
            if (m_velocity.y > 0) m_velocity.y = 0;
            break;
        default:
            break;
        }
    }
}

void Player::tryShoot()
{
    if (m_shootCooldown > 0.f) return;
    m_shootCooldown = 1.f;

    if (!m_onShoot)
        throw std::runtime_error("Shoot callback not set");

    // spawn at top-center of sprite
    auto pos = m_sprite.getPosition();
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    // bounds.width  == 10
    // bounds.height == 15
    const float bulletW = 10.f;
    const float bulletH = 15.f;
    // player left + half player width  – half bullet width
    float spawnX = pos.x + (bounds.size.x - bulletW) / 2.f;
    float spawnY = pos.y - bounds.size.x / 2.f;
   
    sf::Vector2f spawnPos{ spawnX , spawnY };
    m_onShoot(spawnPos);

}

bool Player::isAlive() const
{
    return m_alive;
}

void Player::setShootCallback(std::function<void(sf::Vector2f)> cb) {
    m_onShoot = std::move(cb);
}

sf::FloatRect Player::getPosition() const{
    return m_sprite.getGlobalBounds();
}

void Player::kill()  {
    if (m_health < 1)
        m_alive = false;
    m_health -= 1;
}

sf::Sprite& Player::getSprite() {
    return m_sprite;
}

sf::Vector2f& Player::getVelocity() {
    return  m_velocity;
}

void Player::reduceCooldown(float dt) {
    if (m_shootCooldown > 0.f) 
        m_shootCooldown -= dt;
}