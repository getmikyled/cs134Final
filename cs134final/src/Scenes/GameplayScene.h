#pragma once
#include "Scene.h"
#include "Player/Player.h"

class GameplayScene : public Scene
{
public:
    GameplayScene()
    {
        player = createGameObject<Player>();
        environment = createGameObject<GameObject>();
        Model* terrainModel = environment->addComponent<Model>();
        terrainModel->load("models/terrain/terrain.obj");
        Model* buildingsModel = environment->addComponent<Model>();
        buildingsModel->load("models/terrain/buildings_noid.obj");
        Model* roadLampSignModel = environment->addComponent<Model>();
        roadLampSignModel->load("models/terrain/SM_roadlampsign.obj");
        Model* treesFencesModel = environment->addComponent<Model>();
        treesFencesModel->load("models/terrain/treesandfence.obj");

        mainCamera = new ofEasyCam();
        mainCamera->enableMouseInput();
        mainCamera->setPosition(100, 0, 100);
        mainCamera->lookAt(glm::vec3(0, 0, 0));
        mainCamera->setNearClip(.1f);
        mainCamera->setFarClip(100000.0f);

        ofLight* directionalLight = new ofLight();
        directionalLight->setup();
        directionalLight->enable();
        directionalLight->setDirectional();
        lights.push_back(directionalLight);
    }

    GameObject* environment;
    Player* player;
};
