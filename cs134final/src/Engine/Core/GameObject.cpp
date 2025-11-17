#include "GameObject.h"

void GameObject::draw()
{
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->draw();
    }
}

void GameObject::update()
{
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->update();
    }
}