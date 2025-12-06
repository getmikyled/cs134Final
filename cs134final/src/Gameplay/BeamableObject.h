#pragma once
#include "GameObject.h"
#include "Model.h"
#include "Engine/Physics/Collider.h"

class BeamableObject : public GameObject
{
public:
    BeamableObject()
    {
        
        model = addComponent<Model>();
        model->load("models/objects/testAnimal.obj");

        collider = addComponent<Collider>();
        collider->model = model;
    }

    void onUpdate(ofEventArgs& args) override;
    void onCollisionTriggered(GameObject* argGameObject, ofVec3f normal) override;

    ofVec3f ufoPosition = ofVec3f(0, 0, 0);
    bool beamed = false;

    Model* model;
    Collider* collider;
};
