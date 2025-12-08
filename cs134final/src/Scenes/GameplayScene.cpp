#include "GameplayScene.h"

#include "GameManager.h"
#include "InputSystem.h"
#include "Engine/Octree/ray.h"

void GameplayScene::onEnable()
{
    Scene::onEnable();

    
    setUserInterface(gameplayUi);
    player->transform.position = ofVec3f(55, 28, 35);
    player->rigidbody->velocity = ofVec3f(0, 0, 0);

    ofAddListener(ofEvents().keyPressed, this, &GameplayScene::onKeyPressed);
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
                ofMesh& mesh = octree->staticMeshes[i]->model->getMesh(0);
                intersectedPoint = mesh.getVertex(intersectedNode.points[i][0]);
                gameplayUi->setAltitude(int(playerPosition.y() - intersectedPoint.y));
            }
        }
    }
    else
    {
        gameplayUi->setAltitude(-1);
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