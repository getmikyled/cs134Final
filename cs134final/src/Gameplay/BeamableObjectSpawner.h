#pragma once
#include "GameObject.h"
#include "Octree.h"

class BeamableObjectSpawner : public GameObject
{
public:

    void spawnBeamableObjects(Octree* octree, int argAmount);
    void spawnBeamableObject(ofVec3f position);
};
