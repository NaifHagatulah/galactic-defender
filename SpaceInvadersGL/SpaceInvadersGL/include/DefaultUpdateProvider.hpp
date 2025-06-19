#pragma once
#include "IUpdateProvider.hpp"

class DefaultUpdateProvider : public IUpdateProvider {
	void update(GameObject& obj, float dt);
};