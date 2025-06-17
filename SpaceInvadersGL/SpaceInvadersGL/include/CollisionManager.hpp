#pragma once 

#include "GameObject.hpp"

class CollisionManager {
public:
	CollisionManager() = default;
	static void run(std::vector<std::unique_ptr<GameObject>>& objects);

private:
	static void broadPhase(GameObject& obj1, GameObject& obj2);
	static void narrowPhase(GameObject& obj1, GameObject& obj2);
};
