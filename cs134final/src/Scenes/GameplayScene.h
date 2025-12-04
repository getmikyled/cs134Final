#pragma once

#include "GameplayUI.h"
#include "Scene.h"
#include "Player/Player.h"

class GameplayScene : public Scene
{
public:
    GameplayScene()
    {

        // Set up ui
        gameplayUi = new GameplayUI();
        userInterface = gameplayUi;
        
        player = createGameObject<Player>();
        player->transform.position = ofVec3f(0, 50, 0);
        beam = createGameObject<Beam>();
        player->beam = beam;

        
        environment = createGameObject<GameObject>();

        terrainModel = environment->addComponent<Model>();
        terrainModel->load("models/terrain/terrain.obj");

        buildingsModel = environment->addComponent<Model>();
        buildingsModel->load("models/terrain/buildings_noid.obj");
   
        roadLampSignModel = environment->addComponent<Model>();
        roadLampSignModel->load("models/terrain/SM_roadlampsign.obj");
      
        treesFencesModel = environment->addComponent<Model>();
        treesFencesModel->load("models/terrain/treesandfence.obj");
        
        mainCamera = player->camera;

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
        octree->staticMeshes.push_back(treesFencesModel);
        octree->create(20);
        addGameObject(octree);
        std::cout << "FINISHED" << std::endl;
    }

    void draw(ofEventArgs& args) override;
    void update(ofEventArgs& args) override;

    GameplayUI* gameplayUi;

    Model* terrainModel;
    Model* buildingsModel;
    Model* roadLampSignModel;
    Model* treesFencesModel;
    
    GameObject* environment;
    Player* player;
    Beam* beam;
};
