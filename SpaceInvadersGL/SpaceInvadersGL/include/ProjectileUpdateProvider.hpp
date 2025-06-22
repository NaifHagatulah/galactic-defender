#pragma once
#include "IUpdateProvider.hpp"
#include "Projectile.hpp"

class ProjectileUpdateProvider : public IUpdateProvider {
public:
    void update(GameObject& baseObj, float dt) override {
        auto& p = static_cast<Projectile&>(baseObj);
        p.getSprite().move(p.getVelocity() * dt);
        if (p.isOutOfBounds()) p.kill();
    }
};