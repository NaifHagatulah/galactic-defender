#pragma once
#include "Player.hpp"
#include "IUpdateProvider.hpp"
#include "GameObject.hpp"

class PlayerUpdateProvider : IUpdateProvider {
	void update(GameObject& baseObj, float dt) {
		auto& p = static_cast<Player&>(baseObj);
		p.getSprite().move(p.getVelocity() * dt);
		p.reduceCooldown(dt);
	}
};