#include "Player.h"
#include "InputSystem.h"
#include "Forces.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"

void Player::onEnable()
{
    Entity::onEnable();

    ofAddListener(ofEvents().mouseMoved, this, &Player::onMouseMoved);

    // Add gravity
    forces.push_back(new Force(getUpVector(), gravity, true));
}

void Player::onDisable()
{
    Entity::onDisable();

    ofRemoveListener(ofEvents().mouseMoved, this, &Player::onMouseMoved);
}


glm::vec3 Player::getFrontVector()
{
    glm::vec3 frontVector = (transform.position - camera->getPosition()).getNormalized();
    frontVector.y = 0;
    return frontVector;
}

glm::vec3 Player::getRightVector()
{
    return normalize(cross(getFrontVector(), getUpVector()));
}

glm::vec3 Player::getUpVector()
{
    return glm::vec3(ofVec3f(0,1,0) * transform.getRotation());
}


void Player::onUpdate(ofEventArgs& args)
{
    Entity::onUpdate(args);
    
    // Update movement force
    inputX = (InputSystem::getInstance().wPressed || InputSystem::getInstance().upArrowPressed)
        - (InputSystem::getInstance().sPressed || InputSystem::getInstance().downArrowPressed);

    inputY = InputSystem::getInstance().spacePressed;

    inputZ = (InputSystem::getInstance().dPressed || InputSystem::getInstance().rightArrowPressed)
        - (InputSystem::getInstance().aPressed || InputSystem::getInstance().leftArrowPressed);
    
    forces.push_back(new Force(getFrontVector(), speed*inputX, false));
    forces.push_back(new Force(getUpVector(), speed*inputY, false));
    forces.push_back(new Force(getRightVector(), speed*inputZ, false));
    
    // Update player
    float yawRadians = ofDegToRad(cameraYaw);
    float pitchRadians = ofDegToRad(cameraPitch);

    ofVec3f cameraOffset;
    cameraOffset.x = cameraDistance * cosf(pitchRadians) * sinf(yawRadians);
    cameraOffset.y = cameraDistance * sinf(pitchRadians);
    cameraOffset.z = cameraDistance * cosf(pitchRadians) * cosf(yawRadians);
     
    camera->setPosition(transform.position + cameraOffset);
    camera->lookAt(transform.position);
}

void Player::onMouseMoved(ofMouseEventArgs& args)
{
    float mouseX = args.x - previousMousePosition.x;
    float mouseY = previousMousePosition.y - args.y;

    previousMousePosition = ofVec2f(args.x, args.y);

    cameraYaw += mouseX * cameraSensitivityX;
    cameraPitch = std::clamp(cameraPitch + mouseY * cameraSensitivityY, 0.0f, 70.0f);
}
