#pragma once
#include "GameObject.h"
#include "Model.h"
#include "Engine/Physics/Collider.h"

class Beam : public GameObject
{
public:
    Beam()
    {
        // Initialize ufo beam
        model = addComponent<Model>();
        model->load("models/objects/ufo_beam.obj");
        model->color = ofColor(255, 255, 255, 0);

        collider = addComponent<Collider>();
        collider->model = model;
    }
    
    Model* model;
    Collider* collider;
};
