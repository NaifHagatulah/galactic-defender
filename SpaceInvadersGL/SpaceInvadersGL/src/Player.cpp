#include "../include/Player.hpp"

#include <SFML/Graphics.hpp>

sf::Sprite      m_sprite;        
sf::Vector2f    m_velocity{ 0.f, 0.f };  
bool            m_alive{ true };       
float           m_shootCooldown{ 0.f }; 
Player::Player(const sf::Texture& texture, sf::Vector2f& position)
    : m_sprite(texture)
{
    m_sprite.setPosition(position);
}

void draw(sf::RenderWindow& target) {
    target.draw(m_sprite);
}