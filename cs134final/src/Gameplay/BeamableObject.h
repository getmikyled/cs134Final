#pragma once
#include "GameObject.h"
#include "Model.h"

class BeamableObject : public GameObject
{
public:
    BeamableObject()
    {
        model = addComponent<Model>();
        model->load("models/objects/testAnimal.obj");
    }

    Model* model;
};
