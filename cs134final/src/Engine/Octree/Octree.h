#pragma once

#include "GameObject.h"
#include "ofMain.h"
#include "Engine/Octree/box.h"
#include "Graphics/Model.h"

//--------------------------------------------------------------
//
//  Kevin M. Smith
//
//  Simple Octree Implementation 11/10/2020
// 
//  Copyright (c) by Kevin M. Smith
//  Copying or use without permission is prohibited by law.
//

class TreeNode {
public:
    Box box;
    vector<vector<int>> points;
    vector<TreeNode> children;
};

class Octree : public GameObject
{
public:

    void draw() override;

    void create(int numLevels);
    void subdivide(TreeNode & node, int numLevels, int level);
    bool intersect(const Ray &, const TreeNode & node, TreeNode & nodeRtn);
    bool intersect(Box &, TreeNode & node, vector<Box> & boxListRtn);
    void draw(TreeNode & node, int numLevels, int level);
    void draw(int numLevels, int level) {
        draw(root, numLevels, level);
    }
    
    static void drawBox(const Box &box);
    static Box meshBounds(const ofMesh &);
    int getMeshPointsInBox(const ofMesh &mesh, const vector<int> & points, Box & box, vector<int> & pointsRtn);
    int getMeshFacesInBox(const ofMesh &mesh, const vector<int> & faces, Box & box, vector<int> & facesRtn);
    void subDivideBox8(const Box &b, vector<Box> & boxList);

    vector<Model*> staticMeshes;
    vector<Model*> dynamicMeshes;
    ofMesh mesh;
    TreeNode root;
    
};
