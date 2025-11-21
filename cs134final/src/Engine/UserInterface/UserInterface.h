#pragma once
#include <vector>

#include "Elements/UiElement.h"

class UserInterface
{
public:
    
    void onEnable();
    void onDisable();
    void update();
    void draw();

    std::vector<UiElement*> uiElements;
};
