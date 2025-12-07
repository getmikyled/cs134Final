#include "LandingZone.h"

#include "of3dGraphics.h"
#include "ofxInputField.h"

void LandingZone::draw()
{
    GameObject::draw();
    
    ofNoFill();
    ofVec3f pos = ofVec3f(box->center().x(), box->center().y(), box->center().z());
    float width = box->parameters[1].x() - box->parameters[0].x();
    float height = box->parameters[1].y() - box->parameters[0].y();
    float depth = box->parameters[1].z() - box->parameters[0].z();
    ofDrawBox(pos, width, height, depth);
}
