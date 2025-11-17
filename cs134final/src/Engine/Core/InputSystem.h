#pragma once
#include "ofVec3f.h"

class InputSystem
{
public:

    static InputSystem& getInstance() {
        static InputSystem instance;
        return instance;
    }

    void onKeyPressed(int key);
    void onKeyReleased(int key);
    void onMouseMoved(int x, int y);
    void onMouseDragged(int x, int y, int button);
    void onMousePressed(int x, int y, int button);
    void onMouseReleased(int x, int y, int button);

    ofVec2f mousePosition;
    bool leftClickPressed = false;

    bool spacePressed = false;
    bool ctrlPressed = false;
    bool leftArrowPressed = false;
    bool rightArrowPressed = false;
    bool upArrowPressed = false;
    bool downArrowPressed = false;
    
private:
    InputSystem() {} // Private constructor
    InputSystem(const InputSystem&) = delete;
    InputSystem& operator=(const InputSystem&) = delete;
};
