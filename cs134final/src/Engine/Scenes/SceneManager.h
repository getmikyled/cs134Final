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

    void update();
    void draw();
    void addGameObject(GameObject* gameObject);

    Scene* activeScene = nullptr;
    std::vector<Scene*> scenes;

private:
    SceneManager() {} // Private constructor
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;
};
