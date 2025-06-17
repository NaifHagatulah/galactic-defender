#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
	
public:
	virtual ~GameObject() = default;
	virtual void update(float dt) = 0;
	
	virtual void draw(sf::RenderWindow& target) const = 0;

	virtual bool isAlive() const = 0;

	virtual sf::FloatRect getPosition() = 0;

};