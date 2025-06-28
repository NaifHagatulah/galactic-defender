// ProjectileUpdateProvider.hpp
#pragma once
#include "IUpdateProvider.hpp"
#include "Projectile.hpp"
#include <SFML/Graphics.hpp>

class ProjectileUpdateProvider : public IUpdateProvider {
public:
    ProjectileUpdateProvider() = default;            
    void setBounds(const sf::FloatRect& b) { m_bounds = b; }

    void update(GameObject& baseObj, float dt) override {
        auto& p = static_cast<Projectile&>(baseObj);
        p.getSprite().move(p.getVelocity() * dt);
        if (p.isOutOfBounds()) p.kill();
    }
private:
    sf::FloatRect m_bounds;   
};
