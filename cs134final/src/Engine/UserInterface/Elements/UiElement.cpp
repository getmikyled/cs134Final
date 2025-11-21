#include "UiElement.h"

#include "ofAppRunner.h"

void UiElement::onEnable()
{
    ofAddListener(ofEvents().update, this, &UiElement::onUpdate);
    ofAddListener(ofEvents().draw, this, &UiElement::onDraw);
    ofAddListener(ofEvents().mousePressed, this, &UiElement::onMousePressed);
    ofAddListener(ofEvents().mouseReleased, this, &UiElement::onMouseReleased);
}

void UiElement::onDisable()
{
    ofRemoveListener(ofEvents().update, this, &UiElement::onUpdate);
    ofRemoveListener(ofEvents().draw, this, &UiElement::onDraw);
    ofRemoveListener(ofEvents().mousePressed, this, &UiElement::onMousePressed);
    ofRemoveListener(ofEvents().mouseReleased, this, &UiElement::onMouseReleased);
}

ofVec2f UiElement::getPosition()
{
    float width = static_cast<float>(ofGetWindowWidth());
    float height = static_cast<float>(ofGetWindowHeight());
    
    return ofVec2f(width * position->x, height * position->y);
}