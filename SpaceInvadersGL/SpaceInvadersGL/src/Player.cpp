#include "../include/Player.hpp"
#include <SFML/Graphics.hpp>

// The constructor definition is now consistent with the header declaration
Player::Player(const sf::Texture& texture,
    const sf::Vector2f& position,
    float speed)
    : m_sprite(texture)
    , m_speed(speed)
{

    m_sprite.setPosition(position);
}

// FIX 2: Added the 'Player::' scope resolution to all member functions.
// FIX 3: Added the 'const' keyword to match the header declaration.
void Player::draw(sf::RenderWindow& target) const {
    target.draw(m_sprite);
}

// FIX 4: Implemented the update logic.
void Player::update(float dt) {
    // Update the player's position based on its velocity and elapsed time
    m_sprite.move(m_velocity * dt);

    // Simple cooldown update
    if (m_shootCooldown > 0.f)
    {
        m_shootCooldown -= dt;
    }
}

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
        default:
            break;
        }
    }
    else if (const auto* keyEvt = evt.getIf<sf::Event::KeyReleased>())
    {
        switch (keyEvt->code)
        {
            // This logic correctly stops movement on one axis without
            // interfering with the other.
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
    // You can add your shooting logic here.
    // For example, check the cooldown:
    if (m_shootCooldown <= 0.f)
    {
        // Logic to create a bullet...
        // std::cout << "Pew!" << std::endl;

        // Reset the cooldown
        // m_shootCooldown = 0.5f; // e.g., 0.5 second cooldown
    }
}