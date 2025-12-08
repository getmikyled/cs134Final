#include "Player.h"
#include "InputSystem.h"
#include "LandingZone.h"
#include "Octree.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"

void Player::onEnable()
{
    GameObject::onEnable();

    ofAddListener(ofEvents().mouseMoved, this, &Player::onMouseMoved);

    // Add gravity
    rigidbody->forces.push_back(new Force(getUpVector(), gravity, true));
}

void Player::onDisable()
{
    GameObject::onDisable();

    ofRemoveListener(ofEvents().mouseMoved, this, &Player::onMouseMoved);
    
    rigidbody->forces.clear();
}

void Player::onCollisionTriggered(GameObject* argGameObject, ofVec3f normal)
{
    GameObject::onCollisionTriggered(argGameObject, normal);

    Octree* octree = dynamic_cast<Octree*>(argGameObject);
    if (octree != nullptr)
    {
        // Handle crash type
        if (rigidbody->velocity.length() > crashVelocity)
        {
            onCrashLanding();
        }

        // Perform collision reaction
        transform.position += normal;
        rigidbody->velocity = .5 * (rigidbody->velocity - 2 * rigidbody->velocity.dot(normal) * normal);
    }

    LandingZone* landingZone = dynamic_cast<LandingZone*>(argGameObject);
    inLandingZone = landingZone != nullptr;
}

void Player::onCrashLanding()
{
    // Endlessette add code here
    cout << "CRASH LANDING" << endl;
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
    GameObject::onUpdate(args);

    // Update beam
    beam->transform.position = transform.position;
    beam->transform.rotation = transform.rotation;
    
    // Update movement force
    inputX = (InputSystem::getInstance().wPressed || InputSystem::getInstance().upArrowPressed)
        - (InputSystem::getInstance().sPressed || InputSystem::getInstance().downArrowPressed);

    inputY = InputSystem::getInstance().spacePressed;

    inputZ = (InputSystem::getInstance().dPressed || InputSystem::getInstance().rightArrowPressed)
        - (InputSystem::getInstance().aPressed || InputSystem::getInstance().leftArrowPressed);
    
    rigidbody->forces.push_back(new Force(getFrontVector(), speed*inputX, false));
    rigidbody->forces.push_back(new Force(getUpVector(), speed*inputY, false));
    rigidbody->forces.push_back(new Force(getRightVector(), speed*inputZ, false));


    


    
    float targetPitch = clamp(rigidbody->velocity.z * tiltSpeedFactor, -maxTiltAngle, maxTiltAngle);
    float targetRoll = clamp(rigidbody->velocity.x * tiltSpeedFactor, -maxTiltAngle, maxTiltAngle);
    
    
    transform.rotation = ofVec3f(-targetPitch, 0,  targetRoll);
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
    float mouseX = previousMousePosition.x - args.x;
    float mouseY = args.y - previousMousePosition.y;

    previousMousePosition = ofVec2f(args.x, args.y);

    cameraYaw += mouseX * cameraSensitivityX;
    cameraPitch = std::clamp(cameraPitch + mouseY * cameraSensitivityY, 0.0f, 70.0f);
}

void Player::draw()
{
    GameObject::draw();
    /*Box box = ufoCollider->getBounds();
    
    ofNoFill();
    Vector3 min = box.parameters[0];
    Vector3 max = box.parameters[1];
    Vector3 size = max - min;
    Vector3 center = size / 2 + min;
    ofVec3f p = ofVec3f(center.x(), center.y(), center.z());
    float w = size.x();
    float h = size.y();
    float d = size.z();
    ofDrawBox(p, w, h, d);*/
}