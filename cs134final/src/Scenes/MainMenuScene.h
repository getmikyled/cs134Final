#pragma once
#include "Model.h"
#include "..\UI\MainMenuUI.h"
#include "Scene.h"

class MainMenuScene : public Scene
{
public:
    MainMenuScene()
    {
        userInterface = new MainMenuUI();

        mainCamera = new ofEasyCam();
        mainCamera->setPosition(ofVec3f(0, 0, -30));
        mainCamera->lookAt(ofVec3f(0, 0, 0));
        mainCamera->disableMouseInput();

        // Set up ufo object
        ufoObject = createGameObject<GameObject>();
        ufoObject->transform.position = ofVec3f(-13.75, 5.1f, 0);
        ufoObject->transform.rotation = ofVec3f(321, 0, 0);
        ufoModel = ufoObject->addComponent<Model>();
        ufoModel->load("models/objects/ufo.obj");
        ufoModel->color = ofColor(255, 255, 255, 0);
        beamObject = createGameObject<GameObject>();
        beamObject->transform.position = ofVec3f(-13.75, 5.1f, 0);
        beamObject->transform.rotation = ofVec3f(321, 0, 0);
        beamModel = ufoObject->addComponent<Model>();
        beamModel->load("models/objects/ufo_beam.obj");
        beamModel->color = ofColor(0, 0, 0, 0);

        // Set up lighting
        mainLight = new ofLight();
        mainLight->setup();
        mainLight->setDirectional();
        mainLight->setAmbientColor(ofColor::purple);
        mainLight->setDiffuseColor(ofColor::white);
        mainLight->setSpecularColor(ofColor::white);
        mainLight->setPosition(ofVec3f(10, 0, 10));
        lights.push_back(mainLight);
    }   

    void onEnable() override;

    GameObject* ufoObject;
    Model* ufoModel;
    GameObject* beamObject;
    Model* beamModel;

    ofLight* mainLight;
};
