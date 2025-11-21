#include "Player.h"
#include "InputSystem.h"
#include "Forces.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"


glm::vec3 Player::getFrontVector()
{
    return glm::vec3(ofVec3f(1,0,0) * transform.getRotation());
}

glm::vec3 Player::getRightVector()
{
    return glm::vec3(ofVec3f(0,0,1) * transform.getRotation());
}

glm::vec3 Player::getUpVector()
{
    return glm::vec3(ofVec3f(0,1,0) * transform.getRotation());
}


void Player::onUpdate(ofEventArgs& args)
{
    inputX = (InputSystem::getInstance().wPressed || InputSystem::getInstance().upArrowPressed)
        - (InputSystem::getInstance().sPressed || InputSystem::getInstance().downArrowPressed);

    inputY = InputSystem::getInstance().spacePressed;

    inputZ = (InputSystem::getInstance().dPressed || InputSystem::getInstance().rightArrowPressed)
        - (InputSystem::getInstance().aPressed || InputSystem::getInstance().leftArrowPressed);
    
    forces.push_back(new Force(getFrontVector(), speed*inputX, false));
    forces.push_back(new Force(getUpVector(), speed*inputY, false));
    forces.push_back(new Force(getRightVector(), speed*inputZ, false)); 

    Entity::onUpdate(args);
}

void Player::onDraw(ofEventArgs& args)
{
    ofPushMatrix();
    ofMultMatrix(transform.getTransform());

    ofDrawSphere(0, 0, 0, 200);
    
    ofPopMatrix();
}

