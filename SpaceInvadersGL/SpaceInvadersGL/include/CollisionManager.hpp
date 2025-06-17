#pragma once 

#include "GameObject.hpp"

class CollisionManager {
public:
	CollisionManager() = default;
	static void run(std::vector<std::unique_ptr<GameObject>> objects);

private:
	void broadPhase(const GameObject& obj1, const GameObject& obj2);
	void narrowPhase(const GameObject& obj1, const GameObject& obj2);
};
