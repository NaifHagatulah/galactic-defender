#pragma once
#include "IUpdateProvider.hpp"

class DefaultUpdateProvider : public IUpdateProvider {
public:
    void update(GameObject& obj, float dt) override {
        // No special behavior; override in specialized providers
        (void)obj; (void)dt;
    }
};
