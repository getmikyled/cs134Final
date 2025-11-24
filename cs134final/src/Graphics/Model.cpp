#include "Model.h"

#include "GameObject.h"
#include "ofGraphics.h"

void Model::draw()
{
    ofPushMatrix();
    ofMultMatrix(gameObject->transform.getTransform());

    model->drawFaces();
    ofPopMatrix();
}

void Model::load(std::string path)
{
    model->load(path);
}