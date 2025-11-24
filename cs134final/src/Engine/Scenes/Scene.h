#pragma once
#include "ofEasyCam.h"
#include "../UserInterface/UserInterface.h"
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

        // Enable object if scene is active
        if (isActive)
        {
            gameObject->onEnable();
        }
        
        return gameObject;
    }

    void addGameObject(GameObject* gameObject)
    {
        pendingGameObjects.emplace_back(gameObject);

        // Enable object if scene is active
        if (isActive)
        {
            gameObject->onEnable();
        }
    }

    void onEnable();
    void onDisable();
    
    virtual void setup() {};
    virtual void update(ofEventArgs & args);
    virtual void draw(ofEventArgs & args);
    virtual void calculateCollisions();

    bool isActive = false;
    
    ofEasyCam* mainCamera = nullptr;
    UserInterface* userInterface = nullptr;
};
