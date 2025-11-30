#include "Model.h"

#include "GameObject.h"
#include "ofGraphics.h"

void Model::draw()
{
    ofPushMatrix();

    model->drawFaces();
    ofPopMatrix();
}

void Model::load(std::string path)
{
    model->load(path);
    model->setScaleNormalization(false);
    model->enableMaterials();
    model->enableNormals();
    mesh = model->getMesh(0);
}