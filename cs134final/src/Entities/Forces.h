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
    
    ofVec3f direction;
    float magnitude;
    bool indefinite;
    virtual ofVec3f getForce()
    {
        return direction * magnitude;
    }
};
