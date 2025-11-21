#include "Entity.h"

#include "ofAppRunner.h"

void Entity::onUpdate(ofEventArgs & args)
{
    collidedEntities.clear();

    integrate();
}

ofVec3f Entity::calculateForces()
{
    ofVec3f result = ofVec3f(0, 0, 0);
    auto force = forces.begin();

    while (force != forces.end())
    {

        if (!(*force)->rotation)
        {
            result += (*force)->getForce();
        
            // Erase if force is NOT indefinite on the system
            if ((*force)->indefinite == false)
            {
                force = forces.erase(force);
            }
        }
        
    }

    return result;
}

ofVec3f Entity::calculateRotationalForces()
{
    ofVec3f result = ofVec3f(0, 0, 0);
    auto force = forces.begin();

    while (force != forces.end())
    {

        if ((*force)->rotation)
        {
            result += (*force)->getForce();
        
            // Erase if force is NOT indefinite on the system
            if ((*force)->indefinite == false)
            {
                force = forces.erase(force);
            }
        }
        
    }

    return result;
}


void Entity::integrate()
{
    float frameRate = ofGetFrameRate();
    if (frameRate < 1.0f)
    {
        // Return if greater than 0 to prevent division by 0
        return;
    }
    float dt = 1.0f / frameRate;
    
    transform.position += (velocity * dt);
    ofVec3f accel = acceleration;
    accel += calculateForces() * (1.0 / mass);
    velocity += accel * dt;
    velocity *= damping;

    if (velocity.length() > maxSpeed) velocity = velocity.normalize() * maxSpeed;
}

void Entity::onCollisionTriggered(Entity* entity)
{
    
}

bool Entity::canCollideWith(Entity* entity)
{
    return collisionsEnabled && collidedEntities.find(entity) == collidedEntities.end();
}