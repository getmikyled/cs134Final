#include "SceneManager.h"

void SceneManager::update()
{
    if (activeScene != nullptr)
    {
        activeScene->update();   
    }
}

void SceneManager::draw()
{
    if (activeScene != nullptr)
    {
        activeScene->draw();
    }
}

void SceneManager::addGameObject(GameObject* gameObject)
{
    if (activeScene != nullptr)
    {
        activeScene->addGameObject(gameObject);
    }
    else
    {
        throw std::exception("No active scene");
    }
}
