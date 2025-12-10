#pragma once
#include "ofVec3f.h"

class Force
{
public:

    Force(ofVec3f argDirection, float argMagnitude, bool argIndefinite)
    {
        direction = argDirection;
        magnitude = argMagnitude;
        indefinite = argIndefinite;
    }

    Force()
    {
        indefinite = false;
        magnitude = 0;
        direction = ofVec3f(0, 0, 0);
    }
    virtual ~Force() {}
    
    ofVec3f direction;
    float magnitude;
    bool indefinite;
    
    virtual ofVec3f getForce()
    {
        return direction * magnitude;
    }
};

