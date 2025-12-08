#pragma once
#include "BeamableUtility.h"
#include "GameObject.h"
#include "Model.h"
#include "ofMain.h"
#include "Engine/Physics/Collider.h"

class BeamableObject : public GameObject
{
public:
    BeamableObject()
    {
        
        model = addComponent<Model>();
        model->load(BeamableUtility::getRandomModel());

        collider = addComponent<Collider>();
        collider->model = model;
        pickupSound.load("sfx/pop.mp3");
    }

    void onUpdate(ofEventArgs& args) override;
    void onCollisionTriggered(GameObject* argGameObject, ofVec3f normal) override;

    void onDisable();

    ofVec3f ufoPosition = ofVec3f(0, 0, 0);
    bool beamed = false;

    Model* model;
    Collider* collider;
    ofSoundPlayer pickupSound;
};
