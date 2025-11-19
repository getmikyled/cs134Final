#pragma once

#include <unordered_set>

#include "Forces.h"
#include "..\Engine\Core\GameObject.h"

class Entity: public GameObject
{
public:

    void update() override;
    ofVec3f calculateForces();
    void integrate();
    virtual void onCollisionTriggered(Entity* entity);
    virtual bool canCollideWith(Entity* entity);

    std::unordered_set<Entity*> collidedEntities;
    std::vector<Force*> forces;

    float radius;
    
    float mass = 10;
    ofVec3f velocity = ofVec3f(0, 0, 0);
    ofVec3f acceleration = ofVec3f(0, 0, 0);
    float damping = 1;
    
    ofVec3f headingDirection = ofVec3f(0, -1, 0);
    bool edgeWrap = false;

    bool physicsEnabled = true;
};
