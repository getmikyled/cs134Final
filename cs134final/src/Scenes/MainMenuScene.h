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

        ufoObject = createGameObject<GameObject>();
        ufoObject->transform.position = ofVec3f(-13.75, 5.1f, 0);
        ufoObject->transform.rotation = ofVec3f(321, 0, 0);
        ufoModel = ufoObject->addComponent<Model>();
        ufoModel->load("models/objects/ufo.obj");
        std::cout<< ufoModel->model->getMesh(0).getNumVertices()<<std::endl;
    }   

    void onEnable() override;

    GameObject* ufoObject;
    Model* ufoModel;
};
