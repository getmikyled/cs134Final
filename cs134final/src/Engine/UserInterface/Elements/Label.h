#pragma once
#include "ofTrueTypeFont.h"
#include "UiElement.h"

class Label : public UiElement
{
public:
    Label(float fontsize)
    {
        font = new ofTrueTypeFont();
        fontSize = fontsize;
        currentWindowWidth = ofGetWindowWidth();
        font->load("fonts/JosefinSans-SemiBold.ttf", currentWindowWidth * fontSize);
    }

    void onUpdate(ofEventArgs& args) override;
    void onDraw(ofEventArgs& args) override;
    bool inside(ofPoint point) override;

    ofColor fontColor = ofColor::white;
    float fontSize = 0.1f;
    std::string text = "Text";
    int currentWindowWidth;

private:
    ofTrueTypeFont* font;
};
