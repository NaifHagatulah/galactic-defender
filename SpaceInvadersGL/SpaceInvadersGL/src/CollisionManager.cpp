#include "../include/CollisionManager.hpp"

void CollisionManager::run(std::vector<std::unique_ptr<GameObject>> objects) {

}

void CollisionManager::broadPhase(const GameObject& obj1, const GameObject& obj2) {
	sf::FloatRect pos1 = obj1.getPosition();
}

void CollisionManager::narrowPhase(const GameObject& obj1, const GameObject& obj2) {

}