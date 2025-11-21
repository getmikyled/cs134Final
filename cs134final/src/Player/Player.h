#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
    void onUpdate(ofEventArgs& args) override;
    void onDraw(ofEventArgs& args) override;

    glm::vec3 getFrontVector();
    glm::vec3 getRightVector();
    glm::vec3 getUpVector();

    float inputX;
    float inputY;
    float inputZ;

    float speed = 10;

    
    
};
