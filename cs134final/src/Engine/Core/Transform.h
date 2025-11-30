#pragma once

#include <glm/ext/matrix_transform.hpp>

#include "ofMatrix4x4.h"
#include "ofPoint.h"

class Transform
{
public:
    Transform()
    {
        position = ofVec3f(0, 0, 0);
        rotation = ofVec3f(0, 0, 0);
        scale = ofVec3f(1, 1, 1);
    }
    
    ofMatrix4x4 getTransform()
    {
        ofMatrix4x4 T = glm::translate(glm::mat4(1.0f), (glm::vec3)position);
        ofMatrix4x4 R = getRotation();
        ofMatrix4x4 S = glm::scale(glm::mat4(1.0f), (glm::vec3)scale);
        
        return R * S * T;
    }

    ofMatrix4x4 getRotation()
    {
        ofMatrix4x4 rotationMatrix;
        rotationMatrix.makeRotationMatrix(
            rotation.x, ofVec3f(1, 0, 0),
            rotation.y, ofVec3f(0, 1, 0),
            rotation.z, ofVec3f(0, 0, 1)
        );
        return rotationMatrix;
    }
    
    ofVec3f position;
    ofVec3f rotation;
    ofVec3f scale;
};
