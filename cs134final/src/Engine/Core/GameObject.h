#pragma once

#include "Component.h"
#include "Transform.h"

class GameObject
{
public:

    GameObject() {}
    ~GameObject() {}

    template<typename T>
    T* addComponent()
    {
        // Create component
        T* component = new T();
        component->gameObject = this;
        
        components.emplace_back(component);
        return component;
    }

    virtual void draw();
    virtual void update();
    virtual void onDestroy() {};

    bool pendingDestroy = false;
    
    Transform transform;
    std::vector<Component*> components;
};
