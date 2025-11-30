#pragma once
#include "Component.h"
#include "ofxAssimpModelLoader.h"

class Model : public Component
{
public:
    Model()
    {
        model = new ofxAssimpModelLoader();
    }

    void load(std::string path);
    void draw() override;
    
    ofxAssimpModelLoader* model;
    ofMesh mesh;
};
