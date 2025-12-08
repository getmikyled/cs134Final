#pragma once

#include "Beam.h"
#include "GameObject.h"
#include "ofEasyCam.h"
#include "ofxAssimpModelLoader.h"
#include "Engine/Physics/Collider.h"
#include "Engine/Physics/Rigidbody.h"
#include "Graphics/Model.h"

class Player : public GameObject
{
public:
    Player()
    {
        // Initialize ufo model and collider
        ufoModel = addComponent<Model>();
        ufoModel->load("models/objects/ufo.obj");
        ufoModel->color = ofColor(255, 255, 255, 255);
        
        ufoCollider = addComponent<Collider>();
        ufoCollider->model = ufoModel;
        
        // Initialize rigidbody
        rigidbody = addComponent<Rigidbody>();
        rigidbody->maxSpeed = 10;
        
        // Initialize camera
        camera = new ofEasyCam();
        camera->setPosition(ofVec3f(50, 0, 0));
        camera->disableMouseInput();
        camera->disableMouseMiddleButton();
        camera->setNearClip(.1f);
        camera->setFarClip(100000.0f);

        transform.scale = ofVec3f(.5, .5, .5);
        ufoCollider->collisionSizeMult = .9;
    }

    ofEasyCam* camera;

    void onEnable() override;
    void onDisable() override;
    void onUpdate(ofEventArgs& args) override;
    void onMouseMoved(ofMouseEventArgs& args);
    void onCollisionTriggered(GameObject* argGameObject, ofVec3f normal) override;

    void draw();

    glm::vec3 getFrontVector();
    glm::vec3 getRightVector();
    glm::vec3 getUpVector();

    void onCrashLanding();

    // Components
    Rigidbody* rigidbody;
    Model* ufoModel;
    Collider* ufoCollider;

    Beam* beam;

    ofVec2f previousMousePosition = ofVec2f(0, 0);
    float cameraDistance = 15;
    float cameraSensitivityX = 0.05f;
    float cameraSensitivityY = 0.05f;
    float cameraYaw = 0;
    float cameraPitch = 20;

    float crashVelocity = 4;

    float inputX;
    float inputY;
    float inputZ;

    float gravity = -30;
    float speed = 100;

    float maxTiltAngle = 50;
    float tiltSpeedFactor = -2;

    bool inLandingZone = false;

};
