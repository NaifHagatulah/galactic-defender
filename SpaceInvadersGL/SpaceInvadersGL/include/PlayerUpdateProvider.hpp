#pragma once
#include "Player.hpp"
#include "IUpdateProvider.hpp"
#include "GameObject.hpp"

class PlayerUpdateProvider : public IUpdateProvider {
public:
	void update(GameObject& obj, float dt) {
		auto& p = static_cast<Player&>(obj);
		p.getSprite().move(p.getVelocity() * dt);
		p.reduceCooldown(dt);
	}
};