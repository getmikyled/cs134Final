#pragma once
#include "GameObject.h"
#include "Scene.h"

class BeamableObjectSpawner : public GameObject
{
public:

    void spawnBeamableObjects(Scene* scene, int argAmount);
    void spawnBeamableObject(Scene* scene, ofVec3f position);
};
