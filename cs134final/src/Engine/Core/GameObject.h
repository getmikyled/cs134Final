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

    template<typename T>
    T* getComponent()
    {
        // Check if object has component
        for (Component* component : components)
        {
            if (dynamic_cast<T*>(component) != nullptr)
            {
                return dynamic_cast<T*>(component);
            }
        }

        // Return null if no component
        return nullptr;
    }

    virtual void onEnable();
    virtual void onDisable();

    virtual void draw();
    virtual void onUpdate(ofEventArgs & args);
    virtual void onDestroy() {};

    virtual void onCollisionTriggered(GameObject* argGameObject);
    virtual bool canCollideWith(GameObject* argGameObject);

    bool pendingDestroy = false;
    
    Transform transform;
    std::vector<Component*> components;
};
