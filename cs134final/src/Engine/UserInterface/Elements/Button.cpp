#include "Button.h"

#include "ofAppRunner.h"
#include "ofGraphics.h"

void Button::onUpdate(ofEventArgs& event)
{
    // Call super method
    UiElement::onUpdate(event);
}

void Button::onDraw(ofEventArgs& event)
{
    // Call super method
    UiElement::onDraw(event);

    // Draw rectangle for button
    ofVec2f position = getPosition();
    //ofDrawRectangle(position.x, position.y, size.x, size.y);
}

// Check if point is inside bounds button
bool Button::inside(ofPoint point)
{
    ofVec2f position = getPosition();
    return true; /*point.x >= position.x && point.x <= position.x + size.x &&
        point.y >= position.y && point.y <= position.y + size.y;*/
}
