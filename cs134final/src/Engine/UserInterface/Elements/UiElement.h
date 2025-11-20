#pragma once
#include "ofEvent.h"

class UiElement
{
public:

    virtual void onEnable();
    virtual void onDisable();

    ofEvent<UiElement> clicked;
    ofEvent<UiElement> released;
};
