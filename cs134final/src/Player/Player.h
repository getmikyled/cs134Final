#pragma once

#include "Entity.h"
#include "ofxAssimpModelLoader.h"
#include "Graphics/Model.h"

class Player : public Entity
{
public:
    Player()
    {
        model = addComponent<Model>();
        model->load("models/objects/car.obj");
    }
    
    void onUpdate(ofEventArgs& args) override;

    glm::vec3 getFrontVector();
    glm::vec3 getRightVector();
    glm::vec3 getUpVector();

    float inputX;
    float inputY;
    float inputZ;

    float speed = 300;

    Model* model;
};
