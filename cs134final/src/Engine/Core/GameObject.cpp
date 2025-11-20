#include "GameObject.h"

#include "ofEvents.h"

void GameObject::onEnable()
{
    ofAddListener(ofEvents().update, this, &GameObject::onUpdate);
    ofAddListener(ofEvents().draw, this, &GameObject::onDraw);
}

void GameObject::onDisable()
{
    ofRemoveListener(ofEvents().update, this, &GameObject::onUpdate);
    ofRemoveListener(ofEvents().draw, this, &GameObject::onDraw);
}

void GameObject::onDraw(ofEventArgs & args)
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