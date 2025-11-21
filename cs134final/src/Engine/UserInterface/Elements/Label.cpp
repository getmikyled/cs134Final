#include "Label.h"

void Label::onUpdate(ofEventArgs& args)
{
    font->load("fonts/JosefinSans-SemiBold.ttf", ofGetWindowWidth() * fontSize);
}

void Label::onDraw(ofEventArgs& args)
{
    ofVec2f pos = getPosition();
    ofRectangle bounds = font->getStringBoundingBox(text, pos.x, pos.y);
    font->drawString(text, pos.x, pos.y + bounds.height);
}

bool Label::inside(ofPoint point)
{
    ofVec2f pos = getPosition();
    ofRectangle bounds = font->getStringBoundingBox(text, pos.x, pos.y);
    return point.x >= pos.x && point.x <= pos.x + bounds.width &&
        point.y >= pos.y && point.y <= pos.y + bounds.height;
}