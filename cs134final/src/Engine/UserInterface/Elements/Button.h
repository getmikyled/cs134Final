#pragma once

#include "UiElement.h"

class Button : public UiElement
{
public:
    void onUpdate(ofEventArgs& args) override;
    void onDraw(ofEventArgs& args) override;

    bool inside(ofPoint point) override;
};
