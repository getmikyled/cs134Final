#include "SceneManager.h"

void SceneManager::addScene(Scene* scene)
{
    scenes.push_back(scene);
}

Scene* SceneManager::getActiveScene()
{
    return activeScene;
}

void SceneManager::setActiveScene(Scene* scene)
{
    // Disable currently active scene
    if (activeScene != nullptr)
    {
        activeScene->onDisable();
        activeScene->isActive = false;
    }

    // Enable currently active scene
    activeScene = scene;
    activeScene->onEnable();
    activeScene->isActive = true;
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
