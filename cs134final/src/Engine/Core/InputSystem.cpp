#include "InputSystem.h"

#include "ofEvents.h"

void InputSystem::onKeyPressed(int key)
{
    // Cache current key pressed
    switch (key)
    {
    case OF_KEY_LEFT_CONTROL:
        ctrlPressed = true;
        break;
    case OF_KEY_UP:
        upArrowPressed = true;
        break;
    case OF_KEY_DOWN:
        downArrowPressed = true;
        break;
    case OF_KEY_LEFT:
        leftArrowPressed = true;
        break;
    case OF_KEY_RIGHT:
        rightArrowPressed = true;
    case ' ':
        spacePressed = true;
        break;
    }
}

void InputSystem::onKeyReleased(int key)
{
    // No current key pressed
    switch (key)
    {
    case OF_KEY_LEFT_CONTROL:
        ctrlPressed = false;
        break;
    case OF_KEY_UP:
        upArrowPressed = false;
        break;
    case OF_KEY_DOWN:
        downArrowPressed = false;
        break;
    case OF_KEY_LEFT:
        leftArrowPressed = false;
        break;
    case OF_KEY_RIGHT:
        rightArrowPressed = false;
        break;
    case ' ':
        spacePressed = false;
        break;
    }
}

void InputSystem::onMouseMoved(int x, int y)
{
    mousePosition = ofVec2f(x, y);
}

void InputSystem::onMouseDragged(int x, int y, int button)
{
    
}

void InputSystem::onMousePressed(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT)
    {
        leftClickPressed = true;
    }
}

void InputSystem::onMouseReleased(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT)
    {
        leftClickPressed = false;
    }
}
