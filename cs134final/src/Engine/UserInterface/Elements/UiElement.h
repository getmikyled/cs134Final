#pragma once
#include "ofEvent.h"
#include "ofEvents.h"
#include "ofRectangle.h"
#include "Transform.h"

class UiElement
{
public:
    virtual void onUpdate(ofEventArgs &args) {};
    virtual void onDraw(ofEventArgs &args) {};

    virtual void onEnable();
    virtual void onDisable();

    ofVec2f getPosition();
    
    virtual bool inside(ofPoint point) = 0;

    ofEvent<ofMouseEventArgs> mousePressedEvent;
    ofEvent<ofMouseEventArgs> mouseReleasedEvent;

    ofVec2f* position = new ofVec2f(0, 0);
    
protected:
    void onMousePressed(ofMouseEventArgs &args)
    {
        if (inside(ofVec2f(args.x, args.y)))
        {
            ofNotifyEvent(mousePressedEvent, args);
        }
    }
    void onMouseReleased(ofMouseEventArgs &args)
    {
        if (inside(ofVec2f(args.x, args.y)))
        {
            ofNotifyEvent(mouseReleasedEvent, args);
        }
    }
};
