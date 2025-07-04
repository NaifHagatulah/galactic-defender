// Game.hpp
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ResourceManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "CollisionManager.hpp"
#include "PlayerUpdateProvider.hpp"
#include "ProjectileUpdateProvider.hpp"



static constexpr float WINDOW_WIDTH = 700.f;
static constexpr float WINDOW_HEIGHT = 700.f;
static constexpr float    BULLET_SPEED = 400.f;

class Game {
	
		
public:
	
	Game();
	void run();

	PlayerUpdateProvider playerUpdateProvider;

	ProjectileUpdateProvider projectileUpdateProvider;

private:
	
	void processEvents();
	void update(float dt);
	void render();

	void spawnPlayer();
	void spawnBullet(const sf::Vector2f& pos);

	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<GameObject>> m_objects;
};