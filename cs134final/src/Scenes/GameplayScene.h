#pragma once

#include "GameOverUI.h"
#include "GameplayUI.h"
#include "PauseMenuUI.h"
#include "Scene.h"
#include "YouWinUI.h"
#include "Gameplay/BeamableObjectSpawner.h"
#include "Gameplay/LandingZone.h"
#include "Player/Player.h"

class GameplayScene : public Scene
{
public:
    GameplayScene()
    {
        // Set up ui
        gameplayUi = new GameplayUI();
        pauseMenuUi = new PauseMenuUI();
        youWinUi = new YouWinUI();
        gameOverUi = new GameOverUI();
        userInterface = gameplayUi;;

        // Set up environment
        environment = createGameObject<GameObject>();

        terrainModel = environment->addComponent<Model>();
        terrainModel->load("models/terrain/terrain.obj");

        buildingsModel = environment->addComponent<Model>();
        buildingsModel->load("models/terrain/buildings_noid.obj");
   
        roadLampSignModel = environment->addComponent<Model>();
        roadLampSignModel->load("models/terrain/SM_roadlampsign.obj");
      
        treesFencesModel = environment->addComponent<Model>();
        treesFencesModel->load("models/terrain/treesandfence.obj");

        

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



        

        

        // Set up landing zones
        landingZoneOne = createGameObject<LandingZone>();
        landingZoneOne->box->parameters[0] = Vector3(-71, 15, 35);
        landingZoneOne->box->parameters[1] = Vector3(-40, 30, 66);
        landingZoneTwo = createGameObject<LandingZone>();
        landingZoneTwo->box->parameters[0] = Vector3(45, 20, 25);
        landingZoneTwo->box->parameters[1] = Vector3(81, 30, 45);
        landingZoneThree = createGameObject<LandingZone>();
        landingZoneThree->box->parameters[0] = Vector3(-51, 45, -107);
        landingZoneThree->box->parameters[1] = Vector3(-25, 61, -81);
    }

    void onEnable() override;
    void onDisable() override;
    void onKeyPressed(ofKeyEventArgs& args);

    void draw(ofEventArgs& args) override;
    void update(ofEventArgs& args) override;

    GameplayUI* gameplayUi;
    PauseMenuUI* pauseMenuUi;
    YouWinUI* youWinUi;
    GameOverUI* gameOverUi;

    Model* terrainModel;
    Model* buildingsModel;
    Model* roadLampSignModel;
    Model* treesFencesModel;
    
    GameObject* environment;
    Player* player;
    Beam* beam;

    BeamableObjectSpawner* beamableObjectSpawner;

    LandingZone* landingZoneOne;
    LandingZone* landingZoneTwo;
    LandingZone* landingZoneThree;

    ofVec3f intersectedPoint = ofVec3f(0, 0, 0);

    vector<vector<glm::vec3>> vertices;
};
