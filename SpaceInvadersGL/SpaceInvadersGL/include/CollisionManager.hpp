#pragma once 

#include "GameObject.hpp"

class CollisionManager {
public:
	CollisionManager();
	void run(std::vector<std::unique_ptr<GameObject>> objects);
};
