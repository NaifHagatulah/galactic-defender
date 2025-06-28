#include "../include/Projectile.hpp"

Projectile::Projectile(const sf::Texture& tex,
	const sf::Vector2f& pos,
	const sf::Vector2f& vel,
	IUpdateProvider& updater)
	: GameObject(updater)
	, m_sprite(tex)
	, m_velocity(vel)
{
	m_sprite.setPosition(pos);
}

void Projectile::draw(sf::RenderWindow& target) const 
{
	target.draw(m_sprite);


}

/*void Projectile::update(float dt)
{
	m_sprite.move(m_velocity * dt);
	auto pos = m_sprite.getPosition();
	if (pos.x < 0 || pos.x > 700 || pos.y < 0 || pos.y > 700)
		m_alive = false;

}
*/

bool Projectile::isAlive() const
{
	return m_alive;
}

sf::FloatRect Projectile::getPosition() const {
	return m_sprite.getGlobalBounds();
}


void Projectile::kill()  {
	m_alive = false;
}

sf::Sprite& Projectile::getSprite() { return m_sprite; }
sf::Vector2f Projectile::getVelocity() const { return m_velocity; }
bool Projectile::isOutOfBounds() const {
	auto pos = m_sprite.getPosition();
	return (pos.x < 0.f || pos.x > 3000 || pos.y < 0.f || pos.y > -300);
}