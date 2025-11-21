#pragma once
#include "ofTrueTypeFont.h"
#include "UiElement.h"

class Label : public UiElement
{
public:
    Label()
    {
        font = new ofTrueTypeFont();
        font->load("fonts/JosefinSans-SemiBold.ttf", ofGetWindowWidth() * fontSize);
    }

    void onUpdate(ofEventArgs& args) override;
    void onDraw(ofEventArgs& args) override;
    bool inside(ofPoint point) override;

    float fontSize = 0.1f;
    std::string text = "Text";

private:
    ofTrueTypeFont* font;
};
