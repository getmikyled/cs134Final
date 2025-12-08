#include "Scene.h"

#include "InputSystem.h"
#include "ofGraphics.h"
#include "ofLight.h"
#include "Engine/Physics/Collider.h"

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
    ofEnableAlphaBlending();
    if (mainCamera != nullptr)
    {
        mainCamera->begin();
    }


    for (GameObject* gameObject : gameObjects)
    {
        gameObject->draw();
    }

    

    if (mainCamera != nullptr)  mainCamera->end();
    ofDisableAlphaBlending();
    ofDisableLighting();
    ofDisableDepthTest();

    // Draw User Interface
    if (userInterface  != nullptr) userInterface->draw();
}

void Scene::calculateCollisions()
{
    if (octree != nullptr)
    {
        for (GameObject* gameObject : gameObjects)
        {
            Collider* collider = gameObject->getComponent<Collider>();
            if (collider != nullptr)
            {
                // Check for collisions with octree
                Box& bounds = collider->getBounds();
                vector<Box> colBoxList;
                octree->intersect(bounds, octree->root, colBoxList);
                if (colBoxList.size() >= 5)
                {
                    glm::vec3 averageBoxPosition = glm::vec3(0, 0, 0);
                    for (int i = 0; i < colBoxList.size(); i++)
                    {
                        Vector3 center = bounds.center();
                        averageBoxPosition += glm::vec3(center.x(), center.y(), center.z());
                    }
                    averageBoxPosition /= colBoxList.size();

                    glm::vec3 direction = normalize(averageBoxPosition - glm::vec3(gameObject->transform.position));


                        
                    gameObject->onCollisionTriggered(octree, direction);
                }

                // Check for collisions with other objects
                for (GameObject* otherGameObject : gameObjects)
                {
                    Collider* otherCollider = otherGameObject->getComponent<Collider>();
                    if (gameObject != otherGameObject && otherCollider != nullptr && otherGameObject->canCollideWith(gameObject)
                        && collider->getBounds().overlap(otherCollider->getBounds()))
                    {
                        ofVec3f normal = gameObject->transform.position - otherGameObject->transform.position;
                        gameObject->onCollisionTriggered(otherGameObject, normal);
                        otherGameObject->onCollisionTriggered(gameObject, -normal);
                    }
                }
            }
        }
    }
}

void Scene::setUserInterface(UserInterface* argUserInterface)
{
    if (isActive)
    {
        if (userInterface != nullptr)
        {
            userInterface->onDisable();
        }
        
        userInterface = argUserInterface;
        userInterface->onEnable();
    }
}
