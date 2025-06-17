#include "../include/Projectile.hpp"

Projectile::Projectile(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& velocity)
	: m_sprite(texture)
	, m_velocity(velocity)
{
	m_sprite.setPosition(position);
}

void Projectile::draw(sf::RenderWindow& target) const 
{
	target.draw(m_sprite);


}

void Projectile::update(float dt) 
{
	m_sprite.move(m_velocity * dt);
	auto pos = m_sprite.getPosition();
	if (pos.x < 0 || pos.x > 700 || pos.y < 0 || pos.y > 700)
		m_alive = false;

}

bool Projectile::isAlive() const
{
	return m_alive;
}

sf::FloatRect Projectile::getPosition() const {
	return m_sprite.getGlobalBounds();
}