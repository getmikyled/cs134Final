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
        cout << "Starting to load terrain" << endl;
        terrainModel = environment->addComponent<Model>();
        terrainModel->load("models/terrain/terrain.obj");
        cout << "Starting to load buildings" << endl;
        buildingsModel = environment->addComponent<Model>();
        buildingsModel->load("models/terrain/buildings_noid.obj");
        cout << "Starting to load roadsign" << endl;
        roadLampSignModel = environment->addComponent<Model>();
        roadLampSignModel->load("models/terrain/SM_roadlampsign.obj");
        cout << "Starting to load trees" << endl;
        treesFencesModel = environment->addComponent<Model>();
        treesFencesModel->load("models/terrain/treesandfence.obj");
        cout << "Finished loading all models" << endl;

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
        cout << "Starting to load octree" << endl;
        octree = new Octree();
        octree->staticMeshes.push_back(terrainModel);
        octree->staticMeshes.push_back(buildingsModel);
        octree->staticMeshes.push_back(roadLampSignModel);
        octree->create(20);
        std::cout << "FINISHED" << std::endl;
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
