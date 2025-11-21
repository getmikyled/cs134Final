#pragma once
#include "MainMenuUI.h"
#include "Scene.h"

class MainMenuScene : public Scene
{
public:
    MainMenuScene()
    {
        userInterface = new MainMenuUI();
    }
};
