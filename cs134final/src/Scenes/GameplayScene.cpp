#include "GameplayScene.h"

#include "GameManager.h"
#include "InputSystem.h"
#include "Engine/Octree/ray.h"

void GameplayScene::onEnable()
{
    

    // Set up beamable object spawner
    beamableObjectSpawner = new BeamableObjectSpawner();
    beamableObjectSpawner->spawnBeamableObjects(this, 70);

    GameManager::getInstance().score = 0;
        
    // Set up player
    player = createGameObject<Player>();
    player->transform.position = ofVec3f(55, 24.8, 35);
    player->rigidbody->velocity = ofVec3f(0, 0, 0);

    beam = createGameObject<Beam>();
    player->beam = beam;
    lights.push_back(beam->light);

    topDownCam = new ofEasyCam();
    topDownCam->setPosition(ofVec3f(50,100,50));
    topDownCam->lookAt(ofVec3f(0, 0, 0));

    cityViewCam = new ofEasyCam();
    cityViewCam->setPosition(ofVec3f(25,10,25));
    cityViewCam->lookAt(ofVec3f(0, 15, 0));

    Scene::onEnable();
        
    mainCamera = player->camera;
    /*mainCamera = new ofEasyCam();
    mainCamera->enableMouseInput();*/

    
    setUserInterface(gameplayUi);
    /*player->transform.position = ofVec3f(55, 28, 35);
    player->rigidbody->velocity = ofVec3f(0, 0, 0);*/

    

    ofAddListener(ofEvents().keyPressed, this, &GameplayScene::onKeyPressed);

    for (int i = 0; i < octree->staticMeshes.size(); i++)
    {
        vertices.push_back(octree->staticMeshes[i]->mesh.getVertices());
    }
    
}

void GameplayScene::onDisable()
{
    Scene::onDisable();

    ofRemoveListener(ofEvents().keyPressed, this, &GameplayScene::onKeyPressed);
}


void GameplayScene::onKeyPressed(ofKeyEventArgs& args)
{
    if (GameManager::getInstance().gameState == GAMEPLAY && args.key == OF_KEY_LEFT_CONTROL)
    {
        if (userInterface == pauseMenuUi)
        {
            setUserInterface(gameplayUi);
        }
        else if (userInterface == gameplayUi)
        {
            setUserInterface(pauseMenuUi);
        }
    }

    switch (args.key)
    {
        case '1':
            mainCamera = player->camera;
            break;
        case '2':
            mainCamera = topDownCam;
            break;
        case '3':
            mainCamera = cityViewCam;
            break;
        default:
            break;
    }
}


void GameplayScene::update(ofEventArgs& args)
{
    Scene::update(args);

    // Altitude sensor
    TreeNode intersectedNode;
    Vector3 playerPosition = Vector3(player->transform.position.x, player->transform.position.y, player->transform.position.z);
    bool intersected = octree->intersect(Ray(playerPosition, Vector3(0, -1, 0)), octree->root, intersectedNode);
    if (intersected)
    {
        for (int i = 0; i < octree->staticMeshes.size(); i++)
        {
            if (intersectedNode.points[i].size() > 0)
            {
                intersectedPoint = vertices[i][0];
                gameplayUi->setAltitude(int(playerPosition.y() - intersectedPoint.y));
            }
        }
    }
    else
    {
        //gameplayUi->setAltitude(-1);
    }
}

void GameplayScene::draw(ofEventArgs& args)
{
    Scene::draw(args);

    mainCamera->begin();
    ofSetColor(ofColor::lightGreen);
    //ofDrawSphere(intersectedPoint, 2);
    mainCamera->end();
}