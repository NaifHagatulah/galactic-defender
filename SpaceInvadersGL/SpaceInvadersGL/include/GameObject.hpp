#pragma once
#include <SFML/Graphics.hpp>
#include "IUpdateProvider.hpp"

class GameObject {
	
public:
	GameObject(IUpdateProvider& provider)
		: m_provider(provider) {
	}
	virtual ~GameObject() = default;

	void update(float dt) {
		m_provider.update(*this, dt);
	}
	
	virtual void draw(sf::RenderWindow& target) const = 0;

	virtual bool isAlive() const = 0;

	virtual sf::FloatRect getPosition() const = 0;
	virtual void kill()  = 0;

protected:
	IUpdateProvider& m_provider;

};