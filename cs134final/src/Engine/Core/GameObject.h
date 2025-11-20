#pragma once

#include "Component.h"
#include "ofEvents.h"
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

    virtual void onEnable();
    virtual void onDisable();

    virtual void onDraw(ofEventArgs & args);
    virtual void onUpdate(ofEventArgs & args);
    virtual void onDestroy() {};

    bool pendingDestroy = false;
    
    Transform transform;
    std::vector<Component*> components;
};
