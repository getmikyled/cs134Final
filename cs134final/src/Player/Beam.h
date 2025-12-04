#pragma once
#include "GameObject.h"
#include "Model.h"
#include "ofLight.h"
#include "Engine/Physics/Collider.h"

class Beam : public GameObject
{
public:
    Beam()
    {
        // Initialize ufo beam
        model = addComponent<Model>();
        model->load("models/objects/ufo_beam.obj");
        model->color = ofColor(0, 255, 0, 100);

        collider = addComponent<Collider>();
        collider->model = model;

        light = new ofLight();
        light->setup();
        light->setPointLight();
        light->setAttenuation(2.0f, 0.001f, 0.01f);
        //  light->setAmbientColor(ofColor::green);
        light->setDiffuseColor(ofColor::green);
        light->setSpecularColor(ofColor::green);
    }

    void onUpdate(ofEventArgs& args) override;
    
    Model* model;
    Collider* collider;
    ofLight* light;
};
