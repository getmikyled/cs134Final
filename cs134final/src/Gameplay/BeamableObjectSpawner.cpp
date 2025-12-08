#include "BeamableObjectSpawner.h"

#include "BeamableObject.h"
#include "Scene.h"

void BeamableObjectSpawner::spawnBeamableObjects(Scene* scene, int argAmount)
{
    Box spawnBounds = scene->octree->getBounds();
    for (int i = 0; i < argAmount; i++)
    {
        TreeNode intersectedNode;
        Vector3 rayOrigin = Vector3(ofRandom(spawnBounds.min().x(), spawnBounds.max().x()),
            spawnBounds.max().y() + 5,
            ofRandom(spawnBounds.min().z(), spawnBounds.max().z())); 
        bool intersected = scene->octree->intersect(Ray(rayOrigin, Vector3(0, -1, 0)), scene->octree->root, intersectedNode);
        if (intersected)
        {
            for (int i = 0; i < scene->octree->staticMeshes.size(); i++)
            {
                if (intersectedNode.points[i].size() > 0)
                {
                    ofMesh& mesh = scene->octree->staticMeshes[i]->model->getMesh(0);
                    spawnBeamableObject(scene, mesh.getVertex(intersectedNode.points[i][0]));
                    
                }
            }
        }
        else
        {
            cout << "Failed to spawn object, no intersection." << endl;
        }
    }
}

void BeamableObjectSpawner::spawnBeamableObject(Scene* scene, ofVec3f position)
{
    BeamableObject* beamableObject = scene->createGameObject<BeamableObject>();
    beamableObject->transform.position = position;
    
}

