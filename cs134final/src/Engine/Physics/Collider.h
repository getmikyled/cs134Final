#pragma once
#include <unordered_set>

#include "box.h"
#include "Component.h"
#include "Model.h"

class Collider : public Component
{
public:

    void update() override;
    
    Box getBounds();

    Box* manualBounds;
    Model* model;
    std::unordered_set<GameObject*> collidedObjects;
};
