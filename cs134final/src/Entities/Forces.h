#pragma once
#include "ofVec3f.h"

class Force
{
public:

    Force(ofVec3f argDirection, float argMagnitude, bool argIndefinite, bool argRotation = false)
    {
        direction = argDirection;
        magnitude = argMagnitude;
        indefinite = argIndefinite;
        rotation = argRotation;
    }
    
    ofVec3f direction;
    float magnitude;
    bool indefinite;
    bool rotation;
    
    virtual ofVec3f getForce()
    {
        return direction * magnitude;
    }
};

