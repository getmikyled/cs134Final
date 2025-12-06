#include "BeamableObjectSpawner.h"

void BeamableObjectSpawner::spawnBeamableObjects(Octree* octree, int argAmount)
{
    Box spawnBounds = octree->getBounds();
    for (int i = 0; i < argAmount; i++)
    {
        TreeNode intersectedNode;
        Vector3 rayOrigin = Vector3(ofRandom(spawnBounds.min().x(), spawnBounds.max().x()),
            spawnBounds.max().y(),
            ofRandom(spawnBounds.min().z(), spawnBounds.max().z())); 
        bool intersected = octree->intersect(Ray(rayOrigin, Vector3(0, -1, 0)), octree->root, intersectedNode);
        if (intersected)
        {
            for (int i = 0; i < octree->staticMeshes.size(); i++)
            {
                if (intersectedNode.points[i].size() > 0)
                {
                    ofMesh& mesh = octree->staticMeshes[i]->model->getMesh(0);
                    spawnBeamableObject(mesh.getVertex(intersectedNode.points[i][0]));
                }
            }
        }
        else
        {
            cout << "Failed to spawn object, no intersection." << endl;
        }
    }
}

void BeamableObjectSpawner::spawnBeamableObject(ofVec3f position)
{
    
}

