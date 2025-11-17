#pragma once

#include <glm/ext/matrix_transform.hpp>

#include "ofMatrix4x4.h"
#include "ofPoint.h"

class Transform
{
public:
    Transform()
    {
        position = glm::vec3(0, 0, 0);
        rotation = 0;
        scale = glm::vec3(1, 1, 1);
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
        return glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
    }
    
    ofVec3f position;
    float rotation;
    ofVec3f scale;
};
