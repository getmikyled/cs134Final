#include "GameObject.h"

#include "ofEvents.h"
#include "Engine/Physics/Collider.h"

void GameObject::onEnable()
{
    ofAddListener(ofEvents().update, this, &GameObject::onUpdate);
}

void GameObject::onDisable()
{
    ofRemoveListener(ofEvents().update, this, &GameObject::onUpdate);;
}

void GameObject::draw()
{
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->draw();
    }
}

void GameObject::onUpdate(ofEventArgs & args)
{
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->update();
    }
}

void GameObject::onCollisionTriggered(GameObject* argGameObject)
{
    
}

bool GameObject::canCollideWith(GameObject* argGameObject)
{
    // Check if object has a collider
    Collider* collider = getComponent<Collider>();
    if (collider != nullptr)
    {
        // Check if the collision was already triggered
        return collider->collidedObjects.find(argGameObject) == collider->collidedObjects.end();
    }

    return false;
}