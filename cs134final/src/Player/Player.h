#pragma once

#include "Entity.h"
#include "ofEasyCam.h"
#include "ofxAssimpModelLoader.h"
#include "Graphics/Model.h"

class Player : public Entity
{
public:
    Player()
    {
        model = addComponent<Model>();
        model->load("models/objects/ufo.obj");

        camera = new ofEasyCam();
        camera->setPosition(ofVec3f(50, 0, 0));
        camera->disableMouseInput();
        camera->disableMouseMiddleButton();
        camera->setNearClip(.1f);
        camera->setFarClip(100000.0f);

        maxSpeed = 300;
    }

    ofEasyCam* camera;

    void onEnable() override;
    void onDisable() override;
    void onUpdate(ofEventArgs& args) override;
    void onMouseMoved(ofMouseEventArgs& args);

    glm::vec3 getFrontVector();
    glm::vec3 getRightVector();
    glm::vec3 getUpVector();

    ofVec2f previousMousePosition = ofVec2f(0, 0);
    float cameraDistance = 50;
    float cameraSensitivityX = 0.05f;
    float cameraSensitivityY = 0.05f;
    float cameraYaw = 0;
    float cameraPitch = 20;

    float inputX;
    float inputY;
    float inputZ;

    float gravity = -9.8f;
    float speed = 300;

    Model* model;
};
