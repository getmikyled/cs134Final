#include "Scene.h"

#include "ofGraphics.h"
#include "ofLight.h"

void Scene::onEnable()
{
    // Subscribe events
    ofAddListener(ofEvents().update, this, &Scene::update);
    ofAddListener(ofEvents().draw, this, &Scene::draw);

    // Enable user interface
    if (userInterface != nullptr) userInterface->onEnable();

    // Enable game objects
    for (GameObject* gameObject : gameObjects)
    {
        gameObject->onEnable();
    }

    for (GameObject* gameObject : pendingGameObjects)
    {
        gameObject->onEnable();
    }

    for (ofLight* light : lights)
    {
        light->enable();
    }
}

void Scene::onDisable()
{
    // Subscribe events
    ofRemoveListener(ofEvents().update, this, &Scene::update);
    ofRemoveListener(ofEvents().draw, this, &Scene::draw);

    // Disable userInterface
    if (userInterface != nullptr) userInterface->onDisable();

    // Disable game objects
    for (GameObject* gameObject : gameObjects)
    {
        gameObject->onDisable();
    }

    for (GameObject* gameObject : pendingGameObjects)
    {
        gameObject->onDisable();
    }

    for (ofLight* light : lights)
    {
        light->disable();
    }
}

void Scene::update(ofEventArgs & args)
{
    // Update ui
    if (userInterface != nullptr)
    {
        userInterface->update();
    }
    
    ///-////////////////////////////////////////////////////////////////////////////////////////
    /// Update all game objects in scene
    auto gameObject = gameObjects.begin();
    while (gameObject != gameObjects.end())
    {
        // Delete if object is pending for destroy
        if ((*gameObject)->pendingDestroy)
        {
            (*gameObject)->onDestroy();
            gameObject = gameObjects.erase(gameObject); // erase returns the next iterator
        }
        // Otherwise, update game object
        else
        {
            ++gameObject;
        }
    }

    ///-////////////////////////////////////////////////////////////////////////////////////////
    /// Add any new pending game objects - we use it because we don't want to modify
    /// gameObjects iterator while its updating
    for (auto* pending : pendingGameObjects)
    {
        gameObjects.emplace_back(pending);
    }
    pendingGameObjects.clear();

    ///-////////////////////////////////////////////////////////////////////////////////////////
    /// Calculate collisions
    calculateCollisions();
}

void Scene::draw(ofEventArgs &args)
{

    ofEnableDepthTest();
    ofEnableLighting();
    if (mainCamera != nullptr)
    {
        mainCamera->begin();
    }

    for (GameObject* gameObject : gameObjects)
    {
        gameObject->draw();
    }
    
    if (mainCamera != nullptr)  mainCamera->end();
    ofDisableLighting();
    ofDisableDepthTest();

    // Draw User Interface
    if (userInterface  != nullptr) userInterface->draw();
}

void Scene::calculateCollisions()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        /*if (Entity* entityA = dynamic_cast<Entity*>(gameObjects[i]))
        {
            if (entityA->collisionsEnabled)
            {
                for (int j = 0; j < gameObjects.size(); j++)
                {
                    if (i != j)
                    {
                        if (Entity* entityB = dynamic_cast<Entity*>(gameObjects[j]))
                        {
                            if (entityB->collisionsEnabled && entityA->canCollideWith(entityB))
                            {
                                // Get entity A bounds
                                ofVec3f min = entityA->model->getSceneMin() + entityA.getPosition();
                                ofVec3f max = lander.getSceneMax() + lander.getPosition();

                                Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
                            }
                        }
                    }
                }   
            }
        }*/
    }
}
