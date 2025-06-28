#pragma once
//#include "GameObject.hpp"
class GameObject;

class IUpdateProvider {
public:
    virtual ~IUpdateProvider() = default;

    virtual void update(GameObject& obj, float dt) = 0;
};