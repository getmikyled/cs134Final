#include "UserInterface.h"

void UserInterface::onEnable()
{
    // Enable all UI elements
    for (UiElement* element : uiElements)
    {
        element->onEnable();
    }
}

void UserInterface::onDisable()
{
    // Disable all UI elements
    for (UiElement* element : uiElements)
    {
        element->onDisable();
    }
}

void UserInterface::update()
{
    
}

void UserInterface::draw()
{
    
}
