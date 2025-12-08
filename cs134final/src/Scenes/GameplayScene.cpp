#include "GameplayScene.h"

#include "GameManager.h"
#include "InputSystem.h"
#include "Engine/Octree/ray.h"

void GameplayScene::update(ofEventArgs& args)
{
    Scene::update(args);

    if (InputSystem::getInstance().ctrlPressed)
    {
        GameManager::getInstance().setGameState(PAUSED);
    }
    else
    {
        GameManager::getInstance().setGameState(GAMEPLAY);
    }

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
    ofDrawSphere(intersectedPoint, 2);
    mainCamera->end();
}