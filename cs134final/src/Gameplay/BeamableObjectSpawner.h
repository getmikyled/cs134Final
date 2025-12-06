#pragma once
#include "GameObject.h"

class BeamableObjectSpawner : public GameObject
{
public:
    void onEnable() override;

    void spawnBeamableObjects(int argAmount);

    int initialSpawnCount = 20;
};
