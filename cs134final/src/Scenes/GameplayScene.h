#pragma once

#include "Scene.h"
#include "Engine/Octree/Octree.h"
#include "Player/Player.h"

class GameplayScene : public Scene
{
public:
    GameplayScene()
    {
        player = createGameObject<Player>();
        environment = createGameObject<GameObject>();
        terrainModel = environment->addComponent<Model>();
        terrainModel->load("models/terrain/terrain.obj");
        buildingsModel = environment->addComponent<Model>();
        buildingsModel->load("models/terrain/buildings_noid.obj");
        roadLampSignModel = environment->addComponent<Model>();
        roadLampSignModel->load("models/terrain/SM_roadlampsign.obj");
        treesFencesModel = environment->addComponent<Model>();
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

        octree = new Octree();
        addGameObject(octree);
        octree->staticMeshes.push_back(terrainModel);
        octree->staticMeshes.push_back(buildingsModel);
        octree->staticMeshes.push_back(roadLampSignModel);
        octree->staticMeshes.push_back(treesFencesModel);
        octree->create(20);
    }

    void draw(ofEventArgs& args) override;
    void update(ofEventArgs& args) override;

    Model* terrainModel;
    Model* buildingsModel;
    Model* roadLampSignModel;
    Model* treesFencesModel;

    Octree* octree;
    GameObject* environment;
    Player* player;
};
