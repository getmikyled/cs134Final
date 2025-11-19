#pragma once
#include "../Core/GameObject.h"

class Scene
{
public:
    std::vector<GameObject*> pendingGameObjects;
    std::vector<GameObject*> gameObjects;

    template<typename T>
    T* createGameObject()
    {
        // Create game object
        T* gameObject = new T();
        pendingGameObjects.emplace_back(gameObject);
        return gameObject;
    }

    void addGameObject(GameObject* gameObject)
    {
        pendingGameObjects.emplace_back(gameObject);
    }

    virtual void setup() {};
    virtual void update();
    virtual void draw();
    virtual void calculateCollisions();
};
