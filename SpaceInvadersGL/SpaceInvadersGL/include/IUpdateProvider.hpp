#pragma once
#include "GameObject.hpp"
class gameObject;

class IUpdateProvider {
public:
    virtual ~IUpdateProvider() = default;

    virtual void update(GameObject& obj, float dt) = 0;
};