#include "BeamableObjectSpawner.h"

#include "BeamableObject.h"
#include "Scene.h"

void BeamableObjectSpawner::spawnBeamableObjects(Scene* scene, int argAmount)
{
    int nummodels = scene->octree->staticMeshes.size();
    vector<ofMesh> meshes;
    vector<vector<glm::vec3>> vertices;
    
    for (int i = 0; i < nummodels; i++)
    {
        vertices.push_back(scene->octree->staticMeshes[i]->mesh.getVertices());
    }
    
    Box spawnBounds = scene->octree->root.box;
    for (int i = 0; i < argAmount; i++)
    {
        TreeNode intersectedNode;
        Vector3 rayOrigin = Vector3(ofRandom(spawnBounds.min().x()+100, spawnBounds.max().x()-100),
            spawnBounds.max().y() + 5,
            ofRandom(spawnBounds.min().z()+100, spawnBounds.max().z()-100)); 
        bool intersected = scene->octree->intersect(Ray(rayOrigin, Vector3(0, -1, 0)), scene->octree->root, intersectedNode);
        if (intersected)
        {
            
            for (int i = nummodels-1; i >= 0; i--)
            {
                if (intersectedNode.points[i].size() > 0)
                {
                    
                    spawnBeamableObject(scene, vertices[i][intersectedNode.points[i][0]]);
                    break;
                    
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

