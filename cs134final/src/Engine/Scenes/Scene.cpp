#include "Scene.h"

#include "../../Entities/Entity.h"

void Scene::update()
{
    // Update all game objects in scene
    auto gameObject = gameObjects.begin();

    while (gameObject != gameObjects.end())
    {
        // Erase if age exceeds lifespan
        if ((*gameObject)->pendingDestroy)
        {
            (*gameObject)->onDestroy();
            gameObject = gameObjects.erase(gameObject); // erase returns the next iterator
        }
        // Otherwise, integrate game object
        else
        {
            (*gameObject)->update();
            ++gameObject;
        }
    }

    // Queue pending game objects - we use it because we don't want to modify gameObjects iterator while its updating
    for (auto* pending : pendingGameObjects)
    {
        gameObjects.emplace_back(pending);
    }
    pendingGameObjects.clear();
    
    calculateCollisions();
}

void Scene::draw()
{
    // Draw all game objects in scene
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void Scene::calculateCollisions()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (Entity* entity = dynamic_cast<Entity*>(gameObjects[i]))
        {
            if (entity->physicsEnabled)
            {
                for (int j = 0; j < gameObjects.size(); j++)
                {
                    if (i != j)
                    {
                        if (Entity* otherEntity = dynamic_cast<Entity*>(gameObjects[j]))
                        {
                            if (otherEntity->physicsEnabled && entity->canCollideWith(otherEntity))
                            {
                                float distance = ofDist(entity->transform.position.x, entity->transform.position.y,
                                    otherEntity->transform.position.x, otherEntity->transform.position.y);
                                if (distance < entity->radius + otherEntity->radius)
                                {
                                    entity->onCollisionTriggered(otherEntity);
                                }
                            }
                        }
                    }
                }   
            }
        }
    }
}
