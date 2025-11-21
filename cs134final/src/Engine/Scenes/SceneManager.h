#pragma once
#include <vector>

#include "Scene.h"

class SceneManager
{
public:
    static SceneManager& getInstance() {
        static SceneManager instance;
        return instance;
    }
    
    void addGameObject(GameObject* gameObject);

    Scene* getActiveScene();
    void setActiveScene(int index);

    void addScene(Scene* scene);

private:
    SceneManager() {} // Private constructor
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

    Scene* activeScene;
    std::vector<Scene*> scenes;
};
