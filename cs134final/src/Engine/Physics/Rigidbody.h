#pragma once
#include <unordered_set>
#include <vector>

#include "Component.h"
#include "Forces.h"

class Rigidbody : public Component
{
public:

    void update() override;
    
    ofVec3f calculateForces();
    ofVec3f calculateRotationalForces();
    void integrate();
    virtual void onCollisionTriggered(GameObject* argGameObject);
    virtual bool canCollideWith(GameObject* argGameObject);

    std::unordered_set<GameObject*> collidedObjects;
    std::vector<Force*> forces;

    float radius;
    
    float mass = 10;
    ofVec3f velocity = ofVec3f(0, 0, 0);
    ofVec3f acceleration = ofVec3f(0, 0, 0);
    float damping = .99;
    
    ofVec3f headingDirection = ofVec3f(0, -1, 0);

    float maxSpeed = 1000;

    bool collisionsEnabled = true;
};
