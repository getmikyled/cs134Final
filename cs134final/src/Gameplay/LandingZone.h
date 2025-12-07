#pragma once
#include "box.h"
#include "Collider.h"
#include "GameObject.h"

class LandingZone : public GameObject
{
public:
    LandingZone()
    {
        box = new Box(Vector3(0, 0, 0), Vector3(0, 0, 0));

        collider = new Collider();
        collider->manualBounds = box;
    }
    
    void draw() override;
    
    Box* box;
    Collider* collider;
};
